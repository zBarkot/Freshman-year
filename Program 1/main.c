#include<stdio.h>

 int main() {
    int startPoint;
    int endPoint;
    int steps;

    for (int i=0; i<1; ++i){
    printf("Enter a starting point:\n");
    scanf("%d", &startPoint);
       if (startPoint < 2 || startPoint > 99) {
           printf("Enter valid starting point\n");
       }
    }
     
    for (int i = 0; i<1;){
    printf("Enter a end point.\n");
    scanf("%d", &endPoint);
    if (startPoint > endPoint || endPoint > 1000 || endPoint < 4) {
       printf("Enter a valid end point\n");
      }
      else{
        ++i;
      }
    
    }
    
    int num = startPoint;
    
     steps = 0;
     int u = 0;
     for( u = startPoint; u <= endPoint; ++u) {
     while (num > 1) {
       if (num%2 > 0)
          num = 3*num+1;
       else
          num /= 2;
       
       steps += 1;
    }
     printf("%d : %d \n", num, steps);
     
     }
       
 }
