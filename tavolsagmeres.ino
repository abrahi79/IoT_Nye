
// include the library code:
#include <LiquidCrystal.h>
#include <HCSR04.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
UltraSonicDistanceSensor distanceSensor(4, 3);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hi!");

  Serial.begin(9600); 
  pinMode(13,OUTPUT); // We initialize serial connection so that we could print values from sensor.
}

void loop() {
  delay(300);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  lcd.print(distanceSensor.measureDistanceCm());
  int distance = distanceSensor.measureDistanceCm();
   Serial.println(distance);
  

//condition for recognizing the distance when flashing
if (distance <= 15)
{
 
  digitalWrite(13,HIGH);
  delay(300);
  digitalWrite(13,LOW);
  delay(300);
}
  
}



