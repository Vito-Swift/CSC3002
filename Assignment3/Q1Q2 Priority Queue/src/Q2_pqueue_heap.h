/*
 * File: pqueue.h
 * --------------
 * This file exports the PriorityQueue class, a collection in which values
 * are processed in priority order.
 */

#ifndef _pqueue_h
#define _pqueue_h

#include "vector.h"
#include "error.h"
#include <iostream>

/*
 * Class: PriorityQueue<ValueType>
 * -------------------------------
 * This class models a structure called a priority queue in which values
 * are processed in order of priority.  As in conventional English usage,
 * lower priority numbers correspond to higher effective priorities, so
 * that a priority 1 item takes precedence over a priority 2 item.
 */

template <typename ValueType>
class PriorityQueue {

public:

/*
 * Constructor: PriorityQueue
 * Usage: PriorityQueue<ValueType> pqueue;
 * --------------------------------------
 * Initializes a new empty priority queue.
 */

    PriorityQueue();

/*
 * Destructor: ~PriorityQueue
 * Usage: (usually implicit)
 * --------------------------
 * Frees any heap storage associated with this queue.
 */

    ~PriorityQueue();

/*
 * Method: size
 * Usage: int n = pqueue.size();
 * -----------------------------
 * Returns the number of values in the priority queue.
 */

    int size();

/*
 * Method: isEmpty
 * Usage: if (pqueue.isEmpty()) . . .
 * ----------------------------------
 * Returns true if the priority queue contains no elements.
 */

    bool isEmpty();

/*
 * Method: clear
 * Usage: pqueue.clear();
 * ----------------------
 * Removes all elements from this queue.
 */

    void clear();

/*
 * Method: enqueue
 * Usage: pqueue.enqueue(value, priority);
 * ---------------------------------------
 * Adds value with corresponding priority to the queue
 */

    void enqueue(ValueType value, double priority);

/*
 * Method: dequeue
 * Usage: ValueType first = pqueue.dequeue();
 * ------------------------------------------
 * Removes and returns the first item in the priority queue.   This method
 * signals an error if called on an empty queue.
 */

    ValueType dequeue();

/*
 * Method: peak
 * Usage: ValueType first = pqueue.peek();
 * ---------------------------------------
 * Returns the first value in the priority queue without removing it.  This
 * method signals an error if called on an empty queue.
 */

    const ValueType peek();

/*
 * Copy constructor and assignment operator
 * ----------------------------------------
 * These methods implement deep copying from queues.
 */

    PriorityQueue(const PriorityQueue<ValueType>& src);
    PriorityQueue& operator=(const PriorityQueue<ValueType>& src);

/* Private section */

private:

/* Type for heap cell */

    struct Cell {
        ValueType data;                                     /* The data value                          */
        double priority;                                    /* The cell priority                       */
    };

/* Instance variables */

    Vector<Cell> elements;                                  /* Dynamic list based heap                 */

/* Heap operations */

    void heapInsert(ValueType data, double priority);       /* Insert cell into heap                   */
    ValueType heapDeleteMin();                              /* Remove and return the root cell of heap */

/* Private method prototypes */

    void deepCopy(const PriorityQueue<ValueType>& src);

};

/*
 * Implementation section
 * ----------------------
 * C++ requires that the implementation for a template class be available
 * to the compiler whenever that type is used. The effect of this
 * restriction is that header files must include the implementation.
 * Clients should not need to look at any of this code beyond this point.
 */

/*
 * Implementation notes: PriorityQueue constructor
 * ------------------------------------------------
 * The constructor push a flag into the heap with minimum priority
 */

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue() {
    Cell flag;
    flag.priority = -1;
    elements.push_back(flag);
}

/*
 * Implementation notes: ~PriorityQueue destructor
 * -----------------------------------------------
 * The destructor frees any heap memory allocated by the queue.
 */

template <typename ValueType>
PriorityQueue<ValueType>::~PriorityQueue() {
    elements.clear();
}

/*
 * Implementation notes: size, isEmpty, clear
 * ------------------------------------------
 * These methods use the size() method of dynamic list.
 */

template <typename ValueType>
int PriorityQueue<ValueType>::size() {
    return elements.size() - 1;
}

template <typename ValueType>
bool PriorityQueue<ValueType>::isEmpty() {
    return elements.size() - 1 == 0;
}

template <typename ValueType>
void PriorityQueue<ValueType>::clear() {
    while (elements.size() > 1) dequeue();
}

/*
 * Implementation notes: enqueue
 * -----------------------------
 * This method insert an cell into the heap
 */

template <typename ValueType>
void PriorityQueue<ValueType>::enqueue(ValueType value, double priority) {
    heapInsert(value, priority);
}

/*
 * Implementation notes: dequeue, peek
 * -----------------------------------
 * These methods check for an empty queue and report an error if
 * there is no first element. The dequeue method returns the first
 * elements and re-heaps the dynamic list using method heapDeleteMin,
 * while peek only returns the first element in the list.
 */

template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeue() {
    if (isEmpty())
        error("dequeue: Attempting to dequeue an empty queue");
    return heapDeleteMin();
}

template <typename ValueType>
const ValueType PriorityQueue<ValueType>::peek() {
    if (isEmpty()) error("peek: Attempting to peek at an empty queue");
    return elements[1].data;
}

/*
 * Implementation notes: heapInsert
 * --------------------------------
 * This method is a heap operation. It inserts a cell into the heap
 * and re-heaps the dynamic list according to the priority of the cell.
 */

template <typename ValueType>
void PriorityQueue<ValueType>::heapInsert(ValueType value, double priority) {
    int i;
    Cell tmp;
    tmp.data = value;
    tmp.priority = priority;
    elements.push_back(tmp);
    for (i = elements.size()-1; elements[i/2].priority > priority; i /= 2)
        elements[i] = elements[i/2];
    elements[i] = tmp;
}

/*
 * Implementation notes: heapDeleteMin
 * -----------------------------------
 * This method is a heap operation. It returns the first element in the
 * dynamic list and re-heaps the dynamic list after removing the first
 * element.
 */

template <typename ValueType>
ValueType PriorityQueue<ValueType>::heapDeleteMin() {
    Cell minCell = elements[1];
    Cell lstCell = elements[elements.size()-1];

    int i;
    int child;
    for (i = 1, child = 2; 2 * i <= elements.size() - 1; i = child) {
        child = i * 2;
        if (child != elements.size()-1 && elements[child+1].priority < elements[child].priority)
            child++;
        if (lstCell.priority > elements[child].priority)
            elements[i] = elements[child];
        else
            break;
    }
    elements[i] = lstCell;
    elements.remove(elements.size()-1);
    return minCell.data;
}

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * These methods follow the standard template, leaving the work to deepCopy.
 */

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue(const PriorityQueue<ValueType>& src) {
    deepCopy(src);
}

template <typename ValueType>
PriorityQueue<ValueType>& PriorityQueue<ValueType>::operator=(const PriorityQueue<ValueType>& src) {
    if (this != &src) {
        clear();
        deepCopy(src);
    }
    return *this;
}

/*
 * Implementation notes: deepCopy
 * ------------------------------
 * This function copies the data from the src parameter into the current
 * object. This implementation simply walks down the dynamic list in the
 * source object and enqueues each value in the destination.
 */

template <typename ValueType>
void PriorityQueue<ValueType>::deepCopy(const PriorityQueue<ValueType>& src) {
    for (int i = 1; i < elements.size(); i++)
        enqueue(elements[i].data, elements[i].priority);
}

#endif
