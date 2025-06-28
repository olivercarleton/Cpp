#pragma once
#include <cstddef>

namespace OliverCarleton {

    class array {
    public:
        /// @brief Default constructor sets the size zero.
        array();

        /// @brief Constructor sets size and allocates integer array of size.
        /// @param size The size of array.
        array(size_t size);

        /// @brief Constructor sets size and allocates integer array of size.
        /// Initialize all elements with initialValue.
        /// @param size The size of array.
        /// @param initialValue The initial value.
        array(size_t size, int initialValue);

        /// @brief Copy constructor
        /// @param obj An object of class array.
        array(const array &obj);

        /// @brief Destructor delete array data
        ~array();

        /// @brief Change the size of array to newSize and copy elements to new array.
        void resize(size_t newSize);

        /// @brief Overloaded operator [] to access an element with index n.
        /// @param n Index
        /// @return The reference of the element pointed by index.
        int& operator[](size_t n);

        /// @brief get the size of array.
        /// @return The size of array.
        size_t size() const;

    private:
        int *elements; ///< pointer to a memory block
        size_t sizeOfArray;  ///< size of the array
    };

} // namespace OliverCarleton

