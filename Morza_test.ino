#include <Keyboard.h>

#define DOT_BUTTON 2
#define DASH_BUTTON 3

bool dotPressed = false;
bool dashPressed = false;

char* currentLayout[] = layoutLatin;


char* code[] = {
  "*-","-***","*--","--*","-**","*","***-","--**","**","*---",
  "-*-","*-**","--","-*","---","*--*","*-*","***","-","**-",
  "**-*","****","-*-*","---*","----","--*-","-*--","-**-","**-**","**--",
  "*-*-",
  "*----","**---","***--","****-","*****","-****","--***","---**","----*","-----",
  "......","*-*-*-","---***","-*-*-","-*--*-","*----*","*-**-*","-****-","-**-*","**--**","--**--",
  "-***-","********","*--*-*","**-*-",
  ""
};


char* layoutCyrillic[] = {
  "а","б","в","г","д","е","ж","з","и","й",
  "к","л","м","н","о","п","р","с","т","у",
  "ф","х","ц","ч","ш","щ","ы","ь","э","ю",
  "я",
  "1","2","3","4","5","6","7","8","9","0",
  ".",",",":",";","(","\'","\"","-","/","?","!",
  " *DELIMITER* "," *ERR* ","@"," *END* ",
  ""
};


char* layoutLatin[] = {
  "a","b","w","g","d","e","v","z","i","j",
  "k","l","m","n","o","p","r","s","t","u",
  "f","h","c","ö","ch","q","y","x","é","ü",
  "ä",
  "1","2","3","4","5","6","7","8","9","0",
  ".",",",":",";","(","\'","\"","-","/","?","!",
  " *DELIMITER* "," *ERR* ","@"," *END* ",
  ""
};

void setup() {
  pinMode(DOT_BUTTON, INPUT_PULLUP);
  pinMode(DASH_BUTTON, INPUT_PULLUP);
  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {
  // Проверяем нажатие кнопки для точки
  if (digitalRead(DOT_BUTTON) == LOW && !dashPressed) {
    dotPressed = true;
    while (digitalRead(DOT_BUTTON) == LOW); // Ждем отпускания кнопки
    if (dotPressed) {
      sendMorseSymbol(".");
    }
    dotPressed = false;
  }
  
  // Проверяем нажатие кнопки для тире
  if (digitalRead(DASH_BUTTON) == LOW && !dotPressed) {
    dashPressed = true;
    while (digitalRead(DASH_BUTTON) == LOW); // Ждем отпускания кнопки
    if (dashPressed) {
      sendMorseSymbol("-");
    }
    dashPressed = false;
  }
  
  delay(50);
}

void sendMorseSymbol(const char* symbol) {
  for (int i = 0; code[i][0] != '\0'; i++) {
    if (strcmp(symbol, code[i]) == 0) {
      Keyboard.write(currentLayout[i]);
      break;
    }
  }
}
