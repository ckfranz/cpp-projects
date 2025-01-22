#include "circular-queue.h"
#include <iostream>

using namespace std;

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -9999;

CircularQueue::CircularQueue() {
    size_ = 0;
    capacity_ = 16;
    head_ = 0;
    tail_ = 0;
    // Initialize new array as the sequential list
    QueueItem * arr = new QueueItem[capacity_];
    items_ = arr;
}

CircularQueue::CircularQueue(unsigned int capacity) {
    size_ = 0;
    capacity_ = capacity;
    head_ = 0;
    tail_ = 0;
    // Initialize new array as the sequential list
    QueueItem * arr = new QueueItem[capacity_];
    items_ = arr;
}

CircularQueue::~CircularQueue() {
    delete [] items_;
    items_ = nullptr;
}

bool CircularQueue::empty() const {
    // Check if the list is empty (ie. size_ = 0), regardless of capacity
    // if yes, return true

    if (size_ == 0) {
        //cout << "true - List is empty!" << endl;
        return true;
    } else {
        // if no, return false (ie. size_ < 0)
        //cout << "false - List is not empty!" << endl;
        return false;
    }
}

bool CircularQueue::full() const {
    if(size_ == capacity_) {
        //cout << "stack cap is reached, double its size." << endl;
        return true;
    } else {
        return false;
    }
}

int CircularQueue::size() const {
    // Return size of list (size_)
    // cout << "Size of stack is: " << size_ << endl;
    return size_;
}

bool CircularQueue::enqueue(QueueItem value) {
    //check if Queue is full
    if(size_ == capacity_) {
        // cout << "Queue is full! cannot enqueue." << endl;

        return false;
    } else { // not full, enqueue at iRear
        // check if need to set back to 0
        ////////////////////////////////
        items_[tail_] = value;
        tail_ ++;
        size_ ++;
        if (tail_ == capacity_) tail_ = 0;
        return true;
        ////////////////////////////////
    }
}

CircularQueue::QueueItem CircularQueue::dequeue() {
    //check if there is anything to dequeue
    if (size_ == 0){
        // cout << "Queue is empty! cannot dequeue." << endl;
        return EMPTY_QUEUE;
    } else { // dequeue from iFront
        // check if need to be set back to zero
        ///////////////////////////////
        int dequeue = items_[head_];
        head_ ++;
        size_ --;
        if (head_ == capacity_) head_ = 0;
        return dequeue;
        ///////////////////////////////
    }
}

CircularQueue::QueueItem CircularQueue::peek() const {
//check if there is any node
    if (size_ == 0) {
        // cout << "Queue is empty! nothing to peek." << endl;
        return EMPTY_QUEUE;
    } else {
        ///////////////////////////////
        return items_[head_];
        ///////////////////////////////
    }
}

void CircularQueue::print() const {
    //check if there is anything to print
    if(size_ == 0){
        cout << "Queue is empty! nothing to print." << endl;
        return;
    } else {
        ///////////////////////////////
        // Print all elements of the list in the format: [ x1, x2, ... xn ]
        cout << "Print List:  [ ";
        // Iterate through the array back to front, printing each element in the list
        for (int i = 0; i < size_; ++i)
            cout << items_[i] << " ";

        cout << "]" << endl;



        ///////////////////////////////
        cout << endl;
    }
}

