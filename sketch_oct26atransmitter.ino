int packetID = 1;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

  Serial.println("==================================");
  Serial.println("   SERIAL TRANSMITTER STARTED");
  Serial.println("==================================");
}

void loop() {
  Serial1.print("PACKET:");
  Serial1.println(packetID);

  Serial.print("Transmitted Packet: ");
  Serial.println(packetID);

  packetID++;

  delay(1000);
}