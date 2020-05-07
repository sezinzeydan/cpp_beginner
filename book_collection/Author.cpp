//
// Created by LENOVO on 12/6/2019.
//

#include "Author.h"
Author :: Author(){
    name = "";
    id = 0;
}
Author :: Author(const int id, const string name){
    this->name = name;
    this->id = id;
}

void Author :: operator=(const Author& right){
    name = right.name;
    id = right.id;
}

int Author :: getID() const{
    return id;
}
void Author :: setID(const int id){
    this->id = id;
}
string Author :: getName() const{
    return name;
}
void Author :: setName(const string id){
    name = id;
}