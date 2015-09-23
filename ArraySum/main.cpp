//
//  main.cpp
//  ArraySum
//
//  Created by Руслан on 23.09.15.
//  Copyright © 2015 MIPT. All rights reserved.
//

#include <iostream>
#include "ArrayHandler.hpp"
using std::cout;

int main(int argc, const char * argv[]) {
    // insert code here...
    int* hugeArray = ArrayHandler::generateArray(100000);
    cout << ArrayHandler::sumArray(hugeArray, 50000) + ArrayHandler::sumArray(&hugeArray[50000], 50000);
    return 0;
}
