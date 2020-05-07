#include <string>
using namespace std;
#include "Book.h"
class Genre {
public:
    Genre(const string gname = "");
    ~Genre ();
    Genre (const Genre &genreToCopy);
    void operator=(const Genre &right);
    bool addBook(string bName);
    bool removeBook(string name);
    string getGenreName() const;
    void setGenreName(const string gName);
    void displayBooks();
    void addAuthor(const string bName, const string aName,int id);
    void removeAuthor(const string bName, int id);
    void displayAuthor(const int id);
private:
    struct BookNode{
        Book b;
        BookNode* next;
    };
    string genreName;
    BookNode* head;
    BookNode* findBook(string bName);
};