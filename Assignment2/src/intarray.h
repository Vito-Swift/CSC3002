#ifndef INTARRAY_H
#define INTARRAY_H


class IntArray {  
public:
    IntArray();
    IntArray(unsigned int n);
    IntArray(const IntArray& src);
    ~IntArray();
    int size();
    bool isEmpty();
    void clear();
    void set(int index, int val);
    int get(int index);
    int pop();
    void push(const int i);
    int peek();
    IntArray& operator=(const IntArray& src);
private:
    static const int INITIAL_CAPACITY = 10;  
    int* array;
    unsigned int capacity;
    unsigned int count;
    void deepCopy(const IntArray& src);
    void expandCapacity();
};

#endif // INTARRAY_H
