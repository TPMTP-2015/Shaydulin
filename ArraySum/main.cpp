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
using std::cout;

#define RS_ARRAY_SIZE 720000000


int main(int argc, const char * argv[]) {
    TestsRunner::runPOSIXThreadsTests(RS_ARRAY_SIZE, 1);
    TestsRunner::runPOSIXThreadsTests(RS_ARRAY_SIZE, 2);
    TestsRunner::runPOSIXThreadsTests(RS_ARRAY_SIZE, 4);
    return 0;
}
