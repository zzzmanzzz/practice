#ifndef NODE_H
#define NODE_H

struct node {
    int data;
    node *next;
};

extern node* init();
extern node* initWithDuplicate();
extern node* initViaArray(int arr[], int size);
node* initWithLoop(int arr[], int size, int startIndex);
extern void showList(node* head);

#endif