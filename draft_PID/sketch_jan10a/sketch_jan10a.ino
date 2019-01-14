// import library
#include <stdlib.h>
#include <math.h>
#include <string.h>

//#include fungsi.h
//-> header (fungsi.h)
//-> badan fungsi (fungsi.c)

//GLOBAL VARIBLES

// Variable
// omega = ...
// zeta = ...
// persen_ts = ... {x | x =  5% || 2%% || 0.5% }
const double omega_n = 5;
const double zeta = 3;


void setup() {
  // TODO Gean: 
  // yang dibutuhk{an: pin1, gnd, 5v, pin16, pin17, gnd2
  
}

void loop() {
  // Analogi:
  //
  // Ketika ada nilai di pin1: 
  //            -> nilai ini masuk ke Tp 
  //            -> masuk ke persamaan Tp
  //            -> kita dapat nilai Tp

  // Masuk ke persaman ts(0.5%) menggunakan nilai omega dan zeta -> dapat nilai Ts
  
  // Masuk ke Mp 
  
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
