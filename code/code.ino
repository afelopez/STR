
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 7, 6, 5, 2);

int long count = 0;
int long rpm = 0;
int long long lastT = 0;
int visualT = 0;
void setup() {
  attachInterrupt(digitalPinToInterrupt(3), cont, FALLING); 
  lcd.begin(16, 2);
  lcd.print("RPM: ");  
}

void loop() {
  lcd.setCursor(0, 1);
  rpm = ((float)count / millis()  );
  if((millis() - visualT) > 1000){  
    lcd.print(rpm);
    visualT = millis();
  }
  if((millis() - lastT) > 10000){
    count = 0;
  }
}
void cont(){
  count++;
  lastT = millis();
}

