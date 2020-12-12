#include"LRU.hpp"
#include<iostream>
#include<string>
#include<map>

#include<iostream>

int LRU::set(std::string key, int data) {
    if(this->_currentLength >= this->_capacity ) {
        node* tobeDelete = this->tail->prev;
        this->m.erase(tobeDelete->key);
        node* tmp = tobeDelete->prev; 
        delete(tobeDelete);

        this->tail->prev = tmp;
        tmp->next = this->tail;
    }

    node* addr = new node();

    addr->data = data;
    addr->key = key;
  
    addr->prev = this->head;
    addr->next = this->head->next;

    addr->next->prev = addr;
    this->head->next = addr;

    this->m[key] = addr;

    this->_currentLength++;
    return this->_currentLength;
}

int LRU::access(std::string key) {
    int ret;
    if(this->m.find(key) != this->m.end()) {
        node* addr = this->m[key];

        ret = addr->data;
     
        node *prev = addr->prev;
        node *next = addr->next;

        prev->next = next;
        next->prev = prev;

        addr->prev = this->head;
        addr->next = this->head->next;
        addr->next->prev = addr;
        this->head->next = addr;

    } else {
        throw "cache loss";
    }
    return ret;
}

void LRU::dump() {
   for(auto elem : this->m) {
       std::cout << elem.first << " -> " << elem.second << "\n";
   }

   node* cur = this->head->next;
   while(cur != this->tail) {
       std::cout << cur->data << ", ";
       cur = cur->next;
   }
   
}


