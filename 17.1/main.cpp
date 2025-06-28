//HW17 Oliver Carleton April 18, 2024
//“I affirm that I do not give or receive any unauthorized help on this homework and that all work is my own”
#include <iostream>
#include "array.h"
#include "WallClockTime.hpp"

using namespace OliverCarleton;

template<typename T>
void sumupArray(array<T>& a);

int main(int argc, const char * argv[]) {
    array<int> arrayA;
    arrayA.resize(10);
    for (int i = 0 ; i < arrayA.size() ; i++){
        arrayA[i] = i + 1;
    }
    sumupArray(arrayA);

    array<int> arrayB = arrayA;
    sumupArray(arrayB);

    array<double> arrayC(10, 0.1);
    arrayC.resize(5);
    sumupArray(arrayC);

    array<WallClockTime> times(3);
    times[0] = WallClockTime(20);
    times[1] = times[0];
    times[2] = times[1];
    sumupArray(times);

    return 0;
}

template<typename T>
void sumupArray(array<T>& a){
    T sum = T();
    for (size_t i = 0 ; i < a.size() ; i++){
        sum += a[i];
    }
    std::cout << "Sum=" << sum << std::endl;
}
