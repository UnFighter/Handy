#include <Mouse.h>

#define UP_BUTTON A0
#define DOWN_BUTTON A1
#define LEFT_BUTTON A2
#define RIGHT_BUTTON A3

void setup() {
  pinMode(UP_BUTTON, INPUT_PULLUP);
  pinMode(DOWN_BUTTON, INPUT_PULLUP);
  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);

  Mouse.begin();
}

void loop() {
  if (digitalRead(UP_BUTTON) == LOW) {
    Mouse.move(0, -1); 
    delay(100); 
  }

  if (digitalRead(DOWN_BUTTON) == LOW) {
    Mouse.move(0, 1); 
    delay(100); 
  }

  if (digitalRead(LEFT_BUTTON) == LOW) {
    Mouse.move(-1, 0); 
    delay(100); 
  }

  if (digitalRead(RIGHT_BUTTON) == LOW) {
    Mouse.move(1, 0); 
    delay(100); 
  }
}
