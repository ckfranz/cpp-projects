#include "a5_book.hpp"

//Parametric constructor with all attributes specified
Book::Book(string new_title, string new_authors, string new_dop) :
    title(new_title),
    author(new_authors),
    dop(new_dop) {}

//Parametric constructor with only title and author specified
Book::Book(string new_title, string new_authors) :
    title(new_title),
    author(new_authors),
    dop("N/A") {}
    
//Parametric constructor with only title specified
Book::Book(string new_title) :
    title(new_title),
    author("N/A"),
    dop("N/A") {}
    
//Parametric constructor with no attributes specified
Book::Book() :
    title("N/A"),
    author("N/A"),
    dop("N/A") {}

//output the book attributes
void Book::print() {
    cout << title << " "
        << author << " "
        << dop << endl;
}

//accesor methods for member attributes
string Book::get_title() {
    return title;
}
string Book::get_author() {
    return author;
}
string Book::get_dop() {
    return dop;
}

