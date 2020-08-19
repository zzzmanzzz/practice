#include"node.hpp"

int main() {

    int arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[] = {6, 7, 8, 9};
     std::vector<node*> twoHeads = initCommonTailList(arr1, arr2, 10, 4, 1);

     showList(twoHeads[0]);
     showList(twoHeads[1]);


    return 0;
}