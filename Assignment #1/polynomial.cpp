#include "polynomial.h"
#include <iostream>

using namespace std;

// Class constructor
// Array 'A[]' contains coefficients

// The constructor creates the matching 'Polynomial' instance along with a member 'DoublyLinkedList' instance
// of the appropriate size, and inserts all of the array values into it.

Polynomial::Polynomial(int A[], int size) {
    size_ = size;
    //cout << size_ << endl;

    for (int i = 0; i < size_; ++i) {
        coefficients.insert_back(A[i]);
    }
    //coefficients.print();
}


Polynomial* Polynomial::add(Polynomial* rhs) {

    // Declare max and min int to store max and min possible values
    int max, min;

    // determine the max & min possible sizes for the polynomial addition
    if (size_ > rhs->size_) {
        max = size_;
        min = rhs->size_;
    } else {
        // Either rhs->size_ > size_ or they are equal (in which case it doesnt matter)
        max = rhs->size_;
        min = size_;
    }

    // Initialize an array to store the result of the polynomial addition
    int result[max];

    // For the minimum possible size, loop through and calculate new coefficients
    for (int i = 0; i < min; ++i) {
        result[i] = coefficients.select(i) + rhs->coefficients.select(i);
    }
    // If rhs is smaller the original, add the remaining original coefficients directly to the array
    if (rhs->size_ < size_) {
        for (int i = min; i < max; ++i) {
            result[i] = coefficients.select(i);
        }
    } else {
        // If rhs is larger the original, add the remaining rhs coefficients directly to the array
        for (int i = min; i < max; ++i) {
            result[i] = rhs->coefficients.select(i);
        }
    }

    return new Polynomial(result, max);
    // coefficient[0] + rhs[0]
    // return new instance
}


Polynomial* Polynomial::sub(Polynomial* rhs) {

    // Declare max and min int to store max and min possible values
    int max, min;

    // determine the max & min possible sizes for the polynomial subtraction
    if (size_ > rhs->size_) {
        max = size_;
        min = rhs->size_;
    } else {
        // Either rhs->size_ > size_ or they are equal (in which case it doesnt matter)
        max = rhs->size_;
        min = size_;
    }

    // Initialize an array to store the result of the polynomial subtraction
    int result[max];

    // For the minimum possible size, loop through and calculate new coefficients
    for (int i = 0; i < min; ++i) {
        result[i] = coefficients.select(i) - rhs->coefficients.select(i);
    }
    // If rhs is smaller the original, add the remaining original coefficients directly to the array
    if (rhs->size_ < size_) {
        for (int i = min; i < max; ++i) {
            result[i] = coefficients.select(i);
        }
    } else {
        // If rhs is larger the original, add the remaining rhs coefficients directly to the array
        for (int i = min; i < max; ++i) {
            result[i] = rhs->coefficients.select(i);
        }
    }

    return new Polynomial(result, max);
}

Polynomial* Polynomial::mul(Polynomial* rhs) {

    // The maximum size of the polynomial product is sum of sizes -1
    int max = size_ + rhs->coefficients.size() -1;

    // Declare the polynomial product array
    int result[max];

    // Initialize the array
    for (int i = 0; i < max; i++)
        result[i] = 0;

    // Multiply the two polynomials term by term
    for (int i = 0; i < size_; i++) {
        // Multiply the current term of the polynomial with every term of the rhs polynomial
        for (int j = 0; j < rhs->coefficients.size(); j++) {
            result[i + j] += coefficients.select(i) * rhs->coefficients.select(j);
        }
    }

    return new Polynomial(result, max);
}


void Polynomial::print() {

    // Loop though doubly linked list from back to front to print the polynomial in the proper order
    for (int i = size_ - 1; i >= 0; i--) {
        // Terms after the first, but before the last require a proceeding '+'
        for (int j = i; j < size_; j++) // Check if it is the first non-zero coefficient (don't add '+')
            if (i >= 0 && coefficients.select(j+1) !=0 && i != size_ -1 && coefficients.select(i) != 0) {
                cout << " + ";
                break; // Escape loop if condition is met once
        }
        // If the term is positive, output the term normally (ie. ax^b )
        if (coefficients.select(i) > 0) {
            cout << coefficients.select(i);
            cout << "x^" << i;
        }
        // If the term is negative, output the term with brackets (ie. (-a)x^b )
        if (coefficients.select(i) < 0) {
            cout << "(" << coefficients.select(i) << ")";
            cout << "x^" << i;
        }
    }
    cout << endl;
}
