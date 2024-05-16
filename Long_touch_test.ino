#include <Keyboard.h>


const int buttonPins[] = {A0, A1, A2, A3, A4};

const int numButtons = 5;

// Массив для хранения состояний кнопок
int buttonStates[numButtons] = {HIGH};
// Массив для хранения времени удержания кнопок
unsigned long buttonPressTimes[numButtons] = {0};

void setup() {

  Keyboard.begin();
  
  // Настройка пинов кнопок как входов
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() {
  // Считывание состояний кнопок
  for (int i = 0; i < numButtons; i++) {
    int state = digitalRead(buttonPins[i]);
    if (state != buttonStates[i]) {
      buttonStates[i] = state;
      // Если кнопка нажата
      if (state == LOW) {
        // Запоминаем время нажатия кнопки
        buttonPressTimes[i] = millis();
      } else {
        // Если кнопка была отпущена после удержания
        if (millis() - buttonPressTimes[i] >= 2000) {
          checkCombination(i);
        }
      }
    }
  }
}

void checkCombination(int index) {
  switch (index) {
    case 0:
      Keyboard.write('1');
      break;
    case 1:
      Keyboard.write('2');
      delay(100); // Дополнительная задержка для отличия долгого нажатия
      if (digitalRead(buttonPins[1]) == LOW) {
        Keyboard.write('Ё');
      } else {
        Keyboard.write('E');
      }
      break;
    case 2:
      Keyboard.write('3');
      break;
    case 3:
      Keyboard.write('4');
      break;
    case 4:
      Keyboard.write('5');
      break;
  }
}

