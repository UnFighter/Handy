#include <Keyboard.h>


const int buttonPins[] = {A0, A1, A2, A3, A4};

const int numButtons = 5;

// Массив для хранения состояний кнопок
int buttonStates[numButtons] = {HIGH};

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
        checkCombination();
      }
    }
  }
}

void checkCombination() {
  int pressedCount = 0;
  for (int i = 0; i < numButtons; i++) {
    if (buttonStates[i] == LOW) {
      pressedCount++;
    }
  }

  switch (pressedCount) {
    case 1:
      if (buttonStates[0] == LOW) Keyboard.write('O');
      if (buttonStates[1] == LOW) Keyboard.write('E');
      if (buttonStates[2] == LOW) Keyboard.write('A');
      if (buttonStates[3] == LOW) Keyboard.write('И');
      if (buttonStates[4] == LOW) Keyboard.write('У');
      break;
    case 2:
      if (buttonStates[0] == LOW && buttonStates[1] == LOW) Keyboard.write('Р');
      if (buttonStates[0] == LOW && buttonStates[2] == LOW) Keyboard.write('В');
      if (buttonStates[0] == LOW && buttonStates[3] == LOW) Keyboard.write('Л');
      if (buttonStates[0] == LOW && buttonStates[4] == LOW) Keyboard.write('К');
      if (buttonStates[1] == LOW && buttonStates[2] == LOW) Keyboard.write('М');
      if (buttonStates[1] == LOW && buttonStates[3] == LOW) Keyboard.write('Д');
      // Добавляем соседние комбинации
      if (buttonStates[2] == LOW && buttonStates[3] == LOW) Keyboard.write('Я');
      if (buttonStates[2] == LOW && buttonStates[4] == LOW) Keyboard.write('Ы');
      if (buttonStates[3] == LOW && buttonStates[4] == LOW) Keyboard.write('Ю');
      break;
    case 3:
      if (buttonStates[0] == LOW && buttonStates[1] == LOW && buttonStates[2] == LOW) Keyboard.write('П');
      if (buttonStates[0] == LOW && buttonStates[1] == LOW && buttonStates[3] == LOW) Keyboard.write('Г');
      if (buttonStates[0] == LOW && buttonStates[1] == LOW && buttonStates[4] == LOW) Keyboard.write('З');
      if (buttonStates[0] == LOW && buttonStates[2] == LOW && buttonStates[3] == LOW) Keyboard.write('Б');
      if (buttonStates[0] == LOW && buttonStates[2] == LOW && buttonStates[4] == LOW) Keyboard.write('Ч');
      if (buttonStates[0] == LOW && buttonStates[3] == LOW && buttonStates[4] == LOW) Keyboard.write('Х');
      if (buttonStates[1] == LOW && buttonStates[2] == LOW && buttonStates[3] == LOW) Keyboard.write('Ж');
      if (buttonStates[1] == LOW && buttonStates[2] == LOW && buttonStates[4] == LOW) Keyboard.write('Ш');
      if (buttonStates[1] == LOW && buttonStates[3] == LOW && buttonStates[4] == LOW) Keyboard.write('Щ');
      // Добавляем соседние комбинации
      if (buttonStates[2] == LOW && buttonStates[3] == LOW && buttonStates[4] == LOW) Keyboard.write('Н');
      if (buttonStates[0] == LOW && buttonStates[2] == LOW && buttonStates[4] == LOW) Keyboard.write('Т');
      if (buttonStates[0] == LOW && buttonStates[1] == LOW && buttonStates[4] == LOW) Keyboard.write('С');
      break;
    case 4:
      if (buttonStates[0] == LOW && buttonStates[1] == LOW && buttonStates[2] == LOW && buttonStates[3] == LOW) Keyboard.write(KEY_BACKSPACE);
      if (buttonStates[0] == LOW && buttonStates[1] == LOW && buttonStates[2] == LOW && buttonStates[4] == LOW) Keyboard.write('Ц');
      if (buttonStates[0] == LOW && buttonStates[1] == LOW && buttonStates[3] == LOW && buttonStates[4] == LOW) Keyboard.write('Ь');
      if (buttonStates[0] == LOW && buttonStates[2] == LOW && buttonStates[3] == LOW && buttonStates[4] == LOW) Keyboard.write('Ф');
      if (buttonStates[1] == LOW && buttonStates[2] == LOW && buttonStates[3] == LOW && buttonStates[4] == LOW) Keyboard.write('Ъ');
      // Добавляем соседние комбинации
      if (buttonStates[0] == LOW && buttonStates[1] == LOW && buttonStates[3] == LOW && buttonStates[4] == LOW) Keyboard.write(KEY_TAB);
      if (buttonStates[0] == LOW && buttonStates[1] == LOW && buttonStates[2] == LOW && buttonStates[3] == LOW) Keyboard.write(' ');
      break;
    case 5:
      if (allButtonsPressed()) Keyboard.write(KEY_RETURN);
      break;
  }
}
