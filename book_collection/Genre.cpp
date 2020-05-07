//
// Created by LENOVO on 12/6/2019.
//

#include <iostream>
#include "Genre.h"

Genre::Genre(string gname) {
    genreName = gname;
    head = NULL;
}

Genre::~Genre() {
    BookNode* curr = head;
    while(curr != NULL){
        curr = curr->next;
        head->next = NULL;
        delete head;
        head = NULL;
    }
}

Genre :: Genre(const Genre &genreToCopy) {
    if(genreToCopy.head == NULL){
        head = NULL;
    }
    else{
        head = new BookNode;
        head->b = genreToCopy.head->b;
        BookNode *curr = head;
        for(BookNode* origPtr = genreToCopy.head->next;
            origPtr != NULL; origPtr = origPtr->next){
            curr->next =  new BookNode;
            curr = curr->next;
            curr->b = origPtr->b;
        }
        curr->next = NULL;
    }
}

void Genre::operator=(const Genre &right) {
    if(right.head == NULL){
        head = NULL;
    }
    else{
        head = new BookNode;
        head->b = right.head->b;
        BookNode *curr = head;
        for(BookNode* origPtr = right.head->next;
            origPtr != NULL; origPtr = origPtr->next){
            curr->next =  new BookNode;
            curr = curr->next;
            curr->b = origPtr->b;
        }
        curr->next = NULL;
    }
}

bool Genre::addBook(string bName) {
    if(findBook(bName) == NULL){
        BookNode* newNode = new BookNode;
        newNode->b.setName(bName);
        newNode->next = head;
        head = newNode;
        return true;
    }
    cout<<"This book already exists"<<endl;
    return false;
}

bool Genre::removeBook(string name) {
    if(findBook(name) == NULL){
        cout<<"Book does not exist"<<endl;
        return false;
    }
    if( head == NULL){
        cout<<"Book does not exist"<<endl;
        return false;
    }
    if(head->b.getName() == name){
        BookNode*temp = head;
        head = head->next;
        temp->next =NULL;
        delete temp;
        temp = NULL;
        return true;
    }
    BookNode *prev = head;
    for(BookNode* curr = head->next; curr != NULL; curr = curr->next){
        if(curr->b.getName() == name){
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
            curr = NULL;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    cout<<"Book does not exist"<<endl;
    return false;
}

string Genre::getGenreName() const {
    return genreName;
}

void Genre::setGenreName(const string gName) {
    genreName = gName;
}

void Genre::displayBooks() {
    if(head == NULL){
        return;
    }
    for(BookNode *curr = head; curr != NULL; curr = curr->next){
        cout<<curr->b.getName()<<endl;
        curr->b.displayAuthors();
    }
}

Genre::BookNode *Genre::findBook(string bName) {
    if(head == NULL){
        return NULL;
    }

    for(BookNode *curr = head; curr != NULL; curr = curr->next){
        if(curr->b.getName() == bName){
            return curr;
        }
    }

    return NULL;
}

void Genre::addAuthor(const string bName, const string aName, int id) {
    if(findBook(bName) ==  NULL){
        cout<<"book does not exists"<<endl;
        return;
    }
    BookNode* node = findBook(bName);
    node->b.addAuthor(id, aName);
    return;
}

void Genre::removeAuthor(const string bName,  int id) {
    if(findBook(bName) ==  NULL){
        cout<<"Book does not exists"<<endl;
        return;
    }
    if(head ==  NULL){
        return;
    }
    BookNode *node = findBook(bName);
    node->b.removeAuthor(id);
    return;
}
void Genre ::displayAuthor(const int id) {
    Author a;
    if(head == NULL){
        return;
    }
    for(BookNode *curr = head; curr != NULL; curr = curr->next){
        curr->b.getAuthor(id, a);
        if(a.getID()== id){
            cout<<curr->b.getName()<<endl;
        }
    }
}
