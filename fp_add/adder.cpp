//  Copyright (c) 2021 Intel Corporation                                  
//  SPDX-License-Identifier: MIT                                          

#include "HLS/hls.h"
#include "HLS/math.h"
#include "HLS/hls_float.h"
#include "HLS/hls_float_math.h"

#include <stdio.h>

#include "adder.h"

using namespace ihc;



component FPhalf adder(FPhalf a, FPhalf b) {
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

    FPhalf result = FPhalf(0);
    FPhalf a = 1;
    FPhalf b = 2;

    for(int i = 0; i < 3; i++)
      results[i] = a;

  

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
