#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 6

int main(int argc, char *argv[]) {
  PRIORITY_QUEUE hQ;

  hQ = priority_queue_init_default();
  if (hQ == NULL) {
    printf("Failed to allocate space for priority queue.\n");
    exit(1);
  }

  if (priority_queue_is_empty(hQ))
    printf("The priority queue is currently empty.\n");

  printf("_______ INSERTING INTO QUEUE ______n");
  /*for(int i = 0; i < MAX_SIZE; i++)
  {
      priority_queue_insert(hQ, i, i);
  }*/
  priority_queue_insert(hQ, 36, 0);
  priority_queue_insert(hQ, 42, 1);
  priority_queue_insert(hQ, 12, 2);
  priority_queue_insert(hQ, 7, 3);
  priority_queue_insert(hQ, 56, 4);
  priority_queue_insert(hQ, 121, 5);
  priority_queue_display(hQ);
  printf("_______________________________\n");

  if (!priority_queue_is_empty(hQ))
    printf("The priority queue is currently not empty.\n");
  printf("The front of the queue is %d.\n", priority_queue_front(hQ, NULL));

  for (int i = 0; i < MAX_SIZE; i++) {
    printf("_______ SERVICING QUEUE ________\n");
    priority_queue_service(hQ);
    if (priority_queue_is_empty(hQ)) {
      printf("The priority queue is empty as of now.\n");
    } else {
      priority_queue_display(hQ);
      printf("The front of the queue is  %d.\n",
             priority_queue_front(hQ, NULL));
    }
  }

  /// attempt 4
  Status state = SUCCESS;
  priority_queue_front(hQ, &state);
  if (state == FAILURE)
    printf("Still empty.\n");

  priority_queue_destroy(&hQ);

  return 0;
}