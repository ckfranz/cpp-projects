#include "doubly-linked-list.h"
#include <iostream>

using namespace std;

// NODE CONSTRUCTOR
DoublyLinkedList::Node::Node(DataType data)
{
    // DONE!
    // Creating new node
    value = data;
    next = nullptr;
    prev = nullptr;
}

// LINKED LIST CONSTRUCTOR
DoublyLinkedList::DoublyLinkedList()
{
    // DONE!
    // Initialize empty doubly linked list
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
    // Capacity is already set
}

// DESTRUCTOR
DoublyLinkedList::~DoublyLinkedList()
{
    // If there is , memory, must deallocate memory from every node.
    // Tricky (careful - some didn’t iterate through linked list to deallocate every single node!)  - > Make sure to do this
    // You must. Must also consider special case when size is zero!
    // Cant delete head since head points to null -> cause program to crash

    // While 'head_' is not NULL, Loop through the elements of the list, to deallocate memory
    while (head_) {
        Node* temp = head_;
        head_ = head_->next;
        // delete node at each iteration until every one is deallocated
        delete temp;
    }
    //cout << "List destructed!" << endl;
}

unsigned int DoublyLinkedList::size() const
{
    // DONE!
    // Return the size of the list
    //cout << "The size is: " << size_ << endl;
    return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
    // DONE!
    // Return the capacity of the list
    //cout << "The capacity is: " << CAPACITY << endl;
    return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
    // DONE!
    // Check if the list is empty
    // (ie. size = 0 -> will return true, size != 0 -> will return false)
    return (size_ == 0);
}

bool DoublyLinkedList::full() const
{
    // DONE!
    // Check if the list is full
    // (ie. size = capacity -> will return true, size != capacity -> will return false)
    // Note: size_ will never be greater than capacity
    return (size_ == CAPACITY);
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    // If size == 0, return an arbitrary value casted into DataType
    if (size_ == 0) {
        //cout << "No elements exist in the list" << (DataType) -999 << endl;
        return (DataType) -999;
    }
    // If index is valid
    Node *temp = getNode(index);
    // Check if the index is invalid (ie. temp = null)
    if (!temp) {
        // If invalid, return value of last element (ie. tail_->value)
        //cout << "Invalid index. Returning last element: " << tail_->value << endl;
        return tail_->value;
    }
    // If valid, return the value of the element
    // cout << "Element at index, " << index << " is: " << temp->value << endl;
    return temp->value;
}

unsigned int DoublyLinkedList::search(DataType value) const
{
    // Loop through list head to tail, checking if the node value = 'value'
    Node * temp = head_;

    // If 'value' exists, return the index of the first instance
    for (unsigned int i = 0; i < size_; i++) {
        if (temp->value == value) {
            //cout << "Found it! Index: " << i << endl;
            return i;
        }
        temp = temp->next;
    }

    // If it doesn't exist, return the size of the list
    //cout << "Element does not exist in the list!" << endl;
    return size_;
}

void DoublyLinkedList::print() const
{
    cout << "Print List:  [ ";
    Node *temp = head_;
    // Loop through list until temp == nullptr
    while (temp) {
        cout << temp->value <<" ";
        temp = temp->next;
    }
    cout << "]" << endl;
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    // Get the node given a specified index
    Node *temp = head_;
    // Only enter/remain in loop while: temp != null and i < index
    for (unsigned int i = 0; temp && i < index; ++i) {
        temp = temp->next;
    }
    return temp;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    // DONE!
    // Check if the index is in valid range (ie. 0 < index <= size_)
    if (index < 0 || index > size_) {
        //cout << "Index is not within range!" << endl;
        return false;
    }
    if (index == 0) {
        // If the value is inserted at the front, use the insert_front method!
        return insert_front(value);
    }
    if (index == size_) {
        // If the value is inserted at the back, use the insert_back method!
        return insert_back(value);
    } else {
        // If the value is inserted in the middle
        // Check for sufficient capacity
        if (size_ < CAPACITY) {
            Node *tempVal = new Node(value);
            Node *tempIndex = getNode(index);

            tempVal->prev = tempIndex->prev; // tempVal gets tempIndex's prev pointer
            tempIndex->prev->next = tempVal;  // The next pointer, initially pointing to tempIndex is now pointing to tempVal
            tempVal->next = tempIndex; // Set tempVal's next pointer to tempIndex
            tempIndex->prev = tempVal; // Set tempIndex's previous pointer to tempVal
        } else {
            // if list is full, return false
            //cout << "Max capacity! Could not insert." << endl;
            return false;
        }
    }
    ++size_;
    return true;
}

