#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

//inserting from end
struct node *insertend(struct node *head,int data){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    //If the list is empty
    if(head==NULL){
        newnode->next=newnode;
        return newnode;
    }
    struct node *temp=head;
    while(temp->next != head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    
    return head;
}
//traversal
void display(struct node *head){
    struct node *temp =head;
    do{
        printf("%d->", temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("(Back to head again)\n");
}

int main(){
    struct node *head=NULL;
    head=insertend(head,10);
    head=insertend(head,20);
    head=insertend(head,30);
    head=insertend(head,40);
    head=insertend(head,50);
    
    display(head);
    return 0;
}
