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

#define RS_ARRAY_SIZE 40

int main(int argc, const char * argv[]) {
    int* hugeArray = ArrayHandler::generateArray(RS_ARRAY_SIZE);
    pthread_t threads[4];
//    for (int  i = 0; i < 4; i++) {
    ArrayWrapper* arg = new ArrayWrapper;
    for(int i = 0; i < 4; i++){
        arg->array = &hugeArray[i*RS_ARRAY_SIZE/4];
        arg->size = i*RS_ARRAY_SIZE/4;
        pthread_create(&threads[i], NULL, &ArrayHandler::sumArray, arg);
    }
    long long sum = 0;
    void* tmp;
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], &tmp);
        sum += *(long long*) tmp;
        cout << sum <<"\n";
    }
    cout << "The sum is " << sum << "\n";
//    pthread_create(&thread, NULL, &ArrayHandler::sumArray, arg);
    return 0;
}
