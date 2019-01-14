// import library
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
  // manggil fungsi.
  // di void setup ada: pin1, gnd, 5v, pin16, pin 17, gnd2
  //  Serial.println(exp(1));
  

}

// ================================
//  1.FUNGSI DARI DRAFT SEBELUMNYA
// ================================

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

// Ts (Waktu atur / setting time)
float hitung_Ts(float persen, float zeta, float omega_n) {
  float Ts;  
  int var_ts;

  if (persen == 0.5) {
    // persen = 0.5%
    var_ts = 5;
  } else if (persen == 2.0) {
    // persen = 2%
    var_ts = 4;
  } else {
    // persen = 5%
    var_ts = 3;
  }

  Ts = var_ts / (zeta * omega_n);
}

// ================================
// --------------------------------


// ================================
//   FUNGSI DARI DRAFT SEBELUMNYA
// ================================
