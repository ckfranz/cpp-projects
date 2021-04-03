#ifndef SYDE121_A5_LIBRARY_HPP
#define SYDE121_A5_LIBRARY_HPP

#include <vector>

using namespace std;

//PURPOSE: model a library with corresponding attributes
class Library {
    vector<Book> my_library;
    
public:
    //PURPOSE: default constructor
    Library();
    
    //PURPOSE: parametric constructor with all attributes specified
    Library(vector<Book> new_book_list);
    
    //PURPOSE: output all the books stored in the Library instance
    void print();
    
    //PURPOSE: insert the book to the library if the book is not found
    bool insertion_string(string title_tbc, string author_tbc, string dop_tbc); //tbc means to be checked here
    
    //PURPOSE: insert the book to the library if the book is not found
    bool insertion_book(Book book_tbc); //tbc means to be checked here
    
    //PURPOSE: remove the book from the library if the book is found
    bool remove_string(string title_tbc, string author_tbc, string dop_tbc);
    
    //PURPOSE: remove the book from the library if the book is found
    bool remove_book(Book book_tbc);
    
    //PURPOSE: allow access for variable stored in private
    vector<Book> get_my_library();
};

#endif

