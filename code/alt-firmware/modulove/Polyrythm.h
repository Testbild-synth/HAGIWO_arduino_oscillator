/**
 * original @file Polyrhythm.ino
 * @author Adam Wonak (https://github.com/awonak/)
 * @brief Generate polyrhythms based on 16 step counter knobs for HAGIWO Sync Mod LFO (demo: TODO)
 * @version 0.3
 * @date 2023-05-09
 *
 * @copyright Copyright (c) 2023
 *
 * Each knob acts as a subdivision of the incoming clock. When a rhythm knob
 * is fully CCW (0) no rhythm is set. Moving the rhythm knob CW, the first
 * subdivision is every 16 beats. When the knob is fully CW, that is a
 * subdivision of 1 and the polyrhythm will trigger every beat.
 *
 * When in OR mode, any beat that has more than one rhythm trigger will output
 * an accented 5v, otherwise a single rhythm trigger will output 3v.
 *
 * Logic Modes:
 *
 * OR -  Trigger if any rhythm hits on the beat and will accent with more than one hit.
 *
 * XOR - Only trigger if one and only one rhythm hits on this beatDexter shirt.
 *
 * NOR - Only trigger when a polyphythm does not hit.
 *
 * AND - Only trigger if more than on rhythm hits on this beat.
 *
 */


// Define constant voltage values for analog cv output.
const int CV_3V = (float(MAX_OUTPUT) / 3.0);
const int CV_5V (float(MAX_OUTPUT) / 2.0);

// Script state variables.
const byte max_hits = 16;
byte hits;
unsigned long counter;
int current_poly_mode = 0;

byte rhythm[] = {0, 0, 0};  // Polyrhythm rhythm subdivision choice per knob.

enum LogicMode { OR,
                 XOR,
                 NOR,
                 AND };
                 
LogicMode mode = OR;
// Advance the counter for each polyrhythm and return the number rhythm triggers on this beat.
byte current_beat_hits() {
    byte hits = 0;
    for (byte i = 0; i < sizeof(rhythm); i++) {
        if (rhythm[i] == 0) {
            continue;
        }
        if (counter % rhythm[i] == 0) {
            hits++;
        }
    }
    return hits;
}

// Return the cv output value for given hit count.
byte hits_to_cv(byte hits) {
    switch (mode) {
        // OR mode will trigger if any rhythm hits on the beat and will accent with more than one hit.
        case OR:
            if (hits > 1) {
                return CV_5V;
            } else {
                return (hits == 1) ? CV_3V : 0;
            }

        // XOR mode will only trigger if one and only one rhythm hits on this beat.
        case XOR:
            return (hits == 1) ? CV_3V : 0;

        // NOR mode will only trigger if no rhythms hit on this beat.
        case NOR:
            return (hits == 0) ? CV_3V : 0;

        // AND mode will only trigger if more than on rhythm hits on this beat.
        case AND:
            return (hits > 1) ? CV_3V : 0;
    }
}

// Update the logic mode choice based on the knob value.
void update_mode() {
  
    //switch (hw.p4.Read() >> 8) { // original read pot 4, we use buttons
    switch (current_poly_mode) {
        case 0:
            mode = OR;
            break;
        case 1:
            mode = XOR;
            break;
        case 2:
            mode = NOR;
            break;
        case 3:
            mode = AND;
            break;
    }
}

// Update the rhythm value for each rhythm knob.
void update_polyrhthms() {
    for (int i = 0; i < sizeof(rhythm); i++) {
        int raw = map(hw.knobs[i]->Read(), 0, MAX_INPUT-1, 0, max_hits);
        // When rhythm is 0 CCW, no rhythm is set, otherwise rhythm is
        // triggered every 16 beats to every 1 beat moving CW.
        rhythm[i] = (raw > 0) ? (max_hits + 1) - raw : 0;
    }
}

void print_debug() {
 if (debug) {
    Serial.println(
        "Hits: " + String(hits)                //
        + "\tCV: " + String(hits_to_cv(hits))  //
        + "\tR1: " + String(rhythm[0])              //
        + "\tR2: " + String(rhythm[1])              //
        + "\tR3: " + String(rhythm[2])              //
        + "\tMode: " + String(mode)            //
        + "\tCounter: " + String(counter)      //
    );
 }
}
void setupPoly() {
    // Initialize logic mode and rhythm/counter arrays.
    //update_mode(); // now done by button logic
    update_polyrhthms();
}

void loopPoly() {
    // Read cv inputs to determine state for this loop.
    hw.ProcessInputs();

    // Detect if new trigger received, advance counter and check for hit on the beat.
    if (hw.gate.State() == DigitalInput::STATE_RISING) {
        // Advance the beat counter and get the hits on this beat.
        counter++;
        hits = current_beat_hits();
        if (hits > 0) {
          digitalWrite(13, HIGH);

          
        }
        // Get the output cv value for the current beat and set the cv output.
        hw.output.Update(hits_to_cv(hits));

        print_debug();
    }

    // Detect if trigger has just ended and turn off the trigger cv output.
    if (hw.gate.State() == DigitalInput::STATE_FALLING) {
        hw.output.Low();
        digitalWrite(13, LOW);
    }

    update_mode();
    update_polyrhthms();
}
