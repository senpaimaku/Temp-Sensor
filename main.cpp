#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

#define DP1 11
#define DP2 12

DHT dht(9, DHT22);

int num = 0;

int pins[] = { 2, 3, 4, 5, 6, 7, 8 };
int numbers[10][7] = {
//  A  B  C  D  E  F  G
  { 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 0, 1, 1, 0, 1 },
  { 1, 1, 1, 1, 0, 0, 1 },
  { 0, 1, 1, 0, 0, 1, 1 },
  { 1, 0, 1, 1, 0, 1, 1 },
  { 1, 0, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1 },
}; 

void setup() {
  dht.begin();

  for (int i = 0; i <= 6; i++) {
    pinMode(pins[i], OUTPUT);
  }

  pinMode(DP1, OUTPUT);
  pinMode(DP2, OUTPUT);
  
}

void displayNum(int g, int b) {
  digitalWrite(DP1, 0);
  digitalWrite(DP2, 1);
  delay(10);

  for (int i = 0; i <= 6; i++) {
    digitalWrite(pins[i], numbers[g][i]);
  }
    
  digitalWrite(DP1, 1);
  digitalWrite(DP2, 0);
  delay(10);

  for (int i = 0; i <= 6; i++) {
    digitalWrite(pins[i], numbers[b][i]);
  }
    
}

void loop() {

  float a = dht.readTemperature();
  int b = a; 
  
  int tens = b / 10;
  int ones = b % 10;


  displayNum(tens, ones);
}
