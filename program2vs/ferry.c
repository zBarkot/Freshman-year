#include "ferry.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
    int value;
    Node* next;

};

typedef struct queue Queue;
struct queue{
    Node *head, *tail;
    
};

QUEUE create_queue(void){
    Queue *pQ = (Queue*)malloc(sizeof(Queue));
    if(pQ == NULL){
      return NULL;
    }
    pQ->head = NULL;
    pQ->tail = NULL;

    return pQ;
}


Boolean is_empty(QUEUE hQ){
    Queue* pQ =  (Queue*)hQ;
    return (Boolean)(pQ->head == NULL);
}

int peek(QUEUE hQ, Status *status) {
    Queue* pQ =  (Queue*)hQ;
    if (is_empty(pQ)){

        if(status != NULL) *status = FAILURE;
        return 9999;
    }
    
    if(status != NULL) *status = SUCCESS;
    return pQ->head->value;

}

Status enqueue(QUEUE hQ, int value) {
    Queue* pQ =  (Queue*)hQ;
    Node *temp;
  
    temp= (Node*)malloc(sizeof(Node));
    if(temp == NULL){
      return FAILURE;
    }
    temp->value = value;
    temp->next = NULL;

    if(is_empty(pQ)) {
        pQ->head = temp;
        pQ->tail = temp ;

    }
    else {
    pQ->tail->next = temp;
    pQ->tail = pQ->tail->next;
    }

  return SUCCESS;
}

Status dequeue(QUEUE hQ) {
  Queue* pQ = (Queue*)hQ;
  Node* temp;

  if(is_empty(hQ))
  {
      return FAILURE;
  }

  temp = pQ->head;
  pQ->head = pQ->head->next;
  free(temp);
  return SUCCESS;
}

void queue_display(QUEUE hQ)
{
    Queue* pQ = (Queue*)hQ;
    Node* temp = pQ->head;

    while(temp != NULL)
    {
        printf("%d->", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

void destroy_queue(QUEUE *phQ){
  Queue* pQ = (Queue*)*phQ;
  Node* temp;

  while(pQ->head != NULL)
  {
      temp = pQ->head;
      pQ->head = pQ->head->next;
      free(temp);
  }
  free(pQ);

  *phQ = NULL;
}









