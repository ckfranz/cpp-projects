#ifndef SYDE223_A1_POLYNOMIAL_H
#define SYDE223_A1_POLYNOMIAL_H

#include "doubly-linked-list.h"
#include <iostream>

using namespace std;


// Need members to store doubly-linked list
class Polynomial {

private:
    int size_;
    DoublyLinkedList coefficients; // Instance of doubly linked list

public:
    void print();
    Polynomial(int A[], int size);
    Polynomial* add(Polynomial* rhs);
    Polynomial* sub(Polynomial* rhs);
    Polynomial* mul(Polynomial* rhs);
};

#endif
