/*SYDE121
 a5_main.cpp
 Assignment 5
 10/30/20
 Curtis Franz & Tiffany Ngai

 The purpose of the program is to model libraries and books.

 Verification/testing:
 This program was tested thoughoutly as evident in the code below. Testing was
 separated into four functions to test the book constructor, library constructor,
 and book insertion and book removal methods. Test cases were implemented to verify
 functionality of default and parametric constructors. Test cases were also implemented
 to verify book insertion and book removal methods where; (a) the title, authors, and
 date of publication are provided as string values and (b) book instance is passed by
 value.

 Limitations to this program:
 1. Only the title, author and date of publication are avaliable as book attributes
 2. Only books are included as Library attributes

*/
#include <iostream>
#include <cassert>
#include <vector>
#include "a5_book.hpp"
#include "a5_library.hpp"

using namespace std;

//PURPOSE: to test book constructors
void test_book_constructor() {
    cout << "Test Book Constructor:" << endl;
    //Test case 1
    //check if book instance can be created with all attributes
    Book book_testing1("Harry Potter", "JK Rowling", "07/2005");
    book_testing1.print();
    //Expected result:
    //Harry Potter JK Rowling 07/2005
    //The output indeed verfies the result we expect
    
    //Test case 2
    //check if book instance can be created with only title and author attributes
    Book book_testing2("Dune", "Frank Herbert");
    book_testing2.print();
    //Expected result:
    //Dune Frank Herbert N/A
    //The output indeed verfies the result we expect
    
    //Test case 3
    //check if book instance can be created with only title attributes
    Book book_testing3("Sherlock Holmes");
    book_testing3.print();
    //Expected result:
    //Sherlock Holmes N/A N/A
    //The output indeed verfies the result we expect
    
    //Test case 4
    //check if the default constructor works
    Book book_testing4;
    book_testing4.print();
    //Expected result:
    //N/A N/A N/A
    //The output indeed verfies the result we expect
}

//PURPOSE: to test library constructors
void test_library_constructor() {
    cout << "\nTest Library Constructor:" << endl;
    //declare and initialize variables
    Book book_testing1("Harry Potter", "JK Rowling", "07/2005");
    Book book_testing2("Dune", "Frank Herbert", "08/1965");
    Book book_testing3("Sherlock Holmes", "Arthur Conan Doyle", "10/1892");
    vector<Book> testing_vector1 = {book_testing1, book_testing2};
    vector<Book> testing_vector2 = {book_testing1, book_testing3};
    
    cout << "\nTest 1:" << endl;
    //Test case 1: check if the parametric constructor works
    Library testing_library1(testing_vector1);
    testing_library1.print();
    //Expected result:
    //Details for book number 0: Harry Potter JK Rowling 07/2005
    //Details for book number 1: Dune Frank Herbert 08/1965
    //The output indeed verfies the result we expect
    
    cout << "\nTest 2:" << endl;
    //Test case 1: check if the parametric constructor works
    Library testing_library2(testing_vector2);
    testing_library2.print();
    //Expected result:
    //Details for book number 0: Harry Potter JK Rowling 07/2005
    //Details for book number 1: Sherlock Holmes Arthur Conan Doyle 10/1892
    //The output indeed verfies the result we expect
    
    cout << "\nTest 3:" << endl;
    //Test case 1: check if the default constructor works
    Library testing_library3;
    testing_library3.print();
    //Expected result: *nothing*
    //The output indeed verfies the result we expect
}

