// Implementing a queue using 2 stacks


#include <stdio.h>
#define MAX 5
int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// if both the stacks are empty then the queue is empty.
int isEmpty(){
  if (top1 == -1 && top2 == -1){
    return 1;
  }
  return 0;
}

// if the first stack is full then the queue is full.
int isFull(){
  if (top1 == MAX -1){
    return 1;
  }
  return 0;
}

void Enqueue(int val){
  if (isFull()){
    printf("Queue is Full!\n");
    return;
  }
  
  stack1[++top1] = val;
  printf("%d was Enqueued!\n", val);
  
}

void Dequeue(){
  if (isEmpty()){
    printf("Queue is Empty!\n");
    return;
  }
  
  if (top2 == -1){ //only run the loop if stack2 is empty --> reducing the Dequeue complexity to O(n)
    while (top1 != -1){
      stack2[++top2] = stack1[top1--]; //putting the top of stack1's element at the bottom of stack 2, hence making it FIFO (like QUEUE)
    }
    printf("The Dequeued Element is : %d\n", stack2[top2--]);
    return;
  }
  
  printf("The Dequeued Element is : %d\n", stack2[top2--]);
  return;
}



int main()
{

  Enqueue(1);
  Enqueue(2);
  Enqueue(3);
  
  Dequeue();
  Dequeue();
  Dequeue();
  Dequeue();
  Dequeue();

  
  return 0;
}
