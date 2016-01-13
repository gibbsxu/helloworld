//
//  move.cpp
//  HelloC
//
//  Created by hatlonely on 15/12/23.
//  Copyright © 2015年 hatlonely. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <vector>

namespace c11_move {

class MemoryBlock {
public:
    // Simple constructor that initializes the resource.
    explicit MemoryBlock(size_t length) : _length(length), _data(new int[length]) {
        std::cout << "In MemoryBlock(size_t). length = " << _length << "." << std::endl;
    }
    
    // Destructor.
    ~MemoryBlock() {
        std::cout << "In ~MemoryBlock(). length = " << _length << ".";
        
        if (_data != NULL) {
            std::cout << " Deleting resource.";
            // Delete the resource.
            delete[] _data;
        }
        
        std::cout << std::endl;
    }
    
    // Copy constructor.
    MemoryBlock(const MemoryBlock& other) : _length(other._length), _data(new int[other._length]) {
        std::cout << "In MemoryBlock(const MemoryBlock&). length = "
        << other._length << ". Copying resource." << std::endl;
        
        std::copy(other._data, other._data + _length, _data);
    }
    
    // Copy assignment operator.
    MemoryBlock& operator=(const MemoryBlock& other) {
        std::cout << "In operator=(const MemoryBlock&). length = "
        << other._length << ". Copying resource." << std::endl;
        
        if (this != &other)
        {
            // Free the existing resource.
            delete[] _data;
            
            _length = other._length;
            _data = new int[_length];
            std::copy(other._data, other._data + _length, _data);
        }
        return *this;
    }
    
    // Move constructor.
    MemoryBlock(MemoryBlock&& other) : _length(0), _data(NULL) {
        std::cout << "In MemoryBlock(MemoryBlock&&). length = "
        << other._length << ". Moving resource." << std::endl;
        
        // Copy the data pointer and its length from the
        // source object.
        _data = other._data;
        _length = other._length;
        
        // Release the data pointer from the source object so that
        // the destructor does not free the memory multiple times.
        other._data = NULL;
        other._length = 0;
    }
    
    // Move assignment operator.
    MemoryBlock& operator=(MemoryBlock&& other) {
        std::cout << "In operator=(MemoryBlock&&). length = "
        << other._length << "." << std::endl;
        
        if (this != &other)
        {
            // Free the existing resource.
            delete[] _data;
            
            // Copy the data pointer and its length from the
            // source object.
            _data = other._data;
            _length = other._length;
            
            // Release the data pointer from the source object so that
            // the destructor does not free the memory multiple times.
            other._data = NULL;
            other._length = 0;
        }
        return *this;
    }
    
    // Retrieves the length of the data resource.
    size_t Length() const {
        return _length;
    }
    
private:
    size_t _length; // The length of the resource.
    int* _data;     // The resource.
};

int main(int argc, const char *argv[]) {
    // Create a vector object and add a few elements to it.
    std::vector<MemoryBlock> v;
    v.reserve(3);
    v.push_back(MemoryBlock(25));
    std::cout << "======================" << std::endl;
    v.push_back(MemoryBlock(75));
    std::cout << "======================" << std::endl;
    
    // Insert a new element into the second position of the vector.
    v.insert(v.begin() + 1, MemoryBlock(50));
    std::cout << "======================" << std::endl;

    return 0;
}

// In MemoryBlock(size_t). length = 25.
// In MemoryBlock(MemoryBlock&&). length = 25. Moving resource.
// In ~MemoryBlock(). length = 0.
// ======================
// In MemoryBlock(size_t). length = 75.
// In MemoryBlock(MemoryBlock&&). length = 75. Moving resource.
// In MemoryBlock(const MemoryBlock&). length = 25. Copying resource.
// In ~MemoryBlock(). length = 25. Deleting resource.
// In ~MemoryBlock(). length = 0.
// ======================
// In MemoryBlock(size_t). length = 50.
// In MemoryBlock(MemoryBlock&&). length = 50. Moving resource.
// In MemoryBlock(const MemoryBlock&). length = 25. Copying resource.
// In MemoryBlock(const MemoryBlock&). length = 75. Copying resource.
// In ~MemoryBlock(). length = 75. Deleting resource.
// In ~MemoryBlock(). length = 25. Deleting resource.
// In ~MemoryBlock(). length = 0.
// ======================
// In ~MemoryBlock(). length = 75. Deleting resource.
// In ~MemoryBlock(). length = 50. Deleting resource.
// In ~MemoryBlock(). length = 25. Deleting resource.
    
}
