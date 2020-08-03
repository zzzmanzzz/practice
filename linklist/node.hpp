#ifndef NODE_H
#define NODE_H

struct node {
    int data;
    node *next;
};

extern node* init();
extern void showList(node* head);

#endif