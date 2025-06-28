#include <iostream>
#include "array.hpp"

using namespace OliverCarleton;
// sumupArray tests class array's copy constructor and destructor.
// Precondition: Array class object 'a' has data
// Postcondition: Print the sum of a[] on screen
void sumupArray(array a);

int main(int argc, const char * argv[]) {
    array arrayA;
    arrayA.resize(10);
    for (int i = 0 ; i < arrayA.size() ; i++){
        arrayA[i] = i + 1;
    }
    sumupArray(arrayA);
    array arrayB = arrayA;
    sumupArray(arrayB);

    array arrayC(5,1);
    sumupArray(arrayC);
    return 0;
}

void sumupArray(array a){
    int sum = 0;
    for (int i = 0 ; i < a.size() ; i++){
        sum += a[i];
        a[i] = 0;
    }
    std::cout << "Sum=" << sum << std::endl;
}
