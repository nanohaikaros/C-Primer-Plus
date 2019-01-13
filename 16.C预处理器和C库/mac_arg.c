// mac_arg.c -- 带有参数的宏
#include <stdalign.h>
#define SQUARE(X) X*X
#define PR(X) printf("The result is %d.\n", x);
int main(void)
{
    int x = 4;
    int z;

    printf("x = %d\n", x);
    z = SQUARE(x);
    printf("Evaluating SQUARE(x): ");
    PR(z);
    printf("Evaluating SQUARE(x+2): ");
    PR(SQUARE(x+2));
    printf("Evaluation 100/SQUARE(2): ");
    PR(100/SQUARE(2));
    printf("x is %d.\n", x);
    printf("Evaluating SQUARE(++x): ");
    PR(square(++x));
    printf("After incrementing, x is %x.\n", x);

    return 0;
}