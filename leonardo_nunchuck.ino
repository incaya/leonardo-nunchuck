#include <Wire.h>
#include <Keyboard.h>
#include "nunchuck_funcs.h"

// - / + 3.3v / d : D2 / c : D3

int key = -1;
int oldkey = -1;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  nunchuck_init();
  delay(5000);
  digitalWrite(13, HIGH);
}

void loop() {
  // get nunchuck data (i2c)
  nunchuck_get_data();
  int xVal = nunchuck_joyx();
  int yVal = nunchuck_joyy();
  int cButton = nunchuck_cbutton();
  int zButton = nunchuck_zbutton();

  key = getActionId(xVal, yVal, cButton, zButton);
  if (key != oldkey) {
    switch (key) {
      case 1:
        Keyboard.press('s'); // droite
        Serial.println('s');
        break;
      case 2:
        Keyboard.press('q'); // gauche
        Serial.println('q');
        break;
      case 3:
        Keyboard.press('a'); // haut
        Serial.println('a');
        break;
      case 4:
        Keyboard.press('w'); // bas
        Serial.println('w');
        break;
      case 5:
        Keyboard.press('d'); // A / top button
        break;
      case 6:
        Keyboard.press('f'); // B / bottom button
        break;
      default:
        Keyboard.releaseAll();
        break;
    }
  }
  oldkey = key;
  delay(50);
}

// Get action id
int getActionId(unsigned int xVal, unsigned int yVal, unsigned int cButton, unsigned int zButton) {
  if (xVal == 2) { // droite
    return 1;
  } else if (xVal == 43) { // gauche
    return 2;
  } else if (yVal == 1) { // haut
    return 3;
  } else if (yVal == 44) { // bas
    return 4;
  } else if (cButton == 1 && zButton == 0) { // top button
    return 5;
  } else if (cButton == 1 && zButton == 1) { // bottom button
    return 6;
  } else {
    return -1;
  }
}
