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
        Cell* link;
    };

    Cell* head;
    Cell* tail;
    int count;

    void deepCopy(const PriorityQueue<ValueType>& src);

};

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue() {
    head = tail = nullptr;
    count = 0;
}

template <typename ValueType>
PriorityQueue<ValueType>::~PriorityQueue() {
    clear();
}

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
    head = nullptr;
    tail = nullptr;
    count = 0;
    for (Cell* tmp = src.head; tmp != nullptr; tmp = tmp->link)
        enqueue(tmp->data);
}

#endif
