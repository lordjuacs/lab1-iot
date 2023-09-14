const int pinA0 = A0;    // Pin de entrada analógica para la señal sinuoidal
const int bits = 4;      // 4 bits para limitar la señal
const int maxValue = pow(2, bits) - 1;

void setup() {
  // Inicializa la comunicación serie para imprimir valores
  Serial.begin(9600);
}

void loop() {
  // Obtiene el tiempo transcurrido en milisegundos
  unsigned long tiempo = millis();

  // Lee el valor analógico de A0 (0-1023, 10 bits)
  int sensorValue = analogRead(pinA0);

  // Escala el valor a 4 bits (0-15)
  int scaledValue = map(sensorValue, 0, 1023, 0, maxValue);

  // Imprime el tiempo, valor A0 y valor en 4 bits en formato CSV
  Serial.print(tiempo);
  Serial.print(",");
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.println(scaledValue);

  // Espera un breve período de tiempo para visualizar los cambios
  delay(100);
}
