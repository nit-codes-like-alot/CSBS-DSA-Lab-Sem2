// 7-2 Linked Lists - DELETING

#include <stdio.h>
#include <stdlib.h>


// ---------------------- **************** BASIC FUNCTIONS **************** ----------------------

// describing how a node is like
struct Node {
  int data;
  struct Node *next;
};

// writing a function to create a node to avoid repetation
struct Node *createnode(int val) {
  struct Node *new_node = malloc (sizeof(struct Node));
  
  if (new_node == NULL) {
    printf("Failed to create New Node!\n");
    exit(1);
  }
  
  new_node->data = val;
  new_node->next = NULL;
  
  return new_node;
}

// ---------------------- **************** INSERTING FUNCTIONS **************** ----------------------


void insert_at_front(struct Node **head, int val){
  struct Node *new_node = createnode(val);
  new_node -> next = *head;
  *head = new_node;
}

void insert_at_pos(struct Node **head, int val, int pos){
  
  struct Node *new_node = createnode(val);
  
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
  
  struct Node *new_node = createnode(val);
  
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






// ---------------------- **************** DELETING FUNCTIONS **************** ----------------------

void delete_at_front(struct Node **head) {
  
  // if the LL is empty
  if (*head == NULL) {
    printf("The Linked list is Empty! Nothing to delete.\n");
    return;
  }
  
  struct Node *temp = *head;
  *head = (*head) -> next; // assignin head to the next element, 
  // "()" is for precedence, otherwise *head->next would mean the pointer of next var
  free(temp);
  
}


void delete_at_back(struct Node **head ) {
  // if list empty
  if (*head == NULL) {
    printf("The Linked list is Empty! Nothing to delete.\n");
    return;
  }
  
  // if only one node there
  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }
  
  // the general case
  struct Node *temp = *head;
  
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  
  free(temp->next);
  temp->next = NULL;
  
}


void delete_at_pos(struct Node **head, int pos) {
  
  // if list Empty
  if (*head == NULL) {
    printf("The Linked list is Empty! Nothing to delete.\n");
    return;
  }
  
  // special case, if pos == 0, then we delete at front
  if (pos == 0) {
    delete_at_front(head); //calling the delete_at_front function
    return;
  }
  
  // the general case
  struct Node *temp = *head;
  for (int i = 0; i<pos-1; i++) { //moving temp just before the node we wanna delete.
    
    // if position entered is much bigger than the LL sizeof
    if (temp->next == NULL) {
      printf("The Linked list is not that big! The position entered is out of bounds.\n");
      return;
    }
    
    temp = temp->next;
  }
  
  // if the element we reached is the last element of LL, then we cant delete the next one so...
  if (temp->next == NULL) {
    printf("The Linked list is not that big! The position entered is out of bounds.\n");
    return;
  }
  
  // we create a new node for the node to delete cuz temp->next->next doesnt really work well
  struct Node *node_to_delete = temp->next;
  
  temp->next = node_to_delete->next;
  free(node_to_delete);
  
}

int main() {
    
    struct Node *head = NULL;

    // ------------------- Build the list first -------------------
    printf("=== Building Initial List ===\n");
    insert_at_back(&head, 10);
    insert_at_back(&head, 20);
    insert_at_back(&head, 30);
    insert_at_back(&head, 40);
    insert_at_back(&head, 50);
    
    printf("Initial List: ");
    print_list(head);

    // ------------------- Testing Deletes -------------------
    printf("\n\n=== Testing delete_at_front ===\n");
    delete_at_front(&head);
    printf("After delete_at_front: ");
    print_list(head);

    printf("\n=== Testing delete_at_back ===\n");
    delete_at_back(&head);
    printf("After delete_at_back: ");
    print_list(head);

    printf("\n=== Testing delete_at_pos ===\n");
    delete_at_pos(&head, 2);        // delete node at position 2
    printf("After delete_at_pos(2): ");
    print_list(head);

    delete_at_pos(&head, 0);        // delete at front using pos
    printf("After delete_at_pos(0): ");
    print_list(head);

    delete_at_pos(&head, 10);       // invalid position test
    delete_at_pos(&head, 5);        // another invalid position

    // Empty list test
    printf("\n=== Testing on Empty List ===\n");
    delete_at_front(&head);
    delete_at_back(&head);
    delete_at_pos(&head, 0);

    return 0;
}