//test insertion function
void test_book_insertion() {
    //declare and initialize variables
    Book book_testing1("Harry Potter", "JK Rowling", "07/2005");
    Book book_testing2("Dune", "Frank Herbert", "08/1965");
    Book book_testing3("The Fellowship of the Ring", "Tolkein", "09/1954");
    Book book_testing4("Harry Potter", "JK Rowling", "07/2005");
    Book book_testing5("Sherlock Holmes", "Arthur Conan Doyle", "10/1892");
    Book book_testing6("The Two Towers", "Tolkein", "09/1954"); //Publication dated changed for testing purposes
    vector<Book> testing_vector1 = {book_testing1, book_testing2, book_testing3};
    Library library_testing1(testing_vector1);
    Library library_testing2(testing_vector1);
    
    cout << "\nTest Book Insertion:" << endl;
    //Testing for Library::insertion_book(Book book_tbc)
    cout << "Test 1:" << endl;
    //Test case 1: test if the insertion will fail if the details of the book are the same
    cout << library_testing1.insertion_book(book_testing4) << endl;
    library_testing1.print();
    //Expected result:
    //0
    //Details for book number 0: Harry Potter JK Rowling 07/2005
    //Details for book number 1: Dune Frank Herbert 08/1965
    //Details for book number 2: The Fellowship of the Ring Tolkein 09/1954
    //The output indeed verfies the result we expect
    
    //Test case 2: test if the insertion will succeed if the details of the book are completely different
    cout << library_testing1.insertion_book(book_testing5) << endl;
    library_testing1.print();
    //Expected result:
    //1
    //Details for book number 0: Harry Potter JK Rowling 07/2005
    //Details for book number 1: Dune Frank Herbert 08/1965
    //Details for book number 2: The Fellowship of the Ring Tolkein 09/1954
    //Details for book number 3: Sherlock Holmes Arthur Conan Doyle 10/1892
    //The output indeed verfies the result we expect
    
    //Test case 3: test if the insertion will succeed if the details of the book are slightly different
    cout << library_testing1.insertion_book(book_testing6) << endl;
    library_testing1.print();
    //Expected result:
    //1
    //Details for book number 0: Harry Potter JK Rowling 07/2005
    //Details for book number 1: Dune Frank Herbert 08/1965
    //Details for book number 2: The Fellowship of the Ring Tolkein 09/1954
    //Details for book number 3: Sherlock Holmes Arthur Conan Doyle 10/1892
    //Details for book number 4: The Two Towers Tolkein 09/1954
    //The output indeed verfies the result we expect
    
    //Testing for Library::insertion_string(string title_tbc, string author_tbc, string dop_tbc)
    cout << "\nTest 2:" << endl;
    //Test case 1: test if the insertion will fail if the details of the book are the same
    cout << library_testing2.insertion_string("Dune", "Frank Herbert", "08/1965") << endl;
    library_testing2.print();
    //Expected result:
    //0
    //Details for book number 0: Harry Potter JK Rowling 07/2005
    //Details for book number 1: Dune Frank Herbert 08/1965
    //Details for book number 2: The Fellowship of the Ring Tolkein 09/1954
    //The output indeed verfies the result we expect
    
    //Test case 2: test if the insertion will succeed if the details of the book are completely different
    cout << library_testing2.insertion_string("Moby-Dick", "Herman Melville", "-/1851") << endl;
    library_testing2.print();
    //Expected result:
    //1
    //Details for book number 0: Harry Potter JK Rowling 07/2005
    //Details for book number 1: Dune Frank Herbert 08/1965
    //Details for book number 2: The Fellowship of the Ring Tolkein 09/1954
    //Details for book number 3: Moby-Dick Herman Melville -/1851
    //The output indeed verfies the result we expect
    
    //Test case 3: test if the insertion will succeed if the details of the book are slightly different
    cout << library_testing2.insertion_string("The Fellowship of the Ring", "Tolkein", "12/2001") << endl;
    library_testing2.print();
    //Expected result:
    //1
    //Details for book number 0: Harry Potter JK Rowling 07/2005
    //Details for book number 1: Dune Frank Herbert 08/1965
    //Details for book number 2: The Fellowship of the Ring Tolkein 09/1954
    //Details for book number 3: Moby-Dick Herman Melville -/1851
    //Details for book number 4: The Fellowship of the Ring Tolkein 12/2001
    //The output indeed verfies the result we expect
}

