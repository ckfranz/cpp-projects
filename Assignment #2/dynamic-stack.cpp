#include "dynamic-stack.h"
#include <iostream>

using namespace std;

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -9999;

DynamicStack::DynamicStack() {
    size_ = 0;
    init_capacity_ = 16;
    capacity_ = init_capacity_;
    // Initialize new array as the sequential list
    StackItem * arr = new StackItem[capacity_];
    items_ = arr;
}

DynamicStack::DynamicStack(unsigned int capacity){
    size_ = 0;
    capacity_ = capacity;
    init_capacity_ = capacity_;
    // Initialize new array as the sequential list
    StackItem * arr = new StackItem[capacity_];
    items_ = arr;
}

DynamicStack::~DynamicStack() {
    delete [] items_;
    items_ = nullptr; // Extra
}

bool DynamicStack::empty() const {
    // Check if the list is empty (ie. size_ = 0), regardless of capacity
    // if yes, return true

    if (size_ == 0) {
        // cout << "true - List is empty!" << endl;
        return true;
    } else {
        // if no, return false (ie. size_ < 0)
        // cout << "false - List is not empty!" << endl;
        return false;
    }
}

int DynamicStack::size() const {
    // Return size of list (size_)
    //cout << "Size of stack is: " << size_ << endl;
    return size_;
}

void DynamicStack::push(StackItem value) {
    // Check if stack is full
    if(size_ == capacity_) {
        // cout << "stack cap is reached, double its size." << endl;
        // Not possible to change initial capacity, so create new, deallocate old
        int * newItems = new int [2 * capacity_];
        // Double the capacity of the new array
        capacity_ = 2 * capacity_;
        // copy all items to the new array
        for (int i = 0; i < size_; i++){ // loop for n = size times.
            newItems[i] = items_[i];
        }
        // Deallocate memory of old array
        int * temp = items_;
        items_ = newItems;
        delete [] temp;
    }

    // Testing: Ouput capacity of the stack
    // cout << "Initial-cap: " << init_capacity_ << ", Current-cap: " << capacity_ << endl;
    // Add item to the top of the stack
    items_[size_] = value;
    size_++; // Increase size of the stack by one
}

DynamicStack::StackItem DynamicStack::pop() {
    // Check if there is anything to pop
    int popped;
    if(size_ == 0){
        // Nothing to pop
        //cout << "stack is empty! cannot pop." << endl;
        return EMPTY_STACK;   // example EMPTY RETURN value
    } else {
        // store popped item
        popped = items_[size_ - 1];

        //cout << "First item was popped: " << popped << endl;
        size_--; // Decrease size of the array (stack)

        // if size < current_capacity / 4, reduce current capacity by half (round to integer).
        if (size_ <= capacity_ / 4 && capacity_ / 2 >= init_capacity_) {
            capacity_ = capacity_ / 2;
        }
        // Return popped item
        return popped;
    }
}

DynamicStack::StackItem DynamicStack::peek() const {
    // Check if there is anything to peek
    if(size_ == 0) {
        // cout << "Stack is empty! Cannot peek." << endl;
        return EMPTY_STACK;   // example EMPTY RETURN value
    } else {
        // cout << "Peeking: " << items_[0] << endl;
        // Return the value of the first item in the stack
        return items_[size_ - 1];
    }
}

void DynamicStack::print() const {
    //check if there is anything to print (Not used for grading, just testing)
    if (size_ == 0) {
        cout << "stack is empty! Nothing to print." << endl;
        return;
    } else {
        // Print all elements of the list in the format: [ x1, x2, ... xn ]
        cout << "Print List:  [ ";
        // Iterate through the array back to front, printing each element in the list
        for (int i = size_ - 1; i >= 0; --i)
            cout << items_[i] << " ";

        cout << "]" << endl;
    }
}