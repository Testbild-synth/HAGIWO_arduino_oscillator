int prog = 1;
int bank = 1;
int banktotal = 3;

int pb1 = 0;
int pb1total = 3;

int pb2 = 0;
int pb2total = 4;

int pb3 = 0;
int pb3total = 2;

int pb5 = 0;
int pb5total = 3;

int numProg = 73;

int encoder_pos_last = 0;
long encoder_delta = 0;
int enc_offset = 1; // changes direction
int enc_delta; // which direction

/**
   handle encoder button long press event
*/
void onEb1LongPress(EncoderButton& eb) {

  bank = eb.longPressCount();
  if (debug) {
    Serial.print("button1 longPressCount: ");
    Serial.println(eb.longPressCount());
  }
}
/**
   handle encoder turn with  button pressed
   offsets OCR2A
*/
void onEb1PressTurn(EncoderButton& eb) {
  enc_delta = eb.increment();


  if (debug) {
    Serial.print("eb1 press inc by: ");
    Serial.println(enc_delta);
    Serial.print("enc_offset is: ");
    Serial.println(enc_offset);
  }
}

/**
   handle encoder turn with  button pressed
*/
void onEb1Clicked(EncoderButton& eb) {

  // set which bank to select formulas from
  //bank = eb.clickCount();

  if (debug) {
    Serial.print("bank: ");
    Serial.println(eb.clickCount());
  }
  // displayUpdate();
}

/**
    handle left button short release
*/
void onLeftReleased(EncoderButton& left) {
 if (bank == 1) {
   
 }
 if (bank == 2) {
    pb2--;
    constrain(pb2, 0, pb2total);
    current_genseq_refrain = pb2;
  }
  else if (bank == 3) {
    pb3--;
    constrain(pb3, 0, pb3total);
    current_mm_curve = pb3;
  }
  else if (bank ==5) {
    pb5--;
    constrain(pb5, 0, pb5total);
    current_trigger_shape = pb5;
  }
}

/**
    handle right button short release
*/
void onRightReleased(EncoderButton& right) {

if (bank == 1) {
    //constrain(pb2, 0, pb2total);
    //current_genseq_refrain = pb2;
     scaleRoot = random(6);
     cycleMode();
  }
  else if (bank == 3) {
    pb3++;
    constrain(pb3, 0, pb3total);
    current_mm_curve = pb3;
  } else if (bank == 4) { // from adsr
    val = 0;
    loop_enabled = !loop_enabled;
    loop_enabled
    ? changeStage(ATTACK)
    : changeStage(WAIT);
  } else if (bank ==5) {
    pb5++;
    constrain(pb5, 0, pb5total);
    current_trigger_shape = pb5;
  }
}

/**
   A function to handle the 'encoder' event without button
*/
void onEb1Encoder(EncoderButton& eb) {

  //displayUpdate();
  encoder_delta = eb.increment();
  if (bank == 2) {
    current_poly_mode = current_poly_mode + enc_delta;
    constrain (current_poly_mode, 0, 3);
  } else if (bank == 3) {
    current_mm_mode = current_mm_mode + enc_delta;
    constrain(current_mm_mode, 0, 3);
  } else if (bank == 4) {
    current_release = current_release + encoder_delta;
    constrain(current_release, 10,  1000);
  }

  if (debug) {
    Serial.print("eb1 incremented by: ");
    Serial.println(encoder_delta);
  }
}
