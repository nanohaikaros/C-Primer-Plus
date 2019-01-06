/* convert.c -- 自动类型转换 */
#include <stdio.h>
int main(void)
{
    char ch;
    int i;
    float f1;

    f1 = i = ch = 'A';
    printf("ch = %c, i = %d, f1 = %2.2f\n", ch, i, f1);
    ch = ch + 1;
    i = f1 + 2 * ch;
    f1 = 2.0 *ch + i;
    printf("ch = %c, i = %d, f1 = %2.2f\n", ch, i, f1);
    ch = 5212205.17;
    printf("Now ch = %c\n", ch);
    return 0;
}