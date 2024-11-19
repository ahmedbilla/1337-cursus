#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
int sum(int len, ...)
{
    va_list ap;

    va_start(ap, len);
    int i = 0;
    int tmp = 0;
    while (i < len)
    {
        tmp += va_arg(ap, int);
        i++;
    }
    return tmp;
}

int find_max(int len, ...)
{
    va_list ap;
    va_start(ap, len);

    int i = 1;

    int max = va_arg(ap, int);
    while (i < len)
    {
        int min = va_arg(ap, int);
        if (min > max)
        {
            max = min;
        }
        i++;
    }
    va_end(ap);
    return max;
}

int calculate_product(int len, ...)
{
    va_list ap;
    va_start(ap, len);
    int i = 0;
    int tmp = 1;

    while (i < len)
    {
        tmp *= va_arg(ap, int);
        i++;
    }
    return tmp;
    va_end(ap);
}

float calculate_average(int len, ...)
{
    va_list ap;
    va_start(ap , len);
    int i = 0;
    float tmp = 0;
    if (len == 0)
    {
       return (int)-1;

    }
    
    while (i < len)
    {
        tmp += va_arg(ap, int);
        i++;
    }
    return (tmp / len);
}
int main()
{
    // int a = big(5,90, 15, 10, 20, 50);
    // printf("%d", a);

    // printf("Product 1: %d\n", calculate_product(3, 2, 3, 4)); // 2 * 3 * 4 = 24
    // printf("Product 2: %d\n", calculate_product(4, 1, 5, 2, 3)); // 1 * 5 * 2 * 3 = 30
    // printf("Product 3: %d\n", calculate_product(2, 6, 7)); // 6 * 7 = 42

    //printf("Max 1: %d\n", find_max(3, 10, 20, 5));       // Max is 20
    //printf("Max 2: %d\n", find_max(3, -3, -10, -2)); // Max is -1
    //printf("Max 3: %d\n", find_max(5, 1, 3, 7, 2, 6));   // Max is 7


     printf("Average 1: %.2f\n", calculate_average(3, 10, 20, 30)); // Average is 20.00
    printf("Average 2: %.2f\n", calculate_average(4, -5, -10, -15, -20)); // Average is -12.50
    printf("Average 3: %.2f\n", calculate_average(5, 1, 2, 3, 4, 5)); // Average is 3.00
    printf("Average 4: %.2f\n", calculate_average(0)); // No numbers, return -1

    return 0;
}