/* scan_str.c -- 使用scanf（） */
#include <stdio.h>
int main(void)
{
    char name1[11], name2[11];
    int count;

    printf("Please enter 2 names.\n");
    count = scanf("%5d %10s", name1, name2);
    printf("I read the %d names %s and %s.\n", count, name1, name2);
    
    return 0;
}