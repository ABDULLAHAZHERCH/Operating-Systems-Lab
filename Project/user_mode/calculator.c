#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void header()
{
    system("clear");
    puts("");
    puts("--------------------------------< Calculator >--------------------------------");
    puts("");
}

float cal(float num1, char c, float num2)
{
    if (c == '+')
    {
        return (num1 + num2);
    }
    else if (c == '-')
    {
        return (num1 - num2);
    }
    else if (c == '*')
    {
        return (num1 * num2);
    }
    else if (c == '/')
    {
        if (num2 == 0)
        {
            return -1;
        }

        return (num1 / num2);
    }
}

float input()
{
    float num1, num2;
    char c;
    float result = 0;

    printf("Enter first positive integer : ");
    scanf("%f", &num1);

    printf("Enter operation to perform (+,-,*,/) : ");
    scanf(" %c", &c);

    printf("Enter second positive integer : ");
    scanf("%f", &num2);

    result = cal(num1, c, num2);
    return result;
}

int main()
{
    char c;
    float result = 0;
    header();
    result = input();
    puts("");
    printf("Result of that Expression is : %.2f\n", result);
    puts("Press any key to continue!");
    scanf(" %c", c);
}