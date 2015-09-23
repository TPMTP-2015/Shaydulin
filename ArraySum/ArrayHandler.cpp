//
//  ArrayHandler.cpp
//  ArraySum
//
//  Created by Руслан on 23.09.15.
//  Copyright © 2015 MIPT. All rights reserved.
//

#include "ArrayHandler.hpp"
#include <stdlib.h>
#include <iostream>

int* ArrayHandler::generateRandomArray(int size){
    int* result = new int[size];
    for (int i = 0; i < size; i++) {
        result[i] = rand() % 1000;
    }
    return result;
}

int* ArrayHandler::generateArray(int size){
    int* result = new int[size];
    for (int i = 0; i < size; i++) {
        result[i] = 1;
    }
    return result;
}

void ArrayHandler::printArray(int* array, int size){
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

long long ArrayHandler::sumArray(int* array, int size){
    long long result = 0;
    for (int i = 0; i < size; i++) {
        result += array[i];
    }
    return result;
}

