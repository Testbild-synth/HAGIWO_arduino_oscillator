// The max burst gate count.
const int MAX_BURST_COUNT = 16;

// The duration of each burst spark in milliseconds.
const int MIN_BURST_RATE = 10;
const int MAX_BURST_RATE = 512;

// Script state.
int brst_counter = 0;
int individual_cv = 0;
int brst_output = 0;
float individual_progress = 0;
float full_progress = 0;
unsigned long burst_start = 0;
unsigned long last_burst = 0;
int burst_rate;
int burst_count;
int target_cv;
int current_trigger_shape = 0;

enum SequenceShape {
  SEQUENCE_FADE_IN,
  SEQUENCE_FLAT,
  SEQUENCE_FADE_OUT,
  SEQUENCE_TRIANGLE,
  SEQUENCE_RANDOM,
};
SequenceShape sequence_shape = SEQUENCE_FLAT;

enum TrigShape {
  TRIG_FADE_IN,
  TRIG_FLAT,
  TRIG_FADE_OUT,
};
TrigShape trig_shape = TRIG_FLAT;

SequenceShape readSequenceShape(int val) {
  if (val <= 204) {
    return SEQUENCE_FADE_IN;
  } else if (val <= 410) {
    return SEQUENCE_FLAT;
  } else if (val <= 616) {
    return SEQUENCE_FADE_OUT;
  } else if (val <= 820) {
    return SEQUENCE_TRIANGLE;
  } else {
    return SEQUENCE_RANDOM;
  }
}

TrigShape readTrigShape() {
  switch (current_trigger_shape) {
    case 0:
      return TRIG_FADE_IN;
    case 1:
      return TRIG_FLAT;
    case 2:
      return TRIG_FADE_OUT;

  }
}

bool beginBurst() {
  // Read all inputs.
  bool trigger_start = hw.trig.State() == DigitalInput::STATE_RISING;

  return trigger_start;
}


void loopBrstGen() {
  // Read cv inputs to determine state for this loop.
  hw.ProcessInputs();

  // Detect if a new trigger has been received. If so, read inputs for burst
  // settings.
  if (beginBurst()) {
    // Initialize burst state variables.
    burst_start = millis();
    brst_counter = 0;

    // Read the current knob parameters.
    burst_rate = map(hw.p1.Read(), 0, MAX_INPUT, MIN_BURST_RATE, MAX_BURST_RATE);
    burst_count = map(hw.p2.Read(), 0, MAX_INPUT, 1, MAX_BURST_COUNT);
    sequence_shape = readSequenceShape(hw.p3.Read());
    trig_shape = readTrigShape();
  }

  // Update burst cv if withing a bursting state.
  if (millis() < burst_start + ((2 * burst_rate) * burst_count)) {
    // Increment brst_counter for current phase of duty cycle.
    if (millis() > burst_start + (brst_counter * burst_rate)) {
      brst_counter++;
      if (brst_counter % 2) {
        last_burst = millis();
        // Calculate the progress percentage from current time to
        // burst_duration.
        full_progress = float(millis() - burst_start) /
                        float(((2 * burst_rate) * burst_count));
        // Max output or random step.
        target_cv = (sequence_shape == SEQUENCE_RANDOM) ? random(MAX_INPUT) : MAX_INPUT;
      }
    }

    // Calculate progress of current burst slope.
    if (millis() < (last_burst + (2 * burst_rate))) {
      individual_progress =
        float(millis() - last_burst) / float(2 * burst_rate);
    }
    switch (trig_shape) {
      case TRIG_FLAT:
        individual_cv = (brst_counter % 2) ? target_cv : 0;
        break;
      case TRIG_FADE_IN:
        individual_cv = individual_progress * float(target_cv);
        break;
      case TRIG_FADE_OUT:
        individual_cv = (float(target_cv) - (individual_progress * float(target_cv)));
        break;
    }

    // Calculate overall burst progress.
    switch (sequence_shape) {
      case SEQUENCE_FLAT:
      case SEQUENCE_RANDOM:
        brst_output = individual_cv;
        break;
      case SEQUENCE_FADE_IN:
        brst_output = full_progress * individual_cv;
        break;
      case SEQUENCE_FADE_OUT:
        brst_output = (individual_cv - (full_progress * individual_cv));
        break;
      case SEQUENCE_TRIANGLE:
        brst_output = (brst_counter <= burst_count)
                      ? (full_progress * individual_cv)
                      : (individual_cv - (full_progress * individual_cv));
    }

    hw.output.Update10bit(brst_output);
  } else {
    hw.output.Update(0);
  }
}
