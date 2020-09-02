#ifndef LRU_H
#define LRU_H
#include<map>
#include<string>

/*
O(1) LRU
Reference Book 1, 2.8
*/


class LRU {
    struct node {
        int data;
        std::string key;
        node *next;
        node *prev;
    };

    private:
       std::map<std::string, node*> m;
       node* head;
       node* tail;
       const int _capacity;
       int _currentLength;
    
    public:
    
    LRU(int capicity) : _capacity(capicity) {
        this->_currentLength = 0;
        head = new node();
        tail = new node();
        head->next = this->tail;
        head->prev = nullptr;
        tail->prev = this->head;
        tail->next = nullptr;
    };

    int set(std::string key, int data);
    int access(std::string key);

    void dump();

    ~LRU() {
        if(head != nullptr) {
            node* tmp = head->next;
            delete(head);
            head = tmp;
        }
    }

};




#endif