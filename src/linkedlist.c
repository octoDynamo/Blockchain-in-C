#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"


struct node* createNode(int newdata){
	struct node* newNode = (struct node*)malloc(sizeof( struct node ));
	newNode -> data=newdata;
	newNode -> next=NULL;
	return newNode;
}

void insertNode(struct node** headRef, int newData) {
    struct node* newNode = createNode(newData);
    if (newNode != NULL) {
        newNode->next = *headRef;
        *headRef = newNode;
    }
}

void deleteNode(struct node** headRef, int cle){
	struct node *temp = *headRef, *prev;
	if (temp != NULL && temp->data == cle) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != cle) {
        prev = temp;
        temp = temp->next;
        if (temp == NULL) {
        	printf("Key not found in the list!\n");
        	return;
    	}
    } 
    prev->next = temp->next;
    free(temp);
}

void displayList(struct node* head) {
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp ->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
    return 0;
}