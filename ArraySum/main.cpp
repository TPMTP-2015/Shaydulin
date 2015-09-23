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

int main(int argc, const char * argv[]) {
    // insert code here...
    int* hugeArray = ArrayHandler::generateArray(100000);
    pthread_t threads[4];
    for (int  i = 0; i < 4; i++) {
        int* arg = new int;
        *arg = i*1000;
        pthread_create(threads->i, NULL, &ArrayHandler::sumArray, (void*)arg);
    }
    
    return 0;
}
