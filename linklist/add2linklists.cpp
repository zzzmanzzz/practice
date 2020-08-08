/*
相加兩個link list
Reference Book 1, 1.3
*/
#include "node.hpp"

node* add(node* var1, node* var2) {
    if(var1 == nullptr) {
        return var2;
    }

    if(var2 == nullptr) {
        return var1;
    }

    node* dummyHead = new node();
    node* cur1 = var1;
    node* cur2 = var2;
    node* curSum = dummyHead;
    int carry = 0;

    while(true) {
        int cur1Data = 0;
        int cur2Data = 0; 

        if(cur2 == nullptr && cur1 == nullptr) {
            if(carry > 0) {
                curSum->next = new node();
                curSum = curSum->next;
                curSum->data = carry;
            }
            curSum->next = nullptr;
            break;
        } else {
            curSum->next = new node();
            curSum = curSum->next;
            if(cur1 != nullptr) {
                cur1Data = cur1->data; 
            }
            if(cur2 != nullptr) {
                cur2Data = cur2->data; 
            }
        }

        int tmp = cur1Data + cur2Data + carry;
        curSum->data = tmp % 10;
        carry = tmp / 10;

        if(cur1 != nullptr) {
            cur1 = cur1->next;
        }

        if(cur2 != nullptr) {
            cur2 = cur2->next;
        }
    }

    node *ret = dummyHead->next;
    delete(dummyHead);
    return ret;
}

int main() {
    int arr1[] = {1, 8, 3, 7, 5, 9, 2};
    int arr2[] = {9, 7, 7};
    // 2957381 + 779 = 2958160

    node* var1 = initViaArray(arr1, 7);
    showList(var1);
    node* var2 = initViaArray(arr2, 3);
    showList(var2);
 
    showList(add(var2, var1));
}