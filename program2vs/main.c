
#include "ferry.h"
#include <stdio.h>
#include <stdlib.h>

const int MAX_VALUE = 6;

void clear_keyboard_buffer(void);
int test(void);
void ferryService(QUEUE hQ, int ferry_length);

int main(int argc, const char *argv[]) 
{
  
  int c = 0;
  scanf("%d", &c);
  clear_keyboard_buffer();

  for (int i = 0; i < c; i++) { // runs each of the test cases
    printf("%d\n", test());
  }

  return 0;
}

int test(void) {
  
    int trips = 0;
    int ferryL; //length of ferry
    int cars;      // total number of cars in line
    char bank[MAX_VALUE]; // the bank of the car
    int carLength;  //length of car

    QUEUE rightBank = create_queue();
    QUEUE leftBank = create_queue();
    if(leftBank == NULL || rightBank == NULL) {
        printf("Failed to allocate space for queue object.\n ");
        exit(1);
    }
    
    // length of car in centimeters
    scanf("%d %d", &ferryL, &cars); 
    ferryL *= 100; // change to cm from m
    clear_keyboard_buffer();

    for (int i = 0; i < cars; i++) { // filling up the queues 
      scanf("%d %s", &carLength, bank);
      
        if (bank[0] == 'l') 
        {
        enqueue(leftBank, carLength);
        
        } else if (bank[0] == 'r')
        {
        enqueue(rightBank, carLength);
        }
    }

    queue_display(leftBank);
    queue_display(rightBank);
    printf("%d\n", peek(leftBank,  NULL));

    
    while (!is_empty(leftBank) || !is_empty(rightBank))
        {
        
        ferryService(leftBank, ferryL);
        trips++;

        if(is_empty(leftBank) && is_empty(rightBank)) break;
        
        ferryService(rightBank, ferryL);
        trips++;
    }
    

    destroy_queue(&leftBank);

    destroy_queue(&rightBank);

    return trips;
}

void ferryService(QUEUE hQ, int ferry_length) {
  int ferry_load = 0;

  while (!is_empty(hQ) && ferry_load <= ferry_length) {
    if (peek(hQ, NULL) + ferry_load > ferry_length) 
    {
      break;
    }
    ferry_load += peek(hQ, NULL);
    dequeue(hQ);
  }
}

void clear_keyboard_buffer(void) {
  char c;
  char noc;

  noc = scanf("%c", &c);
  while (noc == 1 && c != '\n') {
    noc = scanf("%c", &c);
  }
}
