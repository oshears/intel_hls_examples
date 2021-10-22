//  Copyright (c) 2021 Intel Corporation                                  
//  SPDX-License-Identifier: MIT                                          

#include "HLS/hls.h"
#include <stdio.h>

using namespace ihc;

component float multiply_accumulate_float(float a, float b, float c) {
  return a * b + c;
}

int main() {
//   constexpr int SIZE = 100;
//   unsigned int result[SIZE];
//   for(unsigned int i=0; i<SIZE; ++i) {
    // ihc_hls_enqueue(&result[i], &count);
//   }

//   ihc_hls_component_run_all(count);

  bool pass = true;
//   for(unsigned int i=0; i < SIZE; ++i) {
//     if (result[i] != i) {
//       printf("ERROR: Expected %u, found %u\n", i, result[i]);
//       pass = false;
//     }
//   }

    float result = 0;
    float a = 1;
    float b = 2;
    float c = 3;

    ihc_hls_enqueue(&result, &multiply_accumulate_float, a, b, c);
    ihc_hls_component_run_all(multiply_accumulate_float);


    if(result != (a * b + c)) pass = false;

  if (pass) {
    printf("PASSED\n");
  }
  else {
    printf("FAILED\n");
  }

  return 0;

}
