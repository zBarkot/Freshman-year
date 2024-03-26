//
//  bit.c
//  Program1
//
//  Created by Barkot Zeyohanned on 10/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bit.h"

#define INT_BITS (sizeof(unsigned int) * 8)

struct flag {
    
    int size;
    unsigned int *data;
    int capacity;
    
};

typedef struct flag Flag;

//
BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits){
    
    Flag* pflag = (Flag*)malloc(sizeof(Flag));
    if(pflag == NULL) {
        printf("Failed to allocated data");
        free(pflag);
        return NULL;
    }
    if (pflag){
        
        int elements = ((number_of_bits/INT_BITS) + 1) * INT_BITS;
        
        pflag->size = number_of_bits;
        pflag->capacity = elements;
        
        pflag->data = (unsigned int*)calloc(elements, sizeof(unsigned));
        if(pflag->data == NULL) {
            printf("malloc failed BITFLAG: returning NULL!");
            free(pflag->data);
            return NULL;
        }
    }
    else {
        printf("malloc failed for BITFLAG: returning NULL");
    }
    
    return pflag;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position){
    
    Flag* pflag = (Flag*)hBit_flags;
    
    int index = flag_position/INT_BITS;
    int bit = flag_position%INT_BITS;
    //resize the array if the resize is not needed the value will remain the same
    
    if(flag_position >= pflag->capacity) {
        
        //create a temp to store old flag
        
        int old_noe = pflag->capacity/INT_BITS;
        int new_noe = (flag_position/INT_BITS) + 1;
        unsigned int* temp = (unsigned int*)calloc(new_noe,sizeof(unsigned int));
        if (temp ==NULL) {
            return FAILURE;
        }
        for(int i = 0; i < old_noe; i++) {
            temp[i] = pflag->data[i];
        }
        pflag->capacity = new_noe * INT_BITS;
        pflag->size = flag_position;
        free(pflag->data);
        pflag->data = temp;
        
    }
    if(flag_position >= pflag->size)
    {
        pflag->size = flag_position;
    }
    
    unsigned int mask = 1 << bit;
    pflag->data[index] |= mask; // set bit at flagposition to

    return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position){
    Flag* pflag = (Flag*)hBit_flags;
    int index = flag_position/INT_BITS;
    int bit = flag_position%INT_BITS;
    
    if (flag_position < 0) {
            return FAILURE; // Invalid flag position
        }
    if ( flag_position >= pflag->capacity ){ // resize array
        int numElements = (int)ceil((double)pflag->size/INT_BITS);
        int old = pflag->capacity / INT_BITS;
        unsigned int* temp = (unsigned int*)calloc(numElements,sizeof(unsigned int));
        if (temp ==NULL) {
            return FAILURE;
        }
        for(int i = 0; i < old; i++) {
            temp[i] = pflag->data[i];
            
        }
        pflag->capacity = numElements * INT_BITS;
        free(pflag->data);
        pflag->data = temp;
        
        return SUCCESS; // automatically return success because all newly allocated bytes are set to 0
    }
    unsigned int flag = ~(1u << bit);
    pflag->data[index] &= flag; // set bit at flagposition to 0
    return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position){
    Flag* pflag = (Flag*)hBit_flags;
    
  /*  if(pflag->capacity < flag_position)
        return -1;
    
    return pflag->data[flag_position];
    */
    int checked = 0;

    unsigned int index = flag_position / INT_BITS;
    unsigned int bit = flag_position% INT_BITS;
    unsigned int mask = 1 << bit;
    if(pflag->data[index] & mask ){
        checked = 1;
    }

    return checked;
}

int bit_flags_get_size(BIT_FLAGS hBit_flags){
    Flag* pflag = (Flag*)hBit_flags;
    
    return pflag->size;
    
    
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags){
    Flag* pflag = (Flag*)hBit_flags;
    
    return pflag-> capacity;
    
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags){
    Flag* pflag = (Flag*) *phBit_flags;
    
    free(pflag->data);
    free(pflag);
    *phBit_flags = NULL;
    
}

