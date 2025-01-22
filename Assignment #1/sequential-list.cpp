#include <iostream>
#include "sequential-list.h"

using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
    // DONE!
    size_ = 0;
    capacity_ = cap;
    // Initialize new array as the sequential list
    DataType * arr = new DataType[capacity_];
    data_ = arr;
}

// DESTRUCTOR
SequentialList::~SequentialList()
{
    // Be careful about the destructor. Remember that you need to deallocate memory for
    // all the dynamically allocated variables (data_ in this case).
    // (remember to read online module Week 2.2 “Using new[] and delete[] operators for array”)
    // Called automatically!
    delete []data_;
    data_ = nullptr;
    //cout << "List destructed!" << endl;
}

unsigned int SequentialList::size() const
{
    // DONE!
    // Return size of list (size_)
    //cout << "The size is: " << size_ << endl;
    return size_;
}

unsigned int SequentialList::capacity() const
{
    // DONE!
    // Return capacity of the list (capacity_)
    //cout << "The capacity is: " << capacity_ << endl;
    return capacity_;
}

bool SequentialList::empty() const
{
    // CHECK is it empty if size_ = 0 && capacity_ = 0? ~ Yes, I think?

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

bool SequentialList::full() const
{
    // DONE!
    if (size_ == capacity_) {
        //cout << "true - List is at capacity!" << endl;
        return true;
    } else {
        // The following covers the case when size_ < capacity
        // size_ should never be greater then capacity!
        //cout << "false - List is not at capacity!" << endl;
        return false;
    }
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    // DONE!
    // If the size is 0, return arbitrary data item
    if (size_ == 0) {
        //cout << "No elements exist in the list" << endl;
        return data_[0];
    }
    // If index is within valid range (ie. 0 to size_-1), return element at that index
    if (index <= size_-1) {
        //cout << "Returning value at index " << index << " is " << data_[index] << endl;
        return data_[index];
    } else {
        // If index is outside valid range, return last element of array
        //cout << "Invalid index, " << index << endl;
        //cout << "Returning last element: " << data_[size_-1] << endl;
        return data_[size_-1];
    }
}

unsigned int SequentialList::search(DataType val) const
{
    // DONE!
    // loop through elements of the list, checking if 'val' is on of them
    // if yes, return the index of the element
    for (int i = 0; i < size_; ++i) {
        if (data_[i] == val){
            //cout << "Search - found it! Index of: " << i << endl;
            return i;
        }
    }
    // if no (ie. size = 0 or val not found), return the size
    //cout << "This value does not exist in the list. Return size of list: " << size_ << endl;
    return size_;
}

void SequentialList::print() const
{
    // DONE!
    // Print all elements of the list in the format: [ x1, x2, ... xn ]
    cout << "Print List:  [ ";
    for (int i = 0; i < size_; i++)
        cout << data_[i] << " ";

    cout << "]" << endl;
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    // DONE!
    // Check if there is space in the list and the index is valid
    // if yes, insert element at index, push the rest back 1, return true and increase size
    if (index <= size_ && size_ < capacity_) {
        for (unsigned int i = size_; i >= index + 1; --i) {
            data_[i] = data_[i-1];
        }
        //cout << "Insert - inserted: " << val << " at index: " << index << endl;
        data_[index] = val;
        size_ ++;
        return true;
    } else {
        // if no, return false
        //cout << "Invalid index OR max capacity! Could not insert." << endl;
        return false;
    }
}

bool SequentialList::insert_front(DataType val)
{
    // DONE!
    // check if there is capacity in the list for another element
    // if yes, insert element at first index, push the rest back 1, return true and increase size
    if (size_ < capacity_) {
        for (unsigned int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }
        //cout << "Insert Front - inserted: " << val << endl;
        data_[0] = val;
        size_++;
        return true;
    } else {
        // if no, return false
        //cout << "Max capacity! Could not insert." << endl;
        return false;
    }
}

bool SequentialList::insert_back(DataType val)
{
    // DONE!
    // check if there is capacity in the list for another element
    // if yes, insert element at the end of the list, return true and increase size
    if (size_ < capacity_) {
        //cout << "Insert Back - inserted: " << val << endl;
        data_[size_] = val;
        size_++;
        return true;
    } else {
        // if no, return false
        //cout << "Max capacity! Could not insert." << endl;
        return false;
    }
}

bool SequentialList::remove(unsigned int index)
{
    // DONE!
    // check if there is at least one element and the index is valid
    // if yes, shift all elements after the one removed, 1 space forwards, decrease size and return true
    if (size_ > 0 && index <= size_-1) {
        for (unsigned int i = index; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        //cout << "Element at " << index << " removed!" << endl;
        size_--;
        return true;
    } else {
        // if no, return false
        //cout << "Invalid Input OR No element to remove!" << endl;
        return false;
    }
}

bool SequentialList::remove_front()
{
    // DONE!
    // Check if there is at least one element in the list
    // if yes, shift all elements after element 0, 1 space forwards, decrease size and return true
    if (size_ > 0) {
        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        //cout << "First element removed!" << endl;
        size_--;
        return true;
    } else {
        // if no, return false
        //cout << "No element to remove!" << endl;
        return false;
    }
}

bool SequentialList::remove_back()
{
    // DONE!
    // Check if there is at least one element in the list
    // if yes, decrease size and return true
    if (size_ > 0) {
        //cout << "Last element removed" << endl;
        size_--;
        return true;
    } else {
        // if no, return false
        //cout << "No element to remove!" << endl;
        return false;
    }
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    // Check if there is at least one element in the list and the index is valid
    // if yes, replace the value at index and return true
    if (size_ > 0 && index < size_) {
        data_[index] = val;
        //cout << "Index " << index << " was replaced with " << val << endl;
        return true;
    } else {
        // if no, return false
        //cout << "Invalid index OR No element to replace!" << endl;
        return false;
    }
}