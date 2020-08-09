#include"node.hpp"
#include <iostream>
/*
重新排列linklist
Reference Book 1, 1.4
*/

node* reverseViaLoop(node* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    
    node* prev = head;    
    node* cur = head->next;
    head->next = nullptr;

    node* ret;

    node* next;
    for(; cur != nullptr; cur = next) {
        if(cur->next == nullptr) {
           ret = cur;
        }
        next = cur->next;
        cur->next = prev;
        prev = cur;
    }
    return ret;
}


/*
用快慢指標跟計數器 快指標所指node編號(從一開始) % 2 == 0 時 慢指標進一步
如此list為奇數個時 慢指標會在中間點 為偶數個時會在後半的頭部
但慢指標在中間點 拆成兩個list時 前面的尾巴要改成指向null 這樣不好處理
所以增加一個prev存放慢指標前一節點

偶數時 orphan = null
奇數時 orphan = 中間node
拆出上下半部 把下半部間隔插入上半部 最後接上orphan
*/
node* reorder(node* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    int len = 0;
    node* curFast = head;
    node* curSlow = head;
    node* prev = head;

    while (curFast != nullptr) {
        curFast = curFast->next;
        len++;

        if(len % 2 == 0) {
            prev = curSlow;
            curSlow = curSlow->next;
        } 
    }

    if(len == 2) {
        return head;
    }

    node* headL = head;
    node* headR = len % 2 == 0 ? curSlow : curSlow->next;
    node* orphan = len % 2 == 0 ? nullptr : curSlow;

    //切開
    prev->next = nullptr;
    
    if(orphan != nullptr) {
        orphan->next = nullptr;
    }

    //將右端逆序
    headR = reverseViaLoop(headR);


    //插入
    node* curL = headL;
    node* curR = headR;

    while(curL != nullptr) {
        node* nextL = curL->next;
        node* nextR = curR->next;
        curL->next = curR;
        curR->next = nextL;
        prev = curR;
        curR = nextR;
        curL = nextL;
    }
    prev->next = orphan;
    return headL;

}

int main() {
    int arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    showList(reorder(initViaArray(arr1, 10)));
    showList(reorder(initViaArray(arr1, 9)));
    return 0;
}