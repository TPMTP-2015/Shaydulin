//
//  main.cpp
//  ArraySum
//
//  Created by Руслан on 23.09.15.
//  Copyright © 2015 MIPT. All rights reserved.
//

#include <iostream>
#include "ArrayHandler.hpp"
#include <pthread.h>
using std::cout;

#define RS_ARRAY_SIZE 100000000
#define RS_THREAD_NUMBER 4

int main(int argc, const char * argv[]) {
    int* hugeArray = ArrayHandler::generateRandomArray(RS_ARRAY_SIZE);
    pthread_t threads[4];
//    for (int  i = 0; i < 4; i++) {
    for(int i = 0; i < RS_THREAD_NUMBER; i++){
        ArrayWrapper* arg = new ArrayWrapper;
        arg->array = &hugeArray[i*RS_ARRAY_SIZE/RS_THREAD_NUMBER];
        arg->size = RS_ARRAY_SIZE/RS_THREAD_NUMBER;
        pthread_create(&threads[i], NULL, &ArrayHandler::sumArray, arg);
    }
    long long sum = 0;
    void* tmp;
    for (int i = 0; i < RS_THREAD_NUMBER; i++) {
        pthread_join(threads[i], &tmp);
        sum += *(long long*) tmp;
    }
    cout << "The sum is " << sum << "\n";
    return 0;
}
