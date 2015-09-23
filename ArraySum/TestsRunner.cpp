//
//  TestsRunner.cpp
//  ArraySum
//
//  Created by Руслан on 23.09.15.
//  Copyright © 2015 MIPT. All rights reserved.
//

#include "TestsRunner.hpp"
#include "ArrayHandler.hpp"
#include <time.h>
#include <pthread.h>
#include <iostream>
using std::cout;

void TestsRunner::runPOSIXThreadsTests(long arraySize, int threadNum){
    int* hugeArray = ArrayHandler::generateArray(arraySize);
    clock_t startTime, endTime;
    pthread_t threads[4];
    startTime = clock();
    for(int i = 0; i < threadNum; i++){
        ArrayWrapper* arg = new ArrayWrapper;
        arg->array = &hugeArray[i*arraySize/threadNum];
        arg->size = arraySize/threadNum;
        pthread_create(&threads[i], NULL, &ArrayHandler::sumArray, arg);
    }
    long long sum = 0;
    void* tmp;
    for (int i = 0; i < threadNum; i++) {
        pthread_join(threads[i], &tmp);
        sum += *(long long*) tmp;
    }
    endTime = clock();
    cout << "The sum is " << sum << " Time for " << threadNum << " threads is " << (endTime - startTime)/CLOCKS_PER_SEC <<"\n";
    free(hugeArray);
}