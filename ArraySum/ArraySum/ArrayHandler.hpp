//
//  ArrayHandler.hpp
//  ArraySum
//
//  Created by Руслан on 23.09.15.
//  Copyright © 2015 MIPT. All rights reserved.
//

#ifndef ArrayHandler_hpp
#define ArrayHandler_hpp

#include <stdio.h>

struct ArrayWrapper {
    int* array;
    long size;
};

class ArrayHandler {
    
public:
    static int* generateRandomArray(long size);
    static int* generateArray(long size);
    static void printArray(int* array, long size);
    static void* sumArray(void* args);
};

#endif /* ArrayHandler_hpp */
