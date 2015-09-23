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
#include <time.h>
using std::cout;

#define RS_ARRAY_SIZE 480000000


int main(int argc, const char * argv[]) {
    int* hugeArray = ArrayHandler::generateRandomArray(RS_ARRAY_SIZE);
    clock_t startTime, endTime;
    pthread_t threads[4];
    for (int threadNum = 1; threadNum <=4; threadNum++) {
        startTime = clock();
        for(int i = 0; i < threadNum; i++){
            ArrayWrapper* arg = new ArrayWrapper;
            arg->array = &hugeArray[i*RS_ARRAY_SIZE/threadNum];
            arg->size = RS_ARRAY_SIZE/threadNum;
            pthread_create(&threads[i], NULL, &ArrayHandler::sumArray, arg);
        }
        long long sum = 0;
        void* tmp;
        for (int i = 0; i < threadNum; i++) {
            pthread_join(threads[i], &tmp);
            sum += *(long long*) tmp;
        }
        endTime = clock();
        cout << "The sum is " << sum << " Time for " << threadNum << " threads is " << (endTime - startTime) <<"\n";
    }
    return 0;
}
