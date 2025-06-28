#include "array.hpp"
#include <algorithm> 
#include <cstring>

namespace OliverCarleton {

    //default constructor
    array::array() : elements(nullptr), sizeOfArray(0) {}

    //constructor with size
    array::array(size_t size) : sizeOfArray(size), elements(new int[size]) {
        std::memset(elements, 0, size * sizeof(int));
    }

    //constructor with size and initial value
    array::array(size_t size, int initialValue) : sizeOfArray(size), elements(new int[size]) {
        std::fill_n(elements, size, initialValue);
    }

    //copy constructor
    array::array(const array &obj) : sizeOfArray(obj.sizeOfArray), elements(new int[obj.sizeOfArray]) {
        std::copy(obj.elements, obj.elements + obj.sizeOfArray, elements);
    }

    //destructor
    array::~array() {
        delete[] elements;
    }

    //resize the array
    void array::resize(size_t newSize) {
        int* newElements = new int[newSize];
        if (newSize > sizeOfArray) {
            std::copy(elements, elements + sizeOfArray, newElements);
            std::fill(newElements + sizeOfArray, newElements + newSize, 0);
        } else {
            std::copy(elements, elements + newSize, newElements);
        }
        delete[] elements;
        elements = newElements;
        sizeOfArray = newSize;
    }

    //overloaded operator []
    int& array::operator[](size_t n) {
        return elements[n];
    }

    //return the size of the array
    size_t array::size() const {
        return sizeOfArray;
    }

} // namespace OliverCarleton

