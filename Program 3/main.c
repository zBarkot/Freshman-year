#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define MAX_BIT 2000000001

void clear_keyboard_buffer(void);

int main(void)
{
    BIT_FLAGS inputFlag;
    int noc;
    int value;

    inputFlag = bit_flags_init_number_of_bits(MAX_BIT);
    if (inputFlag == NULL)
    {
        printf("failed to allocate\n");
        exit(1);
    }
    
    noc = scanf("%u", &value);
    clear_keyboard_buffer();

    while (noc == 1 && value > -1)
    { 
        bit_flags_set_flag(inputFlag, value);
        noc = scanf("%u", &value);
        clear_keyboard_buffer();
    }
    
    for (int i = 0; i < bit_flags_get_size(inputFlag); i++)
    {
        if (bit_flags_check_flag(inputFlag, i) == 1)
        {
            printf("%d\n", i);
        }
    }

    bit_flags_destroy(&inputFlag);

    return 0;
}
void clear_keyboard_buffer(void)
{
    char c;
    char noc;

    noc = scanf("%c", &c);
    while (noc == 1 && c != '\n')
    {
        noc = scanf("%c", &c);
    }
}