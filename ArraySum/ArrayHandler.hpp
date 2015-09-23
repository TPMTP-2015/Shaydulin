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
    int size;
};

class ArrayHandler {
    
public:
    static int* generateRandomArray(int size);
    static int* generateArray(int size);
    static void printArray(int* array, int size);
    static void* sumArray(void* args);
};

#endif /* ArrayHandler_hpp */
