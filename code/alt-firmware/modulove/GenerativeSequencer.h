// State variables.
int probability, steps, amplitude;

int output;
int step;
int refrain_counter;
int rand_val;
int midi_note;

int refrain = 2;
int refrain_max = 8;
int pattern_size_max = 16;
int cv_max = MAX_INPUT;
//int cv_max = MAX_OUTPUT_10BIT;
int cv_pattern[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int pattern_options[8] = {1, 2, 3, 4, 6, 8, 12, 16};
int current_genseq_refrain = 0;

void setupGenSeq() {

  // Inititialize random values in sequence.
  for (int i = 0; i < pattern_size_max; i++) {
    cv_pattern[i] = random(cv_max);
  }
}
void loopGenSeq() {
  // Read cv inputs to determine state for this loop.
  hw.ProcessInputs();

  bool advance = hw.trig.State() == DigitalInput::STATE_RISING;

  // Check for new clock trigger.
  if (advance) {
    // Increment the current sequence step.
    // Right shift to scale input to a range of 8.
    steps = pattern_options[(hw.p2.Read() >> 7)];
    step = (step + 1) % steps;

    // Check probability and refrain counter to see if the current step
    // should be updated.
    probability = map(hw.p1.Read(), 0, 1023, 0, 255);

    // Increment Refrain at the first step of the sequence.
    if (step == 0) {
      // Right shift to scale input to a range of 4.
      refrain_counter = (refrain_counter + 1) % refrain;
    }

    if (refrain_counter == 0 && step == 0) {
      cycleMode();
    }

    midi_note = currentMode[random(7)];
    //rand_val = (int) midi_note_to_frequency(midi_note);
    rand_val = map(midi_note, 24, 96, 24, 255);

    //rand_val = random(cv_max);
    if (refrain_counter == 0 && probability > rand_val) {
      cv_pattern[step] = rand_val; // random(cv_max);
    }

    // Scale the max cv output range.
    amplitude = hw.p3.Read();
    octave = map(amplitude, 10, 1016, 1, 5);

    // Update PWM CV output value.
    //output = map(cv_pattern[step], 0, cv_max,  0, amplitude);
    output = cv_pattern[step];

    if (debug) {
      Serial.println(
        "Prob: " + String(probability) + " > " + String(cv_pattern[step])
        + "\tMode: " +  modeIndex
        + "\tMidi: " + String(midi_note) + " " + String( midi_note_to_frequency(midi_note) )
        + "\tRefrain: [" + String(refrain_counter) + "/" + String(refrain) + "]"
        + "\tSteps: [" + String(step) + "/" + String(steps) + "]"
        + "\tAmp: " + String(octave));
    }
  } else {
    //hw.output.Update(output);

  }
    hw.output.Update(output);
}

void ppdebug() {
#ifdef DEBUG
  Serial.println(
    "Prob: " + String(probability) + " > " + String(rand_val)                 //
    + "\tValue: " + String(cv_pattern[step])                                  //
    + "\tRefrain: [" + String(refrain_counter) + "/" + String(refrain) + "]"  //
    + "\tSteps: [" + String(step) + "/" + String(steps) + "]"                 //
    + "\tAmp: " + String(amplitude));
#endif
}
