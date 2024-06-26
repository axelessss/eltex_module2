#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "operations.h"


bool input(int operation, bool shutdown)
{
    float a, b;

    float (*result) (float, float);

    switch(operation)
        {
            case 1:
                result = sum;
                break;
            
            case 2:
                result = subtract;
                break;
            
            case 3:
                result = mul;
                break;
            
            case 4:
                result = div;
                break;
            
            case 5:
                result = deg;
                break;
            
            case 6:
                result = root;
                break;
            
            default:
                shutdown=true;
                break;
        }

    if (shutdown)
        return true;
    else
    {
        printf("Введите первый аргумент: ");
        scanf("%f", &a);
        printf("Введите второй аргумент: ");
        scanf("%f", &b);
        printf("Результат = %f\n", result(a, b));
        return false;
    }
}

int main()
{
    bool shutdown=false;
    int operation;

    while (true)
    {
        if (shutdown)
            break;

        printf("\nВыберите действие: ");
        printf("\n1-сложение\n2-вычитание\n3-умножение\n4-деление\n5-возведение в степень\n6-корень n-й степени\nЛюбая другая кнопка-завершить работу\n");
        scanf("%d", &operation);
        shutdown = input(operation, shutdown);

        if(!shutdown)
            sleep (5);
    }
}
