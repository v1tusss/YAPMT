#include <stdio.h>

int main()
{
    float a, b, c, x;
    printf("ax+b=c  ");
    printf("Введите коэфициент a: ");
    scanf("%d", &a);
    printf("ВВедите коэфициент b: ");
    scanf("%d", &b);
    printf("ВВедите коэфициент c: ");
    scanf("%d", &c);
    
    x = (c-b) / a;
    printf("x = %.2f\n", x);
    return 0;
    
    

}