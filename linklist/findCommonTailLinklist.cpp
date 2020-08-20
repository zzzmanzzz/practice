#include"node.hpp"


bool hasCommonTail(node* head1, node* head2) {
    if(head1 == nullptr || head2 == nullptr || head1 == head2) {
        return false;
    }

    node* cur1 = head1;
    node* cur2 = head2;

    while(cur1->next != nullptr) {
        cur1 = cur1->next;
    }

    while(cur2->next != nullptr) {
        cur2 = cur2->next;
    }

    return cur1 == cur2 ? true : false; 
}

int main() {

    int arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[] = {6, 7, 8, 9};
    std::vector<node*> twoHeads = initCommonTailList(arr1, arr2, 10, 4, 1);

    showList(twoHeads[0]);
    showList(twoHeads[1]);

    std::cout << hasCommonTail(twoHeads[0], twoHeads[1]);

    return 0;
}