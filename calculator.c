#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int is_operator(char* c){
    if (c == NULL) return 0;
    return *c == '+' || *c == '-' || *c == '/' || *c == '*';
}

int main() {
    char input[MAX_LEN];
    printf("Welcome to the calculator\n");
    printf("Enter 'q' to quit\n");

    while(1){
        printf("Enter Expression: ");
        fgets(input, MAX_LEN, stdin);
        printf("input: %s \n", input);

        if (strcmp(input, "q")==0){
            printf("thank you gor using the calculator\n");
            break;
        }

        // remove spaces
        char cleaned[MAX_LEN];
        int j = 0;
        int input_length = strlen(input);
        printf("input length: %d \n", input_length);
        for (int i = 0; i < input_length; i++){
            if (input[i] != ' '){
                cleaned[j++] = input[i];
            }
        }
        cleaned[j] = '\0';

        printf("cleaned input %s \n", cleaned);

        // tokenise input
        int cleaned_length = strlen(cleaned);
        char buffer[50];
        double numbers[50];
        char op[10];
        int buffer_idx = 0, op_idx = 0, numbers_idx = 0;
        

        for (int i = 0; i < cleaned_length; i++){
            if (isdigit(cleaned[i])){
                buffer[buffer_idx++] = cleaned[i];
            } else if (is_operator(&cleaned[i])){
                buffer[buffer_idx++] = '\0';
                buffer_idx = 0;
                numbers[numbers_idx++] = atof(buffer);

                op[op_idx++] = cleaned[i];
            }
        }

        if (buffer_idx > 0) {
            buffer[buffer_idx] = '\0';
            numbers[numbers_idx] = atof(buffer);
            buffer_idx = 0;
        }

        buffer[buffer_idx] = '\0';
        op[op_idx] = '\0';

        printf("Numbers: ");
        for (int i = 0; i < numbers_idx; i++) {
            printf("%.2f ", numbers[i]);
        }
        printf("\nOperators: ");
        for (int i = 0; i < op_idx; i++) {
            printf("%c ", op[i]);
        }
        printf("\n");

        double result = numbers[0];

        for (int i = 0; i < op_idx; i++) {
            char operator = op[i];
            double next_number = numbers[i + 1];

            switch (operator) {
                case '+':
                    result += next_number;
                    break;
                case '-':
                    result -= next_number;
                    break;
                case '*':
                    result *= next_number;
                    break;
                case '/':
                    if (next_number == 0) {
                        printf("Error: Division by zero!\n");
                        goto end_of_loop;
                    }
                    result /= next_number;
                    break;
                default:
                    printf("Unknown operator: %c\n", operator);
                    goto end_of_loop;
            }
        }

        printf("Result (left-to-right): %.2f\n", result);

    }

    end_of_loop:;

    return 0;
}