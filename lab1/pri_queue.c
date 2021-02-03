#include <stdlib.h>
#include <stdio.h>
#include "pri_queue.h"
/** @file pri_queue.c */
static Node_ptr_t head = NULL;
/**
 * Insert a Node into a priority queue.
 * @param priority
 * @param data
 * @author Sukhjot Saggu
 */
void PQ_insert(int priority, char * data) {
    Node_ptr_t newData = malloc(sizeof(Node_t)); // Creating new pointer for new data to be inserted
    newData -> data = data;
    newData -> priority = priority;
    
    Node_ptr_t temp, counter;
    temp = malloc(sizeof(Node_t));
    counter = malloc(sizeof(Node_t));
    if(PQ_get_size() == 0){ //Checking if head of the PQ has been created
        head = malloc(sizeof(Node_t));
        head = newData;
    }
    else{ //If head of PQ already exists
        temp = malloc(sizeof(Node_t)); //Set temp pointer
        for(counter = head; counter != NULL; counter = counter ->next){ 
            if(counter -> priority <= priority){ //Go to correct priority level and insert the data into the linked list
                memcpy(temp, counter, sizeof(Node_t));
                counter -> data = data;
                counter -> priority = priority;
                counter -> next = temp;
                break;
            }
            else if(counter -> data == NULL){ //If the new data has the lowest priority, then insert at the end of the list
                counter -> next = malloc(sizeof(Node_t));
                counter -> next = newData;
            }
        }
    }
}
/**
 * Delete and return the node with the highest priority.
 * @return The highest priority Node.
 */
Node_ptr_t PQ_delete() {
    Node_ptr_t temp = malloc(sizeof(Node_t));
   
    if(head != NULL){
        temp = head;
        if(head -> next != NULL){
            head = head -> next;
        } 
    }
    else{
            temp = NULL; 
        }
    return temp;
}

/**
 * Do NOT modify this function.
 * @return A pointer to the head of the list.  (NULL if list is empty.)
 */
Node_ptr_t PQ_get_head() {
    return head;
}

/**
 * Do NOT modify this function.
 * @return the number of items in the queue
 */
int PQ_get_size() {
    int size = 0;
    Node_ptr_t tmp;
    for(tmp = head; tmp != NULL; tmp = tmp->next, size++)
        ;
    return size;
}


