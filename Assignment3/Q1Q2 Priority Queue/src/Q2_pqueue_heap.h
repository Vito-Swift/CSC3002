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

    PriorityQueue();

    ~PriorityQueue();

    int size();

    bool isEmpty();

    void clear();

    void enqueue(ValueType value, double priority);

    ValueType dequeue();

    const ValueType peek();

    PriorityQueue(const PriorityQueue<ValueType>& src);
    PriorityQueue& operator=(const PriorityQueue<ValueType>& src);

private:

    struct Cell {
        ValueType data;
        double priority;
    };

    Vector<Cell> elements;

    void heapInsert(ValueType data, double priority);
    ValueType heapDeleteMin();

    void deepCopy(const PriorityQueue<ValueType>& src);

};

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue() {
    Cell flag;
    flag.priority = -1;
    elements.push_back(flag);
}

template <typename ValueType>
PriorityQueue<ValueType>::~PriorityQueue() {
    elements.clear();
}

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

template <typename ValueType>
void PriorityQueue<ValueType>::enqueue(ValueType value, double priority) {
    heapInsert(value, priority);
}

template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeue() {
    if (isEmpty())
        error("dequeue: Attempting to dequeue an empty queue");
    return heapDeleteMin();
}

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

template <typename ValueType>
const ValueType PriorityQueue<ValueType>::peek() {
    if (isEmpty()) error("peek: Attempting to peek at an empty queue");
    return elements[1].data;
}

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

template <typename ValueType>
void PriorityQueue<ValueType>::deepCopy(const PriorityQueue<ValueType>& src) {
    for (int i = 1; i < elements.size(); i++)
        enqueue(elements[i].data, elements[i].priority);
}

#endif
