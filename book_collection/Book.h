#ifndef __BOOK_H
#define __BOOK_H
#include <string>
using namespace std;
#include "Author.h"
class Book{
public:
    Book();
    Book(const string name);
    ~ Book();
    Book(const Book& bookToCopy);
    void operator=(const Book& right);
    string getName() const;
    void setName(const string bookName);
    bool addAuthor(const int id, const string name);
    bool removeAuthor (const int id);
    void displayAuthors() const;
    void getAuthor(const int id, Author &a);
private:
    struct AuthorNode {
        Author a;
        AuthorNode* next;
    };
    AuthorNode* head;
    string name;
    int numOfAuthors;
    AuthorNode* findAuthor(int id);
};
#endif
