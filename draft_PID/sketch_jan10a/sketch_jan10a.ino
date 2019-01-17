// import library
#include <stdlib.h>
#include <math.h>
#include <string.h>

//#include fungsi.h
//-> header (fungsi.h)
//-> badan fungsi (fungsi.c)

//GLOBAL VARIBLES

// Variable
const float pi = 3.14;
const double Kd = 0;
float Ts, zeta, Wn, overshoot, Kp, Ki;
void setup() {
  // TODO Gean: 
  // yang dibutuhk{an: pin1, gnd, 5v, pin16, pin17, gnd2
  //  Manual input
  overshoot = 12.8;
  Ts = 0.0216;
  
  Serial.begin(115200);
}

void loop() {

  
//  if(Serial.available() > 0) {
    zeta = hitungZeta(overshoot);
    Wn = hitungWn(Ts, zeta);
    Kp = hitungKp(zeta, Wn);
    Ki = hitungKi(Wn);

    Serial.print("Wn: ");
    Serial.print(Wn, DEC);

    Serial.print("| zeta: ");
    Serial.print(zeta, DEC);
    Serial.println("");
    
    Serial.print("Kp: ");
    Serial.print(Kp, DEC);

    Serial.print("| Ki: ");
    Serial.print(Ki, DEC);

    Serial.print("| Kd: ");
    Serial.print(Kd, DEC);

    Serial.println("");

    Serial.print("===================");
    Serial.println("");
//  }
}


// ================================
//  1.FUNGSI DARI DRAFT SEBELUMNYA
// ================================

// Tp (Waktu puncak / peak time)
float hitung_Tp(float zeta, float omega_n) {
  float Tp;
  Tp = 1 / (omega_n * sqrt(1 - pow(zeta,2)));

  return Tp;
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
//  2.FUNGSI BARU
// ================================

// Cari Zeta
float hitungZeta(float overshoot) {
    float zeta;
    zeta = sqrt(1 / (pi + log(overshoot/100) ) );
    return zeta;
}

// Cari Wn
float hitungWn(float Ts, float zeta) {
  float Wn;
  Wn = 3 / (zeta * Ts);
  return Wn;
}

// Cari Kp
float hitungKp(float zeta, float Wn) {
  float Kp;
  Kp = (2 * zeta * Wn - 3.894) / 712.6;
  return Kp;
}

float hitungKi(float Wn) {
  float Ki;
  Ki = (pow(Wn,2) / 712.6);
  return Ki;
}
