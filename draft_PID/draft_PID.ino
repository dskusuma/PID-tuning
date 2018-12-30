// import library
#include <stdlib.h>
#include <math.h>

// Global Variables

// Konstanta untuk Td
const double CONST_a = 0.742;

// Konstanta untuk Tr
const double CONST_z = 1;

const double CONST_pi = 3.14;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}


// FUNGSI

// Td (Waktu tunda / delay)
float hitung_Td(float zeta, float omega_n) {
  float Td;
  Td = CONST_a / (zeta * omega_n);
  return Td;
}

// Tr (Waktu naik / rise time)
float hitung_Tr(float zeta, float omega_n) {
  float Tr;
  Tr = (CONST_z / (omega_n * sqrt(CONST_z - pow(zeta,2)))) * (CONST_pi - atan(sqrt(CONST_z - pow(zeta, 2)) / omega_n));
  return Tr;
}

// Tp (Waktu puncak / peak time)
float hitung_Tp(float zeta, float omega_n) {
  float Tp;
  Tp = CONST_z / (omega_n * sqrt(CONST_z - pow(zeta,2)));
}
