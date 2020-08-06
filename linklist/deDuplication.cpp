#include "node.hpp"
#include<set>
/*
  Link list去除重複問題
  Reference Book 1, 1.2  
*/

void removeViaLoop(node* head) {
  if(head == nullptr || head->next == nullptr) {
    return;
  }

  for(node* check = head; check != nullptr ; check = check->next) {
    int tmp = check->data;
    node* cur = check->next;
    node* prev = check;
    while(cur != nullptr) {
      if(cur->data == tmp) {
        node* next = cur->next;
        prev->next = next;
        delete(cur);
        cur = next;
        continue;
      }
      prev = cur;
      cur = cur->next;
    }
  }
}

void removeViaSet(node* head) {
  if(head == nullptr || head->next == nullptr) {
    return;
  }

  std::set<int> dedup;
  dedup.insert(head->data);
  node* cur = head->next;
  node* prev = head;
  
  while(cur != nullptr) {
    if(dedup.find(cur->data) != dedup.end()) {
        node* next = cur->next;
        prev->next = next;
        delete(cur);
        cur = next;
        continue;
    }
    dedup.insert(cur->data);
    prev = cur;
    cur = cur->next;
  }
}


int main() {
   node* head = initWithDuplicate();
    showList(head);
    removeViaSet(head);
    showList(head);
    return 0;
}