bool DoublyLinkedList::insert_front(DataType value)
{
    // DONE!
    if (size_ < CAPACITY) {
        Node *temp = new Node(value);

        // Set temp' previous pointer to NULL, temp's next pointer to head_
        temp->prev = nullptr;
        temp->next = head_;
        // If list is empty (ie. head set to nullptr)
        if (head_ == nullptr) {
            // Re assign tail pointer to temp
            tail_ = temp;
        } else {
            // If not empty, set current head's 'prev' pointer to temp
            head_->prev = temp;
        }
        head_ = temp;
        size_++;
        return true;
    } else {
        // if not sufficient capacity, return false
        //cout << "Max capacity! Could not insert." << endl;
        return false;
    }
}

bool DoublyLinkedList::insert_back(DataType value)
{
    // DONE! (Double check)
    if (size_ < CAPACITY) {
        Node *temp = new Node(value);

        // Set temp' previous pointer to tail_, temp's next pointer to NULL
        temp->prev = tail_;
        temp->next = nullptr;

        // if list is empty (ie. tail set to, nullptr)
        if(tail_ == nullptr)
            head_ = temp;
        else
            tail_->next = temp;
        tail_ = temp;
        size_++;
        return true;
    } else {
        // if no, return false
        //cout << "Max capacity! Could not insert." << endl;
        return false;
    }
}

bool DoublyLinkedList::remove(unsigned int index)
{
    // DONE!
    // Check if the index is less than zero, or exceeds valid range
    if (index < 0 || index >= size_) {
        //cout << "Index exceeds valid range! OR Negative number not allowed!" << endl;
        return false;
    }
    // If the value is removed from the front, use the remove_front method!
    if (index == 0) {
        return remove_front();
    }
    // If the value is removed from the back, use the remove_back method!
    if(index == size_-1) {
        return remove_back();
    }

    // If the value is inserted in the middle
    Node *temp = getNode(index);
    temp->prev->next = temp->next; // Set the next pointer that used to point to temp, to the element after temp
    temp->next->prev = temp->prev; // Set the pev pointer that used to point to temp, to the element before temp
    delete temp;
    size_--;
    return true;
}

bool DoublyLinkedList::remove_front()
{
    // DONE! - May check
    // If there are no elements in the list
    if (size_ == 0) {
        //cout << "List is empty, Nothing to remove!" << endl;
        return false;
    }
    // If there is only one element
    if (head_ == tail_) {
        Node *temp = head_;
        head_ = nullptr;
        tail_ = nullptr;
        delete temp;
        //cout << "First element was removed" << endl;
        size_--;
        return true;
    } else {
        // If there is more than one element
        Node *temp = head_;
        head_ = head_->next;
        head_->prev = nullptr;
        delete temp;
        //cout << "First element was removed" << endl;
        size_--;
        return true;
    }
}

bool DoublyLinkedList::remove_back()
{
    // DONE!
    // If there are no elements in the list
    if (size_ == 0) {
        //cout << "List is empty, Nothing to remove!" << endl;
        return false;
    }
    // If there is only one element
    if (head_ == tail_) {
        Node *temp = head_;
        head_ = nullptr;
        tail_ = nullptr;
        delete temp;
        //cout << "Last element was removed" << endl;
        size_--;
        return true;
    }
    else {
        // If there is more than one element
        Node *temp = tail_;
        tail_ = tail_->prev;
        tail_->next = nullptr;
        delete temp;
        //cout << "Last element was removed" << endl;
        size_--;
        return true;
    }
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{

    // Initialize a pointer (temp) to the reference value of the element at 'index'
    DataType *temp = &getNode(index)->value;
    // Check if temp is null
    if (!temp) {
        // If yes, return false, do not replace
        //cout << "Illegal replacement" << endl;
        return false;
    }
    // Set pointer temp to value
    *temp = value;
    return true;
}

