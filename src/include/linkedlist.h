#ifndef linkedlist_h
#define linkedlist_h

struct node
{
    int data;
    struct node* next;
};

struct node* createNode(int newdata);
void insertNode(struct node** headRef, int newData);
void deleteNode(struct node** headRef, int cle);
void displayList(struct node* head);

#endif