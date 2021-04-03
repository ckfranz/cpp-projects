#ifndef SYDE121_A5_BOOK_HPP
#define SYDE121_A5_BOOK_HPP

#include <iostream>
using namespace std;

//PURPOSE: Models a book instance with corresponding attributes
class Book {
    string title, author, dop;
public:
    //PURPOSE: Parametric constructor with all attributes specified
    Book(string new_title, string new_authors, string new_dop);
    
    //PURPOSE: Parametric constructor with only title and author specified
    Book(string new_title, string new_authors);
    
    //PURPOSE: Parametric constructor with only title specified
    Book(string new_title);
    
    //PURPOSE: Parametric constructor with no attributes specified
    Book();
    
    //PURPOSE: Service function that outputs all attribute values
    void print();
    
    //PURPOSE: Simple accesor methods for member attributes
    string get_title();
    string get_author();
    string get_dop();
};

#endif
