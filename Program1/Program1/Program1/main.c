/**********************************************************
Author: Barkot Zeyohannes
Date: October 13, 2023
Effort: 3hours
Purpose: using an opaque object for bit masking
Interface proposal: <answer the last question in the specification>
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "bit.h"

int main(int argc, const char * argv[]) {
    BIT_FLAGS hbit_flags = bit_flags_init_number_of_bits(100);

    printf("Initialize successful Bit flags %p\n", hbit_flags);
    printf("The size is %d\n", bit_flags_get_size(hbit_flags));
    printf("The capacity is %d\n", bit_flags_get_capacity(hbit_flags));

    // testing set_flag function
    bit_flags_set_flag(hbit_flags, 3);
    bit_flags_set_flag(hbit_flags, 30);
    bit_flags_set_flag(hbit_flags, 34);
    bit_flags_set_flag(hbit_flags, 63);
    bit_flags_set_flag(hbit_flags, 92);
    bit_flags_set_flag(hbit_flags, 121);
    bit_flags_set_flag(hbit_flags, 127);
    bit_flags_set_flag(hbit_flags, 130);
    printf("Set flag\n");
    printf("The size is %d\n", bit_flags_get_size(hbit_flags));
    printf("The capacity is %d\n", bit_flags_get_capacity(hbit_flags));
    bit_flags_set_flag(hbit_flags, 131);
    printf("The size is %d\n", bit_flags_get_size(hbit_flags));
    printf("The capacity is %d\n", bit_flags_get_capacity(hbit_flags));

    // printing the bits to check
    printf("\nSet flag checking:\n");
    for (int i = 0; i < bit_flags_get_capacity(hbit_flags); i++)
    {
        if (i % 32 == 0)
            printf("\n");
        else if (i % 4 == 0)
            printf(" ");
        printf("%d", bit_flags_check_flag(hbit_flags,i));
    }

    // testing unset_flag function
    bit_flags_unset_flag(hbit_flags, 3);
    bit_flags_unset_flag(hbit_flags, 34);
    bit_flags_unset_flag(hbit_flags, 127);
    bit_flags_unset_flag(hbit_flags, 130);

    // printing the bits to check
    printf("\n\nUnset flag checking:\n");
    for (int i = 0; i < bit_flags_get_capacity(hbit_flags); i++)
    {
        if (i % 32 == 0)
            printf("\n");
        else if (i % 4 == 0)
            printf(" ");
        printf("%d", bit_flags_check_flag(hbit_flags,i));
    }
    printf("\n");
    bit_flags_destroy(&hbit_flags);
}
