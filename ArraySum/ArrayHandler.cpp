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
        result[i] = i;
    }
    return result;
}

void ArrayHandler::printArray(int* array, int size){
    std::cout<< "Array size is " << size << "\n";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

void* ArrayHandler::sumArray(void* args){
    ArrayWrapper wrapper = *(ArrayWrapper*) args;
    int* array = wrapper.array;
    int size = wrapper.size;
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
        printf("In thread: %lld\n", sum);
    }
    long long* result = new long long;
    *result = sum;
    return result;
}

