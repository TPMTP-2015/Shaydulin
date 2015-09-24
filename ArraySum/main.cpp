//
//  main.cpp
//  ArraySum
//
//  Created by Руслан on 23.09.15.
//  Copyright © 2015 MIPT. All rights reserved.
//

#include <iostream>
#include "ArrayHandler.hpp"
#include "TestsRunner.hpp"
#include <libiomp/omp.h>
using std::cout;

#define RS_ARRAY_SIZE 720000000


int main(int argc, const char * argv[]) {
//    TestsRunner::runPOSIXThreadsTests(RS_ARRAY_SIZE, 1);
//    TestsRunner::runPOSIXThreadsTests(RS_ARRAY_SIZE, 2);
//    TestsRunner::runPOSIXThreadsTests(RS_ARRAY_SIZE, 4);
#pragma omp parallel
    printf("Hello from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
    return 0;
}
