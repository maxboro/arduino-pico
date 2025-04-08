void setup() {
  Serial1.begin(115200);
  Serial1.println("Hello, Raspberry Pi Pico!");
}

void loop() {
  Serial1.println("I am running in the loop");
  delay(1000);
}
