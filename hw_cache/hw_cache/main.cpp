//
//  main.cpp
//  hw_cache
//
//  Created by Руслан on 13.12.15.
//  Copyright © 2015 MIPT. All rights reserved.
//
// Resuls for different NUMBER_OF_FRAGMENTS:
// 2   4,57
// 3   4,53
// 4   4,56
// 5   8
// 6   7,92
// 7   8,4
// 8   8,01
// 9   19,5
// 10  19,5
// 11  19,8
// 12  19,7
// 13  19,7
// 14  19,7
// 15  20
// 16  20



#include <iostream>
#include <chrono>
#include <ctime>
using namespace std::chrono;
using std::cout;

//all numbers are in int -> actual size in bytes is equal to ARRAY_SIZE*4

#define ARRAY_SIZE 536870912    //2Gb
#define OFFSET 16777216 //16Mb
#define NUMBER_OF_FRAGMENTS 16

int main(int argc, const char * argv[]) {
    time_point<high_resolution_clock> start, end;

    int* memory = (int*) malloc(ARRAY_SIZE*sizeof(int));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        memory[i] = -1;
    }
    
    for (int frag_num = 0; frag_num < (NUMBER_OF_FRAGMENTS - 1); frag_num++) {
        for (int num_in_fragment = 0; num_in_fragment < OFFSET/2; num_in_fragment ++) {
            memory[frag_num * OFFSET + num_in_fragment] = (frag_num + 1) * OFFSET + num_in_fragment;
        }
    }
    
    for (int num_in_fragment = 0; num_in_fragment < OFFSET/2; num_in_fragment ++) {
        memory[(NUMBER_OF_FRAGMENTS-1) * OFFSET + num_in_fragment] = num_in_fragment;
    }
    
    int iterat = 0;
    start = high_resolution_clock::now();
    for (long i = 0; i < 1000000000; i++) {
        iterat = memory[iterat];
        if (iterat == -1) {
            cout << "Something is broken on iteration #"<< i << "\n";
            return -1;
        }
    }
    cout << "Final address: " << iterat << "\n";
    end = high_resolution_clock::now();
    duration<double> elapsed_seconds = end - start;
    cout << "Time: " << elapsed_seconds.count() << "s\n";
    return 0;
}
