/*
 * File: intarray.h
 * ----------------
 * This interface defines the IntArray class, which implements
 * the array abstraction for integers.
 */

#ifndef INTARRAY_H
#define INTARRAY_H

/*
 * Class: IntArray
 * ---------------
 * This class models a array of integers.  Fundamental operations
 * are provided.
 */

class IntArray {  

public:

/*
 * Constructor: IntArray
 * Usage: IntArray itary;
 * ----------------------
 * Initializes a new empty array that can contain integers.
 */

    IntArray();

/*
 * Constructor: IntArray
 * Usage: IntArray itary(sz);
 * -------------------------
 * Initializes a new empty array that can contain sz integers.
 */

    IntArray(unsigned int n);

/*
 * Destructor: ~IntArray
 * Usage: (usually implicit)
 * -------------------------
 * Frees any heap storage associated with this integer array.
 */

    ~IntArray();

/*
 * Method: size
 * Usage: int nElems = itary.size();
 * ---------------------------------
 * Returns the number of integers in this array.
 */

    int size();

/*
 * Method: isEmpty
 * Usage: if (itary.isEmpty()) ...
 * -------------------------------
 * Returns true if this array contains no itegers.
 */

    bool isEmpty();

/*
 * Method: clear
 * Usage: itary.clear();
 * ---------------------
 * Removes all integers from this array.
 */

    void clear();

/*
 * Method: set
 * Usage: itary.set(idx, val);
 * ---------------------------
 * Sets idx-th elements with val. Raises an error if idx
 * out of bound.
 */

    void set(int index, int val);

/*
 * Method: get
 * Usage: int idxElems = itary.get(idx);
 * ----------------------
 * Returns the value of idx-th elements. Raises an error if
 * idx out of bound.
 */

    int get(int index);

/*
 * Method: pop
 * Usage: int i = itary.pop();
 * ---------------------------
 * Removes the top integer from this array and returns it.
 */

    int pop();

/*
 * Method: peek
 * Usage: int i = itary.peek();
 * ----------------------------
 * Returns the value of the top character from this array without
 * removing it.  Raises an error if called on an empty array.
 */

    int peek();

/*
 * Method: push
 * Usage: itary.push(i);
 * ---------------------
 * Pushes the integer i onto this array.
 */
    void push(const int i);

/*
 * Standard methods: copy constructor and assignment operator
 * ----------------------------------------------------------
 * The following lines make it illegal to copy a IntArray, by defining
 * copy constructor and assignment operator to delete
 */

   IntArray(const IntArray& src) = delete;
   IntArray& operator=(const IntArray& src) = delete;

/* Private section */

private:

/* Private constants */

    static const int INITIAL_CAPACITY = 10;  

/* Instance variables */

    int* array;                 /* Dynamic array of integers        */
    unsigned int capacity;      /* Allocated size of that array     */
    unsigned int count;         /* Current count of integers pushed */


/* Private function prototypes */

    void expandCapacity();

};

#endif // INTARRAY_H
