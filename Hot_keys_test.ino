#include <Keyboard.h>


const int buttonPin1 = А0;
const int buttonPin2 = А1;

void setup() {
  // Настройка пинов кнопок как входов
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  
  Keyboard.begin();
}

void loop() {
  if (digitalRead(buttonPin1) == LOW) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('c');
    delay(100);
    Keyboard.releaseAll();
    delay(1000); 
  }
  
  // Проверка состояния второй кнопки
  if (digitalRead(buttonPin2) == LOW) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('v');
    delay(100);
    Keyboard.releaseAll();
    delay(1000);
  }
}
