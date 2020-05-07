//
// Created by LENOVO on 12/6/2019.
//

#include <iostream>
#include "BookCollection.h"

BookCollection::BookCollection() {
    head = NULL;
    genreCount = 0;
}

BookCollection::~BookCollection() {
    while(head != NULL){
        GenreNode* curr = head;
        head = head->next;
        curr->next = NULL;
        delete curr;
        curr = NULL;
    }
}

BookCollection::BookCollection(const BookCollection &bcToCopy) {
    genreCount = bcToCopy.genreCount;
    if(bcToCopy.genreCount == 0){
        head = NULL;
    }
    else{
        head = new GenreNode;
        head->g = bcToCopy.head->g;
        GenreNode*curr = head;
        for(GenreNode* origPtr = bcToCopy.head->next;
            origPtr != NULL; origPtr = origPtr->next){
            curr->next = new GenreNode;
            curr = curr->next;
            curr->g = origPtr->g;
        }
        curr->next = NULL;
    }
}

void BookCollection::operator=(const BookCollection &right) {
    genreCount = right.genreCount;
    if(right.genreCount == 0){
        head = NULL;
    }
    else{
        head = new GenreNode;
        head->g = right.head->g;
        GenreNode*curr = head;
        for(GenreNode* origPtr = right.head->next;
            origPtr != NULL; origPtr = origPtr->next){
            curr->next = new GenreNode;
            curr = curr->next;
            curr->g = origPtr->g;
        }
        curr->next = NULL;
    }
}

void BookCollection::addGenre(string genreName) {
    if(findGenre(genreName) == NULL){
        genreCount++;
        GenreNode *newNode;
        newNode = new GenreNode;
        newNode->g.setGenreName(genreName);
        newNode->next = head;
        head = newNode;
    }
}

void BookCollection::removeGenre(string genreName) {
    if(findGenre(genreName) == NULL){
        cout<<"Specified genre does not exist"<<endl;
        return;
    }

    if(head == NULL){
        cout<<"Genre list is empty."<<endl;
        return;
    }

    if(head->g.getGenreName() == genreName){
        GenreNode *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        temp = NULL;
        genreCount--;
        return;
    }
    GenreNode *prev = head;
    for(GenreNode*deleted = head->next; deleted != NULL;
        deleted = deleted->next){
        if(deleted->g.getGenreName() == genreName){
            prev->next = deleted->next;
            deleted->next =NULL;
            delete deleted;
            deleted = NULL;
            genreCount--;
            return;
        }
        prev = deleted;
    }
}

void BookCollection::displayAllGenres() const {
    if(head == NULL){
        cout<<"--EMPTY--"<<endl;
    }
    else{
        for (GenreNode *curr = head; curr != NULL; curr = curr->next) {
            cout << "Genre " << curr->g.getGenreName() << endl;
        }
    }
}

void BookCollection::addBook(string genreName, string bookName) {
    if(findGenre(genreName) == NULL){
        cout<<"This genre does not exist"<<endl;
        return;
    }
    GenreNode* genre = findGenre(genreName);
    genre->g.addBook(bookName);
    return;
}

void BookCollection::removeBook(string genreName, string bookName) {
    if(findGenre(genreName) == NULL){
        cout<<"This genre does not exist"<<endl;
        return;
    }
    if(head == NULL){
        cout<<"This genre does not exist"<<endl;
        return;
    }
    GenreNode* deleteNode = findGenre(genreName);
    deleteNode->g.removeBook(bookName);
    return;
}

void BookCollection::addAuthor(string genreName, string bookName, int authorID, string authorName) {
    if(findGenre(genreName) == NULL){
        cout<<"Genre does not exists."<<endl;
        return;
    }
    GenreNode *curr = findGenre(genreName) ;
    curr->g.addAuthor(bookName,authorName,authorID);
    return;
}

void BookCollection::removeAuthor(string genreName, string bookName, int authorID) {
    if(findGenre(genreName) == NULL){
        cout<<"Genre does not exists."<<endl;
        return;
    }
    if(head == NULL){
        return;
    }
    GenreNode *curr = findGenre(genreName);
    curr->g.removeAuthor(bookName,authorID);
    return;
}

void BookCollection::displayGenre(string genreName) {
    if(head ==  NULL){
        cout<<"--EMPTY--"<<endl;
        return;
    }
    GenreNode *curr = findGenre(genreName);
    cout<<genreName<<endl;
    curr->g.displayBooks();
}

void BookCollection::displayAuthor(int authorID) {
    if(head == NULL){
        return;
    }
    for(GenreNode* curr = head; curr != NULL; curr = curr->next){
        cout<<"Genre "<<curr->g.getGenreName()<<endl;
        curr->g.displayAuthor(authorID);
    }

}

BookCollection::GenreNode *BookCollection::findGenre(string genreName) {
    if(head == NULL){
        return NULL;
    }
    for(GenreNode* curr = head; curr != NULL; curr = curr->next){
        if(curr->g.getGenreName() == genreName){
            return curr;
        }
    }
    return NULL;
}
