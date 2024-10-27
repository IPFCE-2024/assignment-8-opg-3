#include "queue.h"
#include "stdio.h"
#include "stdlib.h"

void initialize(queue *q) {
q->front = NULL;
q->rear = NULL;
}

// Opgave 4
void push(int element, node **head) {//tilføjer element til toppen af vores stak
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
    newNode->data = element;
    newNode->next = *head;//sætter det nye element på toppen af stakken
    *head = newNode;

}

int pop(node **head) {//fjerner/returnerer element fra toppen af stak
    if (*head == NULL)
    {
        printf("stack is empty\n");
        return -1;//returner fejl hvis stak er tom
    }
    node *temp = *head;
    int value = temp->data;
    *head = (*head)->next;
    free(temp);
    return value;
} 

//Tilføjer element til rear, som er den stak vi bruger
void enqueueStack(queue *q, int x) {//som enqueue men bruger push til at tilføje element
    push(x, &q->rear);
}

//fjerner første tilføjede element fra køen
int dequeueStack(queue *q) {//som dequeue men bruger pop til at fjerne element
        if (q->front == NULL)
        {
            while (q->rear != NULL)//flytter elementer fra stack1 til stack2 hvis den er tom
            {
                int element = pop(&q->rear);
                push(element, &q->front);
            }
        }

    if (q->front == NULL)
    {
        printf("queue is empty\n");
         return -1;
    }
        
    return pop(&q->front);//fjerner første tilføjede element
}
