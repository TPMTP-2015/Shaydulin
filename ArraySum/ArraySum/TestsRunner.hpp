//
//  TestsRunner.hpp
//  ArraySum
//
//  Created by Руслан on 23.09.15.
//  Copyright © 2015 MIPT. All rights reserved.
//

#ifndef TestsRunner_hpp
#define TestsRunner_hpp

#include <stdio.h>

class TestsRunner {
public:
    static void runPOSIXThreadsTests(long arraySize, int threadNum);
};

#endif /* TestsRunner_hpp */
