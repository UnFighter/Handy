const int FSR_PIN_1 = A1; 
const int FSR_PIN_2 = A0;
const float VCC = 4.98; // Измеренное напряжение 5V линии Arduino
const float R_DIV = 9720.0; // Измеренное значение резистора

unsigned long previousMillis = 0; // Хранит время последнего измерения
const long interval = 10; // Интервал между измерениями в миллисекундах

void setup() {
  Serial.begin(9600);
  pinMode(FSR_PIN_1, INPUT);
  pinMode(FSR_PIN_2, INPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) { // Проверяем, не пора ли сделать новое измерение
    previousMillis = currentMillis; // Сохраняем текущее время как время последнего измерения

    int fsrADC_1 = analogRead(FSR_PIN_1);
    int fsrADC_2 = analogRead(FSR_PIN_2);
    
    float force_1 = calculateForce(fsrADC_1);
    float force_2 = calculateForce(fsrADC_2);

    if (force_1 > 0.1) { // Выводим значение силы для первого датчика, если оно значительно
      Serial.print("Force 1: ");
      Serial.print(force_1);
      Serial.println(" g");
    }

    if (force_2 > 0.1) { // Выводим значение силы для второго датчика, если оно значительно
      Serial.print("Force 2: ");
      Serial.print(force_2);
      Serial.println(" g");
    }
  }

  // Остальная часть вашего кода, которая должна выполняться непрерывно, помещается сюда.
}

float calculateForce(int fsrADC) {
  if (fsrADC == 0) {
    return 0; // Если значение нулевое, вернуть ноль
  }
  
  float fsrV = fsrADC * VCC / 1023.0; // Вычисление напряжения на FSR
  float fsrR = R_DIV * (VCC / fsrV - 1.0); // Вычисление сопротивления FSR
  float fsrG = 1.0 / fsrR; // Проводимость - обратное значение сопротивления

  float force;
  if (fsrR <= 600) { // Апроксимация
    force = (fsrG - 0.00075) / 0.00000032639;
  } else {
    force = fsrG / 0.000000642857;
  }

  return force;
}
