#include "node.hpp"
#include<iostream>
#include<set>
/*
檢查linklist是否存在環, 若有則回傳入口node
1->2->3->4---|
      ^      |
      |------|
Reference Book 1, 1.6
*/

node* checkLoopBySet(node* head) {
    if(head == nullptr) {
        return head;
    }

    std::set<node*> addr;
    node* cur = head;
    node* ret = nullptr;
    while(cur != nullptr) {
        if(addr.find(cur) != addr.end()) {
            ret = cur;
            break;
        }
        addr.insert(cur);
        cur = cur->next;
    }
    return ret;
}
/*
1, 先用快慢pointer, 快的一次進兩步, 慢的一次一步. 若有環則必然會走某處相遇
2, 若遇到了, 設慢的走了s步, 快的則因為一次兩步所以走了2s步
3, 因為快的至少走完一次環才會碰到慢的所以有以下關係 2s = s + nr 
   n為走了幾次環(n>=1) r為環長 所以s = nr 
4, 將一個指標設定在head, 另一個指標設定在相遇點 兩者都是一步一步前進
   當兩個碰到時就是環入口
5, 說明: 設環入口走下半圓到相遇點的距離為d 當初如果快指標從相遇點走了nr - d那就會停在環入口
   又慢指標如果走了s - d 也會停在環入口 因為nr = s 所以一個從相遇點出發 一個從頭出發 剛好會在入口碰到
*/
node* floydLoopCheck(node* head) {
    node* meet = nullptr;
    node* fastCur = head;
    node* slowCur = head;
    
    do {
        if(fastCur->next != nullptr) {
            fastCur = fastCur->next->next;
            slowCur = slowCur->next;
        } else {
            fastCur = nullptr;
            break;
        }
    } while(fastCur != slowCur && fastCur != nullptr );

    if(fastCur == nullptr) {
        return nullptr; // no loop
    } else if(fastCur == slowCur){
        meet = fastCur;
    } else {
        std::cout << "error" << std::endl;
        return nullptr;
    }
    node* curFromHead = head;
    node* curFromMeet = meet; 

    while(curFromHead != curFromMeet) {
        curFromMeet = curFromMeet->next;
        curFromHead = curFromHead->next;
    }

    return curFromMeet;
}



int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int loopIdx = 5; 
    node* loopHead = initWithLoop(arr, 10,  loopIdx);
    //node* noloopHead = initViaArray(arr, 10);

    node* meet = floydLoopCheck(loopHead);
    if(meet != nullptr) {
        std::cout << "meet at " << meet->data;
    } else {
        std::cout<<"no loop" <<std::endl;
        //showList(noloopHead);
    }
    //showList(head);
    return 0;
}