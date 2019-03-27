#include "intarray.h"
#include "error.h"

using namespace std;


IntArray::IntArray() {
    capacity = INITIAL_CAPACITY;
    array = new int[capacity];
    count = 0;
}


IntArray::IntArray(unsigned int n) {
    capacity = n;
    array = new int[capacity];
    count = 0;
}


IntArray::IntArray(const IntArray& src) {
    deepCopy(src);
}


IntArray::~IntArray() {
    delete[] array;
}


int IntArray::size() {
    return int(count);
}


bool IntArray::isEmpty() {
    return count == 0;
}


void IntArray::clear() {
    count = 0;
}


void IntArray::set(int index, int val) {
    if (static_cast<unsigned long>(index) >= count) error("set: Attempting to set an element out of bound");
    array[index] = val;
}


int IntArray::get(int index) {
    if (static_cast<unsigned long>(index) >= count) error("get: Attempting to get an element out of bound");
    return array[index];
}

void IntArray::push(const int i) {
    if (count == capacity) expandCapacity();
    array[count++] = i;
}


int IntArray::pop() {
    if (isEmpty()) error("pop: Attempting to pop an empty stack");
    return array[--count];
}


int IntArray::peek() {
    if (isEmpty()) error("peek: Attempting to peek at an empty stack");
    return array[--count];
}


IntArray& IntArray::operator=(const IntArray& src) {
    if (this != &src) {
        delete[] array;
        deepCopy(src);
    }
    return *this;
}


void IntArray::deepCopy(const IntArray &src) {
    array = new int[src.count];
    for (unsigned int i = 0; i < src.count; i++) 
        array[i] = src.array[i];
    count = src.count;
    capacity = src.capacity;
}


void IntArray::expandCapacity() {
    int* oldArray = array;
    capacity *= 2;
    array = new int[capacity];
    for (unsigned int i = 0; i < count; i++)
        array[i] = oldArray[i];
    delete[] oldArray;
}
