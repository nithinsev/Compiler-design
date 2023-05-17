#include <stdio.h>

int main() {
    int num1, num2, num3, result;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    result = num1 + num2 * num3;  // The multiplication is done first
    printf("Result of num1 + num2 * num3 is %d\n", result);

    result = (num1 + num2) * num3;  // The addition is done first due to parentheses
    printf("Result of (num1 + num2) * num3 is %d\n", result);

    result = num1 / num2 + num3;  // The division is done first
    printf("Result of num1 / num2 + num3 is %d\n", result);

    result = num1 / (num2 + num3);  // The addition is done first due to parentheses
    printf("Result of num1 / (num2 + num3) is %d\n", result);

    result = num1 * num2 + num3 - num1;  // Multiplication and addition are done first, then subtraction
    printf("Result of num1 * num2 + num3 - num1 is %d\n", result);

    return 0;
}


