// Определение пинов для кнопок
const int buttonPin1 = A0;
const int buttonPin2 = A1;
const int buttonPin3 = A2;
const int buttonPin4 = A3;
const int buttonPin5 = A4;

void setup() {
  // Инициализация последовательного соединения
  Serial.begin(9600);
  
  // Установка пинов как входы с подтягивающими резисторами
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
}

void loop() {
  // Чтение состояния кнопок
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState3 = digitalRead(buttonPin3);
  int buttonState4 = digitalRead(buttonPin4);
  int buttonState5 = digitalRead(buttonPin5);
  
  // Проверка состояния первой кнопки
  if (buttonState1 != LOW) {
    Serial.println("Button 1 is pressed");
  }
  
  // Проверка состояния второй кнопки
  if (buttonState2 != LOW) {
    Serial.println("Button 2 is pressed");
  }

  // Проверка состояния третьей кнопки
  if (buttonState3 != LOW) {
    Serial.println("Button 3 is pressed");
  }

  // Проверка состояния четвертой кнопки
  if (buttonState4 != LOW) {
    Serial.println("Button 4 is pressed");
  }

  // Проверка состояния пятой кнопки
  if (buttonState5 != LOW) {
    Serial.println("Button 5 is pressed");
  }
  
  // Задержка для предотвращения дребезга кнопок
  delay(50);
}
