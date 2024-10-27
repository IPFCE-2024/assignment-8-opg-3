#include "insertion_sort.h"

node* isort(node *list) {
if(!list || !list->next) {
    return list; //If theres no element or only one element the list is already sorted
}

    node *sorted = NULL; //Keeps track of sorted part of the list
    node *current = list; //Used to move around the unsorted part of the list
    while (current != NULL) { //Stops when current becomes NULL which happens at the end of the list
        node *next = current->next; //current->next is stored in next to not lose track of the list
        if (!sorted || current->data <= sorted->data) {
            current->next = sorted;//If the current is smaller than all previously sorted elements the current becomes the new head
            sorted = current;
        } else {
            node *temp = sorted;//Temps is used to move around the sorted part of the list
            while (temp->next != NULL && temp->next->data < current->data) { /*Temp is moved until temp is NULL or 
            when the next node has a greater value current*/
                temp = temp->next;
            }
            current->next = temp->next;//Current points to the node temps was pointing to
            temp->next = current;//temp points to current. Inserting current into the sorted part of the list
        }
        current = next;//Moves to the next node in the unsorted part of the list
    }
    return sorted;
}

