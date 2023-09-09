int redCar = 21;
int yellowCar = 20;
int greenCar = 19;
int redPedestrian = 15;
int greenPedestrian = 14;

int timeStrong = 4000;
int timeWeak = 2000;

void setup() {
  pinMode(redCar, OUTPUT);
  pinMode(yellowCar, OUTPUT);
  pinMode(greenCar, OUTPUT);
  pinMode(redPedestrian, OUTPUT);
  pinMode(greenPedestrian, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
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
