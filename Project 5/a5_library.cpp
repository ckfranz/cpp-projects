#include <iostream>
#include <vector>
#include "a5_book.hpp"
#include "a5_library.hpp"
using namespace std;

Library::Library() {}

Library::Library(vector<Book> new_book_list) :
    my_library(new_book_list) {}

void Library::print() {
    //iterate through and output book values from the library vector
    for (int i = 0; i < my_library.size(); i++) {
        cout << "Details for book number " << i << ": ";
        my_library[i].print();
    }
}

bool Library::insertion_string(string title_tbc, string author_tbc, string dop_tbc) {
    //initialize the existence of the book to be checked to false
    bool exists = false;
    //iterate through library vector to isentify whether the book to be checked exists
    for (int i = 0; i < my_library.size() && !exists; i++) {
        exists = title_tbc == my_library[i].get_title();
        exists = exists && author_tbc == my_library[i].get_author();
        exists = exists && dop_tbc == my_library[i].get_dop();
    }
    //if the book does not exist in the library, add it as the last element
    if (!exists) {
        Book book_tbc(title_tbc, author_tbc, dop_tbc);
        my_library.push_back(book_tbc);
    }
    return !exists;
}

bool Library::insertion_book(Book book_tbc) {
    //initialize the existence of the book to be checked to false
    bool exists = false;
    string title_tbc = book_tbc.get_title(), author_tbc = book_tbc.get_author(), dop_tbc = book_tbc.get_dop();
    //iterate through library vector to isentify whether the book to be checked exists
    for (int i = 0; i < my_library.size() && !exists; i++) {
        exists = title_tbc == my_library[i].get_title();
        exists = exists && author_tbc == my_library[i].get_author();
        exists = exists && dop_tbc == my_library[i].get_dop();
    }
    //if the book does not exist in the library, add it as the last element
    if (!exists) {
        my_library.push_back(book_tbc);
    }
    return !exists;
}

bool Library::remove_string(string title_tbc, string author_tbc, string dop_tbc) {
    //initialize the existence of the book to be checked to false
    bool exists = false;
    //iterate through library vector to identify whether the book to be checked exists
    for (int i = 0; i < my_library.size() && !exists; i++) {
        exists = title_tbc == my_library[i].get_title();
        exists = exists && author_tbc == my_library[i].get_author();
        exists = exists && dop_tbc == my_library[i].get_dop();
        //if matching attributes are found, then erase the element
        if (exists) {
            my_library.erase (my_library.begin()+i);
            break;
        }
    }
    return exists;
}

bool Library::remove_book(Book book_tbc) {
    //initialize the existence of the book to be checked to false
    bool exists = false;
    string title_tbc = book_tbc.get_title(), author_tbc = book_tbc.get_author(), dop_tbc = book_tbc.get_dop();
    //iterate through library vector to identify whether the book to be checked exists
    for (int i = 0; i < my_library.size() && !exists; i++) {
        exists = title_tbc == my_library[i].get_title();
        exists = exists && author_tbc == my_library[i].get_author();
        exists = exists && dop_tbc == my_library[i].get_dop();
        //if matching attributes are found, then erase the element
        if (exists) {
            my_library.erase (my_library.begin()+i);
            break;
        }
    }
    return exists;
}

//accesor methods for member attributes
vector<Book> Library::get_my_library() {
    return my_library;
}
