#include"node.hpp"
#include<iostream>

/*
merge兩個有序link list
Reference Book 1, 1.9
*/

node* append(node* cur, node* appendee) {
    cur->next = appendee;
    appendee->next = nullptr;
    return cur->next;
}

node* merge(node* left, node* right) {

    if(left == nullptr) {
        return right;
    }

    if(right == nullptr) {
        return left;
    }

    node* dummyHead = new node();
    node* cur = dummyHead;
    node* smallCur = left; // current element is small
    node* bigCur = right; // current element is large

    while(smallCur != nullptr || bigCur != nullptr) {
        if(smallCur == nullptr) {
            node* tmp = bigCur;
            smallCur = tmp;
            bigCur = nullptr;
        } else if(bigCur == nullptr) {
            // pointer is correct do nothing
            // smallCur = smallCur;
            // bigCur = nullptr;
        } else {        
            node* tmp;
           // std::cout<< smallCur->data << ", ";
            if(smallCur->data < bigCur->data) {
                //pointer is correct do nothing
            } else {
                node* tmp = smallCur;
                smallCur = bigCur;
                bigCur = tmp;
            }
        } 
        // always append smallCur
        node* tmp = smallCur;
        smallCur = smallCur->next;
        cur = append(cur, tmp);
    }
    node* ret = dummyHead->next;
    delete(dummyHead);
    return ret;

}



int main() {
    int arr1[] = {1, 4, 6, 7, 8};
    int arr2[] = {-10, -5, 5, 10, 15};
    node* head1 = initViaArray(arr1, 5);
    node* head2 = initViaArray(arr2, 5);

    showList(head1);
    showList(head2);
    showList(merge(head1, head2));

    return 0;
}