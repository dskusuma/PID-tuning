// Global Variables


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}

float hitung_TD(float a, float zeta, float omega) {
  float Td;
  Td = a / zeta * omega;
  return Td;
}
