#include <iostream>
#include "Book.h"

Book :: Book(){
    head = NULL;
    name = "";
    numOfAuthors = 0;
}

Book :: Book(const string name){
    head = NULL;
    this->name = name;
    numOfAuthors = 0;
}

Book :: ~Book(){
    AuthorNode* curr = head;
    while(curr != NULL){
        curr = curr->next;
        head->next = NULL;
        delete head;
        head = NULL;
        numOfAuthors--;
    }
}

Book :: Book(const Book& bookToCopy){
    numOfAuthors = bookToCopy.numOfAuthors;
    if(numOfAuthors != 0){
        head = new AuthorNode;
        head->a = bookToCopy.head->a;
        AuthorNode *curr = bookToCopy.head->next;
        AuthorNode* temp = head;

        while(curr != NULL){
            temp->next = new AuthorNode;
            temp = temp->next;
            temp->a = curr->a;
            curr = curr->next;
        }
        temp->next = NULL;
    }
    else{
        head = NULL;
    }
}

void Book :: operator=(const Book& right){
    numOfAuthors = right.numOfAuthors;
    if(numOfAuthors != 0){
        head = new AuthorNode;
        head->a = right.head->a;
        AuthorNode *curr = right.head->next;
        AuthorNode* temp = head;

        while(curr != NULL){
            temp->next = new AuthorNode;
            temp = temp->next;
            temp->a = curr->a;
            curr = curr->next;
        }
        temp->next = NULL;
    }
    else{
        head = NULL;
    }
}

string Book :: getName() const{
    return name;
}

void Book :: setName(const string bookName){
    name = bookName;
}

bool Book :: addAuthor(const int id, const string n2ame){
    if(findAuthor(id) == NULL){
        AuthorNode*temp = new AuthorNode;
        temp->a.setID(id);
        temp->a.setName(n2ame);
        temp->next = head;
        head = temp;
        numOfAuthors++;
        return true;
    }
    else{
        return false;
    }
}


bool Book :: removeAuthor (const int id){
    if(numOfAuthors == 0 ){
        return false;
    }
    AuthorNode *curr = head;
    AuthorNode *prev;
    if(head->a.getID() == id){
        AuthorNode*temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
    }
    curr= head->next;
    prev= head;
    while(curr != NULL){
        if(curr->a.getID() == id){
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
            numOfAuthors--;
            curr = NULL;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}
void Book :: displayAuthors() const{
    AuthorNode* curr =head;
    if(head == NULL){
        cout<<"--EMPTY--"<<endl;
    }
    while(curr != NULL){
        cout<<"Author ID "<<curr->a.getID()<<",Author "<<curr->a.getName()<<endl;
        curr = curr->next;
    }
}
Book :: AuthorNode* Book :: findAuthor(int id){
    for(AuthorNode *curr = head; curr != NULL; curr = curr->next){
        if(curr->a.getID() == id){
            return curr;
        }
    }
    return NULL;
}

void Book :: getAuthor(const int id, Author &a) {
    if(head == NULL){
        return;
    }
    for(AuthorNode *curr = head; curr != NULL; curr = curr->next){
        if(curr->a.getID() == id){
            a = curr->a;
        }
        else{
            a.setID(0);
        }
    }

}