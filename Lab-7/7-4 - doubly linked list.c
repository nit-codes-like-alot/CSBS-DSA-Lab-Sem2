//Implementing doubly linkedlist along insertion and deletion
#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *prev;
  struct node *next;
};
//Insert from front
struct node *insertbeg(struct node *head, int data){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=head;
    if(head!=NULL){
        head->prev=newnode;
    }
    return newnode;
}

//insert from end
struct node *insertend(struct node *head, int data){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    struct node *temp=head;
    if(head==NULL){
        newnode->prev=NULL;
        return newnode;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    return head;
}

//deleting from front
struct node *delbeg(struct node *head){
    if (head==NULL){
        return NULL;
    }
    struct node *temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev= NULL;
    }
    free(temp);
    return head;
}

//delete from end
struct node *delend(struct node *head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    struct node *temp=head;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    return head;
}

//display
void display(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d<->", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void main(){
    struct node *head=NULL;
    head=insertbeg(head,40);
    head=insertbeg(head,30);
    head=insertend(head,50);
    head=insertbeg(head,20);
    head=insertbeg(head,10);
    display(head);
    head=delbeg(head);
    display(head);
}
