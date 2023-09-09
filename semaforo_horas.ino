#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; 
byte colPins[COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int redCar = 21;
int yellowCar = 20;
int greenCar = 19;
int redPedestrian = 15;
int greenPedestrian = 14;

int timeStrong = 4000;
int timeWeak = 2000;
int timeLate = 1000;
String time;

void setup() {
  pinMode(redCar, OUTPUT);
  pinMode(yellowCar, OUTPUT);
  pinMode(greenCar, OUTPUT);
  pinMode(redPedestrian, OUTPUT);
  pinMode(greenPedestrian, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
  Serial.println("Ingrese una hora en formato 24 horas: (y una quinta tecla cualquiera)");
}

void loop() {
  //Lectura del input
  while (time.length() != 5) {
    char key = keypad.getKey();
    if (key) {
      time += key;
      Serial.print(key);
    }
  }

  int hours = (time[0] - '0') * 10 + (time[1] - '0');
  int minutes = (time[3] - '0') * 10 + (time[4] - '0');

  if ((hours >= 23 && minutes >= 0) || (hours <= 6 && minutes >= 0)) {
     for (int i = 0; i < 5; i++) {
      digitalWrite(yellowCar, HIGH);
      digitalWrite(greenPedestrian, HIGH);
      digitalWrite(redPedestrian, HIGH);
      delay(timeLate);
      digitalWrite(yellowCar, LOW);
      digitalWrite(greenPedestrian, LOW);
      digitalWrite(redPedestrian, LOW);
      delay(timeLate);
    }

  } else {
     for (int i = 0; i < 2; i++) {
    digitalWrite(redCar, LOW);
    digitalWrite(greenCar, HIGH);
    digitalWrite(redPedestrian, HIGH);
    digitalWrite(greenPedestrian, LOW);
    delay(timeStrong);

    digitalWrite(yellowCar, HIGH);
    digitalWrite(greenCar, LOW);
    delay(timeWeak);
    digitalWrite(yellowCar, LOW);

    digitalWrite(redCar, HIGH);
    digitalWrite(greenCar, LOW);
    digitalWrite(redPedestrian, LOW);
    digitalWrite(greenPedestrian, HIGH);
    delay(timeStrong);
     }
  }

  Serial.println("Ingrese una hora en formato 24 horas (y una quinta tecla cualquiera):");
  time = "";
  digitalWrite(redCar, LOW);
  digitalWrite(yellowCar, LOW);
  digitalWrite(greenCar, LOW);
  digitalWrite(redPedestrian, LOW);
  digitalWrite(greenPedestrian, LOW);
}
