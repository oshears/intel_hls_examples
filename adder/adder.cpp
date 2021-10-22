//  Copyright (c) 2021 Intel Corporation                                  
//  SPDX-License-Identifier: MIT                                          

#include "HLS/hls.h"
#include <stdio.h>

using namespace ihc;

component unsigned int adder(unsigned int a, unsigned int b) {
  return a + b;
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

    unsigned int result = 0;
    unsigned int a = 1;
    unsigned int b = 2;

    ihc_hls_enqueue(&result, &adder, a, b);
    ihc_hls_component_run_all(adder);


    if(result != 3) pass = false;

  if (pass) {
    printf("PASSED\n");
  }
  else {
    printf("FAILED\n");
  }

  return 0;

}
