
#ifndef ferry_h
#define ferry_h
#include "status.h"

typedef void* QUEUE;

QUEUE create_queue(void);

Boolean is_empty(QUEUE hQ);

int peek(QUEUE  hQ, Status* status);

Status enqueue(QUEUE hQ, int value);

Status dequeue(QUEUE hQ);

void destroy_queue(QUEUE *phQ);

void queue_display(QUEUE hQ);





#endif /* ferry_h */