//test insertion function
void test_book_removal() {
    cout << "\nTest Book Removal:" << endl;
    //declare and initialize variables
    Book book_testing1("The Fellowship of the Ring", "Tolkein", "09/1954");
    Book book_testing2("The Two Towers", "Tolkein", "09/1954");
    Book book_testing3("Harry Potter", "JK Rowling", "07/2005");
    Book book_testing4("Sherlock Holmes", "Arthur Conan Doyle", "10/1892");
    Book book_testing5("Dune", "Frank Herbert", "08/1965"); //Publication dated changed for testing purposes
    vector<Book> testing_vector1 = {book_testing1, book_testing2, book_testing3};
    Library library_testing1(testing_vector1);
    Library library_testing2(testing_vector1);
    
    //Testing for Library::insertion_book(Book book_tbc)
    cout << "Test 1:" << endl;
    //Test case 1: test if the removal will fail if a book is not found
    cout << library_testing1.remove_book(book_testing5) << endl;
    library_testing1.print();
    //Expected result:
    //0
    //Details for book number 0: The Fellowship of the Ring Tolkein 09/1954
    //Details for book number 1: The Two Towers Tolkein 09/1954
    //Details for book number 2: Harry Potter JK Rowling 07/2005
    //The output indeed verfies the result we expect
    
    //Test case 2: test if the removal will succeed if a book is found
    cout << library_testing1.remove_book(book_testing3) << endl;
    library_testing1.print();
    //Expected result:
    //1
    //Details for book number 0: The Fellowship of the Ring Tolkein 09/1954
    //Details for book number 1: The Two Towers Tolkein 09/1954
    //The output indeed verfies the result we expect
    
    //Test case 3: test if the removal of an inserted book will succeed
    cout << library_testing1.insertion_book(book_testing4) << endl;
    library_testing1.print();
    cout << library_testing1.remove_book(book_testing4) << endl;
    library_testing1.print();
    //Expected result:
    //1
    //Details for book number 0: The Fellowship of the Ring Tolkein 09/1954
    //Details for book number 1: The Two Towers Tolkein 09/1954
    //1
    //Details for book number 0: The Fellowship of the Ring Tolkein 09/1954
    //Details for book number 1: The Two Towers Tolkein 09/1954
    //The output indeed verfies the result we expect
    
    //Test case 4: test if the removal of a book that shares common attributes
    //               with another will succeed
    cout << library_testing1.remove_book(book_testing1) << endl;
    library_testing1.print();
    //Expected result:
    //1
    //Details for book number 0: The Fellowship of the Ring Tolkein 09/1954
    //The output indeed verfies the result we expect
    
    //Testing for Library::insertion_string(string title_tbc, string author_tbc, string dop_tbc)
    cout << "\nTest 2:" << endl;
    //Test case 1: test if the removal will fail if a book is not found
    cout << library_testing2.remove_string("Dune", "Frank Herbert", "08/1965") << endl;
    library_testing2.print();
    //Expected result:
    //0
    //Details for book number 0: The Fellowship of the Ring Tolkein 09/1954
    //Details for book number 1: The Two Towers Tolkein 09/1954
    //Details for book number 2: Harry Potter JK Rowling 07/2005
    //The output indeed verfies the result we expect
    
    //Test case 2: test if the removal will succeed if a book is found
    cout << library_testing2.remove_string("Harry Potter", "JK Rowling", "07/2005") << endl;
    library_testing2.print();
    //Expected result:
    //1
    //Details for book number 0: The Fellowship of the Ring Tolkein 09/1954
    //Details for book number 1: The Two Towers Tolkein 09/1954
    //The output indeed verfies the result we expect
    
    //Test case 3: test if the removal of an inserted book will succeed
    cout << library_testing2.insertion_string("Sherlock Holmes", "Arthur Conan Doyle", "10/1892") << endl;
    library_testing2.print();
    cout << library_testing2.remove_string("Sherlock Holmes", "Arthur Conan Doyle", "10/1892") << endl;
    library_testing2.print();
    //Expected result:
    //1
    //Details for book number 0: The Fellowship of the Ring Tolkein 09/1954
    //Details for book number 1: The Two Towers Tolkein 09/1954
    //1
    //Details for book number 0: The Fellowship of the Ring Tolkein 09/1954
    //Details for book number 1: The Two Towers Tolkein 09/1954
    //The output indeed verfies the result we expect
    
    //Test case 4: test if the removal of a book that shares common attributes
    //               with another will succeed
    cout << library_testing2.remove_string("The Two Towers", "Tolkein", "09/1954") << endl;
    library_testing2.print();
    //Expected result:
    //1
    //Details for book number 0: The Fellowship of the Ring Tolkein 09/1954
    //The output indeed verfies the result we expect
}

void execute_tests() {
    test_book_constructor();
    test_library_constructor();
    test_book_insertion();
    test_book_removal();
}

int main() {
    execute_tests();
    return 0;
}
