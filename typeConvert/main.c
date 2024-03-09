#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int main()
{
    /* void * 强转 */
    char * ptr = (char *)malloc(sizeof(char *) * BUFFER_SIZE);
    free(ptr);


    return 0;
}