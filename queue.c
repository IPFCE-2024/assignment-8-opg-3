#include "queue.h"
#include "stdio.h"
#include "stdlib.h"

// Opgave 3
void initialize(queue *q) {
q->front = NULL;
q->rear = NULL;
q->size = 0; //No elements in the queue
}

bool empty(const queue *q) {
    return q->size == 0;//Returns true if queue is empty
}

bool full(const queue *q) {
    node *temp = (node *)malloc(sizeof(node));
    if(temp == NULL){ //Like in the linked list, if malloc returns NULL no more memory can be allocated
    return true;
}
free(temp);
return false;
}

void enqueue(queue *q, int x) {
node *new = (node *)malloc(sizeof(node));
if (new == NULL){
    printf("Queue is full. \n");
    return;
}
new->data = x;
new->next = NULL; //new's data is x and new is pointing to the end of the queue

if(q->rear == NULL){ //If queue is empty both front and rear become new
    q->front = new;
    q->rear = new;
} else {
    q->rear->next = new;
    q->rear = new; //New is added to the back
}
q->size++; //The queue becomes one bigger
}


int dequeue(queue *q) {
   if (q->front == NULL) {
    printf("Queue is empty\n");
    return -1;
   }
   node *temp = q->front;
   int value = temp->data;

   q->front = q->front->next; //Front is moved to the next node in line
    if (q->front == NULL){
        q->rear = NULL; //If front is NULL the queue is empty and rear is set to NULL
    }
    free(temp);
    q->size--;
    return value;
}

// Opgave 4
void push(int element, node **head) {

}

int pop(node **head) {
    return -1;
}

void enqueueStack(queue *q, int x) {

}

int dequeueStack(queue *q) {
    return -1;
}