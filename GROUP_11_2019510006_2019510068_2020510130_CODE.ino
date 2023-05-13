#include <LiquidCrystal_I2C.h>
int INCREMENT_VALUE = 7;
int WAIT_TIME = 1000;
int counter = 0;
LiquidCrystal_I2C lcd_1(0x3f, 16, 2);
// Define pin for the buzzer
const int buzzerPin = 12;


void setup() {
  // initialize LED pins as outputs
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  lcd_1.begin(16, 2);
  // Set the buzzer pin as output
  pinMode(buzzerPin, OUTPUT);
  
   

  
  // initialize serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  lcd_1.init();
  lcd_1.backlight();

  // check if counter value is between 1 and 31
  if (counter < 0 || counter > 31) {
    counter %= 32;
    digitalWrite(buzzerPin, HIGH);
    tone(buzzerPin, 1000, 200); // generate the buzzer sound
    
  }
      digitalWrite(buzzerPin, LOW);

  // convert counter value to binary and turn on corresponding LEDs
  digitalWrite(2, counter & 0b00001);
  digitalWrite(3, counter & 0b00010);
  digitalWrite(4, counter & 0b00100);
  digitalWrite(5, counter & 0b01000);
  digitalWrite(6, counter & 0b10000);
 

  
  // print counter value to serial monitor
  Serial.println(counter);
   lcd_1.setCursor(8, 0);
  lcd_1.print(counter);
  // lcd_1.setBacklight(1);
  
    // increment counter by INCREMENT_VALUE
  counter += INCREMENT_VALUE;
  
 

  // wait for WAIT_TIME before repeating loop
  delay(WAIT_TIME);
  lcd_1.clear();
}
