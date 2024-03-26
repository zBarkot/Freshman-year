//
//  main.c
//  Program 2
//
//  Created by Barkot Zeyohanned on 11/6/22.
//

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int fibonacciNumber(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else
    {
        return (fibonacciNumber(num-1) + fibonacciNumber(num-2));
    }
    
}
void clearKeyboardBuffer(void)
{
    char c;
    scanf("%c", &c);
    while(c != '\n')
    {
        scanf("%c", &c);
    }
}

int main() {
    
    int initial;
    int numDays;
    char repeat;
    int cycles;
    int fibNum;
    
    
    do{// entire prompt
        //crude initial population promt
        
        printf("Please enter the initial size of the green crud:\n");
        scanf("%d", &initial);
        printf("%d", initial);
        clearKeyboardBuffer();
        while(initial < 1 || !isdigit(initial)){
            printf("I'm sorry that value is unrecognized or is negative.\n""Please Enter the initial size of the green crud:\n");
            scanf("%d", &initial);
            clearKeyboardBuffer();
        }
        //days of population growth prom
        printf("Please enter the number of days: \n");//day promt
        scanf("%d",&numDays);
        clearKeyboardBuffer();
        
        while(numDays < 0 || isdigit(numDays))
                {
                    printf("I'm sorry, that value is unrecognized or is negative.\nPlease enter the number of days the green curd will grow: ");
                    scanf("%d", &numDays);
                    clearKeyboardBuffer();
                }
        
        
            cycles = numDays/5;
            fibNum = fibonacciNumber(cycles + 1);
            if(fibNum == 0 || fibNum == 1)
                {
                    printf("With an initial population of %d pounds of curd growing for %d days, the final population would be %d pounds.\n", initial, numDays, initial);
                }
                else
                {
                    printf("With an initial population of %d pounds of curd growing for %d days, the final population would be %d pounds.\n", initial, numDays, initial*fibNum);
                }
        printf("Would you like to continue? (y/n)");
        scanf("%c",&repeat);
        clearKeyboardBuffer();
        while(tolower(repeat) != 'y' && tolower(repeat) != 'n')
                {
                    printf("I'm sorry, that answer is unrecognized.\nWould you like to continue? (y/n): ");
                    scanf("%c", &repeat);
                    clearKeyboardBuffer();
                }
    } while (repeat == 'y');
    
}
