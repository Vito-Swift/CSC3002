/*
 * File: intarray.cpp
 * ----------------
 * This file implements the intarray class
 */

#include "intarray.h"
#include "error.h"
using namespace std;

/*
 * Implementation notes: constructor and destructor
 * -----------------------------------------------
 * The constructor allocates the array storage for the array elements and
 * initializes the fields of the object.  The destructor frees any heap
 * memory allocated by the class, which is just the array of elements
 */

IntArray::IntArray() {
    capacity = INITIAL_CAPACITY;
    array = new int[capacity];
    count = 0;
}

IntArray::IntArray(unsigned int n) {
    capacity = n;
    array = new int[capacity];
    count = n;
}

IntArray::~IntArray() {
    delete[] array;
}

/*
 * Implementation notes: size, isEmpty, clear
 * ------------------------------------------
 * These methods are each a single line and need no detailed documentation.
 */

int IntArray::size() {
    return int(count);
}


bool IntArray::isEmpty() {
    return count == 0;
}


void IntArray::clear() {
    count = 0;
}

/*
 * Implementation notes: set
 * -------------------------
 * This function first checks to see whether the index is valid and then
 * assign the value to the element.
 */

void IntArray::set(int index, int val) {
    if (static_cast<unsigned long>(index) >= count) error("set: Attempting to set an element out of bound");
    array[index] = val;
}

/*
 * Implementation notes: get
 * -------------------------
 * This function first checks to see whether the index is valid and then
 * return the value of the element.
 */

int IntArray::get(int index) {
    if (static_cast<unsigned long>(index) >= count) error("get: Attempting to get an element out of bound");
    return array[index];
}

/*
 * Implementation notes: push
 * -------------------------
 * This function first checks to see whether there is enough room for
 * the character and then expands the array storage if necessary.
 */

void IntArray::push(const int i) {
    if (count == capacity) expandCapacity();
    array[count++] = i;
}

/*
 * Implementation notes: pop, peek
 * ------------------------------
 * These functions check for an empty stack and report an error if
 * there is no top element.
 */

int IntArray::pop() {
    if (isEmpty()) error("pop: Attempting to pop an empty stack");
    return array[--count];
}


int IntArray::peek() {
    if (isEmpty()) error("peek: Attempting to peek at an empty stack");
    return array[--count];
}

/*
 * Implementation notes: expandCapacity
 * ------------------------------------
 * This method doubles the capacity of the elements array whenever it runs
 * out of space.  To do so, the method must copy the pointer to the old
 * array, allocate a new array with twice the capacity, copy the integers
 * from the old array to the new one, and finally free the old storage.
 */

void IntArray::expandCapacity() {
    int* oldArray = array;
    capacity *= 2;
    array = new int[capacity];
    for (unsigned int i = 0; i < count; i++)
        array[i] = oldArray[i];
    delete[] oldArray;
}
