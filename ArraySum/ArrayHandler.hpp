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

class ArrayHandler {
    
public:
    static int* generateRandomArray(int size);
    static int* generateArray(int size);
    static void printArray(int* array, int size);
    static long long sumArray(int* array, void* size);
};

#endif /* ArrayHandler_hpp */
