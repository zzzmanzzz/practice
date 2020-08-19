#ifndef NODE_H
#define NODE_H
#include<vector>
#include <iostream>



struct node {
    int data;
    node *next;
};

extern node* init();
extern node* initWithDuplicate();
extern node* initViaArray(int arr[], int size);
node* initWithLoop(int arr[], int size, int startIndex);
extern void showList(node* head);
extern std::vector<node*> initCommonTailList(int arr1[], int arr2[], int arr1Size, int arr2Size, int arr2pointToArr1Idx);

#endif