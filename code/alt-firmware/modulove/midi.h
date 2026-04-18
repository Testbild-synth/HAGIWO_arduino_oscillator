// midier scale/mode generation

const midier::Degree scaleDegrees[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

const midier::Note roots[] = {
  midier::Note::C, midier::Note::D,  midier::Note::E, midier::Note::F, midier::Note::G, midier::Note::A, midier::Note::B
};

/*
  Converts a note frequency to the closest corresponding MIDI
  note number.
  Adapted from https://gist.github.com/francoisgeorgy/d155f4aa5e8bd767504c2b43e1ba2902
*/
// freq to midi
static const uint32_t midi_note_at_zero_volts = 0;
static const float semitones_per_octave = 12.0f;
static const float volts_per_semitone = 1.0f / semitones_per_octave;
static const float a4_frequency = 440.0f;
static const uint32_t a4_midi_note = 69;


uint32_t frequency_to_midi_note(float frequency) {
  float note = 69.0f + logf(frequency / a4_frequency) / logf(2.0f) * semitones_per_octave;
  return ceil(note);
}

float midi_note_to_frequency(uint32_t midi_note) {
  float semitones_away_from_a4 = (float)(midi_note) - (float)(a4_midi_note);
  return powf(2.0f, semitones_away_from_a4 / semitones_per_octave) * a4_frequency;
}

/*
  Converts a MIDI note number to Volts/octave.
  
  Since the note number represents the number of semitones, there is a
  simple linear relationship between note number and Volts/octave. The
  note number is multiplied by the number of Volts per semitone
  (1/12th of a Volt, or about 83.3 mV) to obtain the corresponding
  voltage.
*/

float midi_note_to_volts(uint32_t midi_note) {
  if( midi_note <= midi_note_at_zero_volts ) {
    midi_note = 0;
  } else {
    midi_note -= midi_note_at_zero_volts;
  }
  return midi_note * volts_per_semitone;
}

midier::Mode mmode;
int scaleRoot = 0; // start at c, yawn.

int modeIndex = 1;
int currentMode[8];
int octave = 3;

void makeScale(midier::Note root, midier::Mode mode) {

  // the root note of the scale
  const midier::Note scaleRoot = root;

  // we are playing ionian mode which is the major scale
  // if you are not familiar with modes, just know that "ionian" is the major scale and "aeolian" is the minor scale
  //const midier::Mode mode = midier::Mode::Ionian;

  for (midier::Degree scaleDegree : scaleDegrees)
  {
    // find out the interval to be added to the root note for this chord degree and chord quality
    const midier::Interval interval = midier::scale::interval(mode, scaleDegree);

    // calculate the note of this chord degree
    const midier::Note note = scaleRoot + interval;
    currentMode[ scaleDegree - 1 ] = midier::midi::number(note, octave);

  }
}

  /* cycle through the modes using the circle of fifths */

void cycleMode() {

  modeIndex = modeIndex + 5;
  modeIndex = modeIndex % 7;

  switch (modeIndex) {
    case 1:
      mmode = midier::Mode::Ionian;
      break;
    case 2:
      mmode = midier::Mode::Dorian;
      break;
    case 3:
      mmode = midier::Mode::Phrygian;
      break;
    case 4:
      mmode = midier::Mode::Lydian;
      break;
    case 5:
      mmode = midier::Mode::Mixolydian;
      break;
    case 6:
      mmode = midier::Mode::Aeolian;
      break;
    case 7:
      mmode = midier::Mode::Locrian;
      break;
  }

   makeScale( roots[scaleRoot], mmode);

}
