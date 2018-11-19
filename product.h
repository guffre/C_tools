#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int __product_done = 0;

void __cartesianProduct(char* set, int length, char *currentset, int repeat, int index, int (*cb)())
{
    // printf("set:%d, length:%d, repeat:%d, index:%d\n", *set, length, repeat, index);
    int j;
    if (__product_done) { return; }
    if(index == repeat)
    {
        __product_done = (*cb)(currentset, repeat);
    }
    else
    {
        for(j=0; j < length; j++)
        {
            currentset[index] = set[j];
            __cartesianProduct(set, length, currentset, repeat, index+1, cb);
            if (__product_done) { return; }
        }
    }
}

void product(char *set, int length, int repeat, int (*cb)())
{
    char *currentset = (char *)calloc(repeat+1, sizeof(set[0]));
    
    __cartesianProduct(set, length, currentset, repeat, 0, cb);
    if (currentset) { free(currentset); currentset = NULL; }
}