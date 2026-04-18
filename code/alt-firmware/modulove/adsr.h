/**
 * @file ADSR.ino
 * @author Adam Wonak (https://github.com/awonak/)
 * @brief ADSR Envelope Generator firmware for HAGIWO Sync Mod LFO (demo: TODO)
 * @version 0.2
 * @date 2023-05-08
 *
 * @copyright Copyright (c) 2023
 *
 */

const int MAX_DURATION = 5000;  // Max env stage time 5 seconds.

int val = 0;       // Envelope state value
int prev_val = 0;  // Previous envelope stage value
unsigned long stage_start_time;
bool loop_enabled = false;

// DEBUG
unsigned long last_print;
unsigned long period = 200;

int16_t current_release = 100;

enum Stage {
    WAIT,
    ATTACK,
    DECAY,
    SUSTAIN,
    RELEASE
};
Stage stage = WAIT;

void changeStage(Stage new_stage) {
    stage = new_stage;
    stage_start_time = millis();
    prev_val = val;
}

void loopADSR() {
    // Read cv inputs to determine state for this loop.
    hw.ProcessInputs();

    bool gate_rising = hw.gate.State() == DigitalInput::STATE_RISING;
    bool gate_falling = hw.gate.State() == DigitalInput::STATE_FALLING;
    bool gate_high = hw.gate.On();


    // Detect if gate has just opened and begin envelope attack.
    if (gate_rising) {
        changeStage(ATTACK);
        val = 0;
    }

    // Detect if gate has just closed and not already in release stage, and begin the release envelope.
    if (gate_falling && stage != RELEASE) {
        changeStage(RELEASE);
        gate_high = false;
    }

    // Toggle looping mode with button 2.
    // see encoderbutton, right button actions
    /*
    if (hw.b2.Change() == Button::CHANGE_PRESSED) {
        val = 0;
        loop_enabled = !loop_enabled;
        loop_enabled
            ? changeStage(ATTACK)
            : changeStage(WAIT);
    }*/

    unsigned long current_time = millis();
    int sustain = map(hw.p3.Read(), 1, MAX_INPUT, 0, MAX_OUTPUT);

    // Advance the cv value for the current envelope stage according to the related stage knob position.
    switch (stage) {
        case ATTACK: {
            int attack_time = map(hw.p1.Read(), 0, MAX_INPUT, 1, MAX_DURATION);
            int elapsed_time = min(current_time - stage_start_time, attack_time);
            val = map(elapsed_time, 0, attack_time, 0, MAX_OUTPUT);

            if (elapsed_time >= attack_time) {
                loop_enabled
                    ? changeStage(RELEASE)
                    : changeStage(DECAY);
            }
            break;
        }

        case DECAY: {
            int decay_time = map(hw.p2.Read(), 0, MAX_INPUT, 1, MAX_DURATION);
            int elapsed_time = min(current_time - stage_start_time, decay_time);
            val = map(elapsed_time, 0, decay_time, prev_val, sustain);

            if (val <= sustain) {
                loop_enabled
                    ? changeStage(RELEASE)
                    : changeStage(SUSTAIN);
            }
            break;
        }

        case SUSTAIN:
            val = sustain;
            break;

        case RELEASE: {
            int release_time = map(current_release, 0, MAX_INPUT, 1, MAX_DURATION); // was reading pot 4, now on encoder
            int elapsed_time = min(current_time - stage_start_time, release_time);
            val = map(elapsed_time, 0, release_time, prev_val, 0);

            if (val == 0) {
                loop_enabled
                    ? changeStage(ATTACK)
                    : changeStage(WAIT);
            }
            break;
        }
    }

    // Write envelope CV output.
    hw.output.Update(val);

    if (debug) {
          // Only print debug message once per elapsed period duration.
    if (millis() - last_print > period) {
        last_print = millis();
        Serial.println(
            "val:   " + String(val)             // Print all env state vars
            + "\tA: " + String(analogRead(P1))  //
            + "\tD: " + String(analogRead(P2))  //
            + "\tS: " + String(analogRead(P3))  //
            + "\tR: " + String(current_release)  //
            + "\tstage: " + String(stage)       //
        );
    }
    }
}
