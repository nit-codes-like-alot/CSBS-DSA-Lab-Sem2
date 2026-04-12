// Linked Lists

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

// making a create node function to use to again & again later on.
struct Node *create_node(int val){
  struct Node *new_node = malloc(sizeof(struct Node));
  if (new_node == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  new_node->data = val;
  new_node->next = NULL;
  
  return new_node;
}

void insert_at_front(struct Node **head, int val){
  struct Node *new_node = create_node(val);
  new_node -> next = *head;
  *head = new_node;
}

void insert_at_pos(struct Node **head, int val, int pos){
  
  struct Node *new_node = create_node(val);
  
  // if position was entered null or, linked list was empty.
  if (pos == 0 || *head == NULL) { 
    new_node->next = *head; //we assigned the initial head to new_node's next
    *head = new_node; //we assign the new head to new_node.
    return;
  }
  
  struct Node *temp = *head;
  for (int i = 0; i < pos - 1; i++) {
    if (temp -> next == NULL) break; //if pos is more than or less than LL's length, then this case will occur.
    temp = temp -> next;
  }
  
  new_node -> next = temp -> next;
  temp -> next = new_node;
}

void insert_at_back(struct Node **head, int val) {
  
  struct Node *new_node = create_node(val);
  
  if (*head == NULL) { //if list is empty, then simply insert the node at front
    *head = new_node;
    return;
  }
  
  struct Node *temp = *head; //makin a temp variable to interate the list
  while (temp->next != NULL) {
    temp = temp->next; //reaching the last element
  }
  
  temp -> next = new_node; 
  // setting the last element's next to our newly created node 
  // (notice how we already set new_node -> next = NULL so it automatically now becomes the last element.)
}

void print_list(struct Node *head) {
  
  if (head == NULL) {
    printf("The Linked List is Empty!\n");
    return;
  }
  
  printf("%d", head->data);
  head = head -> next;
  while (head != NULL){
    printf(" -> %d", head -> data);
    head = head -> next;
  }
  printf("\n");
}



int main() {
    struct Node *head = NULL;   // Start with empty list

    printf("Initial list:\n");
    print_list(head);

    // Test insert at front
    insert_at_front(&head, 10);
    insert_at_front(&head, 20);
    insert_at_front(&head, 30);
    printf("\nAfter inserting at front (30, 20, 10):\n");
    print_list(head);

    // Test insert at back
    insert_at_back(&head, 40);
    insert_at_back(&head, 50);
    printf("\nAfter inserting at back (40, 50):\n");
    print_list(head);

    // Test insert at position
    insert_at_pos(&head, 25, 2);     // insert at position 2
    insert_at_pos(&head, 5, 0);      // insert at front using pos
    insert_at_pos(&head, 99, 10);    // insert at end (pos too big)
    printf("\nAfter various insert_at_pos:\n");
    print_list(head);

    return 0;
}