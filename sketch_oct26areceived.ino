const int greenLED = 7;
const int redLED = 8;

int expectedPacket = 1;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.setTimeout(200);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);

  Serial.println("==================================");
  Serial.println("    SERIAL RECEIVER STARTED");
  Serial.println("==================================");
  Serial.println("Waiting for packets...");
}

void loop() {
  if (Serial1.available()) {
    String message = Serial1.readStringUntil('\n');
    message.trim();

    if (message.startsWith("PACKET:")) {
      int receivedPacket = message.substring(7).toInt();

      if (receivedPacket == expectedPacket) {
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);

        Serial.print("SUCCESS: Packet received = ");
        Serial.println(receivedPacket);
      } else {
        digitalWrite(greenLED, LOW);
        digitalWrite(redLED, HIGH);

        Serial.println("FAULT DETECTED!");
        Serial.print("Expected packet: ");
        Serial.println(expectedPacket);
        Serial.print("Received packet: ");
        Serial.println(receivedPacket);
      }

      expectedPacket = receivedPacket + 1;
    }
  }
}