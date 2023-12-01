#ifndef _ADAFRUIT_FIVE_BIT_HD_GAMMA_H_
#define _ADAFRUIT_FIVE_BIT_HD_GAMMA_H_

#include "Arduino.h"

// Applies gamma correction for the RGBV(8, 8, 8, 5) color space, where
// the last byte is the brightness byte at 5 bits.
// To override this five_bit_hd_gamma_bitshift function just define
// your own version anywhere in your project.
// Example:
//  void five_bit_hd_gamma_bitshift(
//      uint8_t r8, uint8_t g8, uint8_t b8,
//      uint8_t* out_r8,
//      uint8_t* out_g8,
//      uint8_t* out_b8,
//      uint8_t* out_power_5bit) {
//        cout << "hello world\n";
//  }
void five_bit_hd_gamma_bitshift(uint8_t r8, uint8_t g8, uint8_t b8,
                                uint8_t *out_r8, uint8_t *out_g8,
                                uint8_t *out_b8, uint8_t *out_power_5bit)
    __attribute__((weak));

// Simple gamma correction function that converts from
// 8-bit color component and converts it to gamma corrected 16-bit
// color component. Fast and no memory overhead!
// To override this function just define your own version
// anywhere in your project.
// Example:
//  void five_bit_hd_gamma_function(
//    uint8_t r8, uint8_t g8, uint8_t b8,
//    uint16_t* r16, uint16_t* g16, uint16_t* b16) {
//      cout << "hello world\n";
//  }
void five_bit_hd_gamma_function(uint8_t r8, uint8_t g8, uint8_t b8,
                                uint16_t *r16, uint16_t *g16, uint16_t *b16)
    __attribute__((weak));

#endif // _ADAFRUIT_FIVE_BIT_HD_GAMMA_H_
