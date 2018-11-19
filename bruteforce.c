#include <stdio.h>
#include "product.h"
#include "md5.h"
//#include <openssl/md5.h>

int callback(char *combo, int length)
{
    #ifdef HEADER_MD5_H
    unsigned char *digest = MD5(combo, length, NULL);
    #else
    unsigned char *digest = MD5(combo, length);
    #endif
    unsigned char solve[] = {37, 211, 202, 162, 49, 17, 22, 197, 39, 200, 33, 72, 124, 110, 161, 145};
    if (!memcmp(digest, solve, sizeof(solve)))
    {
        printf("match: %s\n", combo);
        return 1;
    }
    /*
    char *solve = "25d3caa2311116c527c821487c6ea191";
    // MD5 returns a static char *, so this is ok
    if (!strcmp(solve, hexdigest(digest)))
    {
        printf("%s\n", combo);
        return 1;
    }
    */
    return 0;
}

int main()
{
	int (*ptr)() = &callback;
    int i;
    
    char *arr = "abcdefghijklmnopqrstuvwxyz";
    int len = strlen(arr);
    
    for (i = 1; i <= 10; i++)
    {
        product(arr, len, i, callback);
    }
}
