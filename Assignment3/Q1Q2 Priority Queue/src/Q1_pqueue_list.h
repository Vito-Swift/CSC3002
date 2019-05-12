/*
 * File: pqueue.h
 * --------------
 * This interface exports the PriorityQueue template class, which implements
 * a queue in which the elements are dequeued in priority order.
 */

#ifndef _pqueue_h
#define _pqueue_h

#include "error.h"

/*
 * Class: PriorityQueue<ValueType>
 * -------------------------------
 * This class models a linear structure called a priority queue in which
 * values are processed in order of priority.  As in conventional English
 * usage, lower priority numbers correspond to higher effective priorities,
 * so that a priority 1 item takes precedence over a priority 2 item.
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

/* Type for linked list cell */

    struct Cell {
        ValueType data;                                 /* The data value                  */
        double priority;                                /* The cell priority               */
        Cell* link;                                     /* link to the next cell           */
    };

/* Instance variables */

    Cell* head;                                         /* Pointer to the cell at the head */
    Cell* tail;                                         /* Pointer to the cell at the tail */
    int count;                                          /* Number of elements in the queue */

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
 * The constructor creates an empty linked list and sets the count to 0.
 */

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue() {
    head = tail = nullptr;
    count = 0;
}

/*
 * Implementation notes: ~Queue destructor
 * ---------------------------------------
 * The destructor frees any heap memory allocated by the queue.
 */

template <typename ValueType>
PriorityQueue<ValueType>::~PriorityQueue() {
    clear();
}

/*
 * Implementation notes: size, isEmpty, clear
 * ------------------------------------------
 * These methods use the count variable and therefore run in constant time.
 */

template <typename ValueType>
int PriorityQueue<ValueType>::size() {
    return count;
}

template <typename ValueType>
bool PriorityQueue<ValueType>::isEmpty() {
    return count == 0;
}

template <typename ValueType>
void PriorityQueue<ValueType>::clear() {
    while (count > 0) dequeue();
}

/*
 * Implementation notes: enqueue
 * -----------------------------
 * This method allocates a new list cell and chains it according
 * to its priority value. If the queue is currently empty, the
 * new cell also becomes the head pointer in the queue.
 */

template <typename ValueType>
void PriorityQueue<ValueType>::enqueue(ValueType value, double priority) {
    Cell* probe = head;
    Cell* tmp = new Cell;
    tmp->data = value;
    tmp->priority = priority;
    tmp->link = nullptr;

    if (head == nullptr) {
        head = tmp;
        tail = tmp;
    } else if (head->priority > priority) {
        tmp->link = head;
        head = tmp;
    } else {
        while (probe->link != nullptr && probe->link->priority < priority)
            probe = probe->link;
        if (probe->link == nullptr) tail = tmp;
        else tmp->link = probe->link;
        probe->link = tmp;
    }

    count++;
}

/*
 * Implementation notes: dequeue, peek
 * -----------------------------------
 * These methods check for an empty queue and report an error if
 * there is no first element.  The dequeue method also checks for
 * the case in which the queue becomes empty and sets both the head
 * and tail pointers to NULL.
 */

template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeue() {
    if (isEmpty())
        error("dequeue: Attempting to dequeue an empty queue");
    Cell* probe = head;
    ValueType ret = probe->data;
    head = probe->link;
    if (head == nullptr) tail = nullptr;
    delete probe;
    count--;
    return ret;
}

template <typename ValueType>
const ValueType PriorityQueue<ValueType>::peek() {
    if (isEmpty()) error("peek: Attempting to peek at an empty queue");
    return head->data;
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
 * object.  This implementation simply walks down the linked list in the
 * source object and enqueues each value in the destination.
 */

template <typename ValueType>
void PriorityQueue<ValueType>::deepCopy(const PriorityQueue<ValueType>& src) {
    head = nullptr;
    tail = nullptr;
    count = 0;
    for (Cell* tmp = src.head; tmp != nullptr; tmp = tmp->link)
        enqueue(tmp->data);
}

#endif
