// r_dirve0.c -- 测试rand0（）函数
#include <stdio.h>
extern int rand0(void);

int main(void)
{
    int count;

    for(count = 0; count < 5; count++)
        printf("%hd\n", rand0());
    
    return 0;
}