#include <stdio.h>

int main() {
    char op;
    double num1, num2, result;

    while(1){
        printf("\n Enter an operation (+, -, *, /) or q to quit: ");
        scanf(" %c", &op);

        if (op == 'q'){
            printf("thank you for unsing the calculator");
            break;
        }

        printf("enter first number: ");
        scanf("%lf", &num1);
        printf("enter second number: ");
        scanf("%lf", &num2);

        switch (op)
        {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0){
                printf("Error: zero division");
                continue;
            }
            result = num1/num2;
            break;
        default:
            printf("invalid operator");
            break;
        }
        printf("Result: %.2lf\n", result);
    }

    return 0;
}