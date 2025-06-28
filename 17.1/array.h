#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <algorithm>

namespace OliverCarleton {

    template<class T>
    class array {
    public:
        /// Default constructor sets the size to zero.
        array() : elements(nullptr), sizeOfArray(0) {}

        /// Constructor sets size and allocates array of type T with size.
        /// @param size The size of array.
        array(size_t size) : sizeOfArray(size), elements(new T[size]) {
            std::fill_n(elements, size, T()); // Using default constructor of T
        }

        /// Constructor sets size and allocates array of type T with size and initial value.
        /// @param size The size of array.
        /// @param initialValue The initial value to fill the array.
        array(size_t size, T initialValue) : sizeOfArray(size), elements(new T[size]) {
            std::fill_n(elements, size, initialValue);
        }

        /// Copy constructor.
        array(const array<T> &obj) : sizeOfArray(obj.sizeOfArray), elements(new T[obj.sizeOfArray]) {
            std::copy(obj.elements, obj.elements + obj.sizeOfArray, elements);
        }

        /// Destructor.
        ~array() {
            delete[] elements;
        }

        /// Resize the array to a new size.
        /// @param newSize The new size of the array.
        void resize(size_t newSize) {
            T* newElements = new T[newSize];
            std::copy(elements, elements + std::min(sizeOfArray, newSize), newElements);
            if (newSize > sizeOfArray) {
                std::fill(newElements + sizeOfArray, newElements + newSize, T());
            }
            delete[] elements;
            elements = newElements;
            sizeOfArray = newSize;
        }

        /// Overloaded operator [] to access elements in the array.
        /// @param n The index of the element to access.
        /// @return Returns a reference to the element.
        T& operator[](size_t n) {
            return elements[n];
        }

        /// Overloaded operator [] to access elements in the array (const version).
        /// @param n The index of the element to access.
        /// @return Returns a const reference to the element.
        const T& operator[](size_t n) const {
            return elements[n];
        }

        /// Returns the size of the array.
        /// @return The size of the array.
        size_t size() const {
            return sizeOfArray;
        }

    private:
        T* elements; // Pointer to the array of type T
        size_t sizeOfArray; // Current size of the array
    };

} // namespace OliverCarleton

#endif // ARRAY_H

