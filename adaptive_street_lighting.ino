// Adaptive Street Light using LDR and PWM LED

int ldrPin = A0;     // LDR connected to A0
int ledPin = 9;      // LED connected to PWM pin D9

int ldrValue = 0;    // Variable to store LDR value
int brightness = 0;  // LED brightness value

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Adaptive Street Light Started");
}

void loop() {
  // Read LDR value
  ldrValue = analogRead(ldrPin);

  // Convert LDR value to LED brightness (inverse relation)
  brightness = map(ldrValue, 0, 1023, 255, 0);
  brightness = constrain(brightness, 0, 255);

  // Control LED brightness
  analogWrite(ledPin, brightness);

  // Display values on Serial Monitor
  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" | LED Brightness: ");
  Serial.println(brightness);

  delay(500);
}
