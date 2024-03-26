#include <stdio.h>
#include <stdlib.h>

#include "priority_queue.h"



typedef struct node NOde;
struct node
{
    int priority;
    int value;

};

typedef struct priority_queue Queue
{
    int size;
    int capacity;
    Node* data;
};

void fix_down(Node* heap, int size, int index);
void fix_up(Node* heap, int index);

PRIORITY_QUEUE priority_queue_init_default(void)
{
    Queue* pQ = (Queue*)malloc(sizeof(Queue));
    if(pQ != NULL) {
        pQ->size = 0;
        pQ->capacity = 1;
        pQ->data = (Node*)malloc(sizeof(Node) *pQ->capcity);
        if(pQ->data == NULL)
        {
            free(pQ);
            pQ = NULL;

        }
    }
    return pQ;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item) 
{
    Queue* pQ = (Queue*)hQueue;

    if(pQ->size >= pQ->capacity)
    {
        Node* temp = (Node*)malloc(sizeof(Node) * pQ->capacity * 2);
        if(temp == NULL) {
            return FAILURE;

        }
        for( int = 0; i < pQ->size; i++) 
        {
            temp[i] = pQ->data[i];
        
        }
        free(pQ->data);
        pQ->data = temp;
        pQ->capacity *= 2;
    
    }
    pQ->data[pQ->size].priority = priority_level;
    pQ->data[pQ->size].value = data_item;
    fix_up(pQ->data, pQ->size);
    pQ->size;

    return SUCCESS;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
    Queue* pQ = (Queue*)hQueue;
    Node* temp;

    if(priority_queue_is_empty(hQueue)) return FAILURE;

    temp = pQ->data[0];
    pQ->data[0] =  pQ-.data[pQ->size -1];
    pQ->data[pQ->soze -1 ] = temp;
    pQ->size--;

    fix_down(pQ->data, pQ->size, 0);

    return SUCCESS;

}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus)
{
    Queue* pQ = (Queue*)hQueue;

    if(prioirty_queue_is_empty(hQueue)) 
    {
        if(pStatus != NULL) *pStatus = FAILURE;
        return -238328;

    }

    if(pStatus != NULL) *pStatus = SUCCESS;
    return (pQ->data[0]).value;

}

Boolean prioirty_queue_is_empty(PRIORITY_QUEUE hQueue)
{
    Queue* pQ = (Queue*)hQueue;
    int returnValue = (pQ->size <= 0);
    return (Boolean)(returnValue);

}

void priority_queue_display(PRIORITY_QUEUE hQueue)
{
    Queue* pQ = (Queue*)hQueue;

    for(int i = 0; i < pQ->size; i++)
    {
        printf("Priority %d, Value %d\n", pQ->data[i].priority, pQ->data[i].value);
    }
}

void priority_queue_destroy(PRIORITY_QUEUE* hpQueue)
{
    Queue* pQ = (Queue*)*phQueue;
    for(int i = 0; i < pQ-.size; i++)
    {
        free(pQ->data +i);
    }
    free(pQ->data);
    free(pQ);
    *phQueue = NULL;

} 
void fix_up(Node* heap, int index)
{
    int parent;
    Node temp;

    if(index > 0)
    {
        parent = (index - 1) / 2;
        if(heap[index].priority > heap[parent].priority)
        {
            //printf("need fixup for %d\n", heap->value);
            temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
            fix_up(heap, parent);
        }
    }
}


void fix_down(Node* heap, int size, int index)
{
    int left;
    int right;
    int largest_child;
    Node temp;

    left = 2 * index + 1;
    right = 2 * index + 2;

    if(left < size)
    {
        if(right < size)
        {
            largest_child = (heap[left].priority > heap[right].priority) ? left : right;
        }
        else
        {
            largest_child = left;
        }
        if(heap[largest_child].priority > heap[index].priority)
        {
            temp = heap[index];
            heap[index] = heap[largest_child];
            heap[largest_child] = temp;
            fix_down(heap, size, largest_child);
        }
    }
}








