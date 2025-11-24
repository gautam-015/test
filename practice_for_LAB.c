#include<stdio.h>
#include<stdlib.h>
typedef struct Complex{
    float real;
    float imag;
}Complex;
Complex add(Complex a, Complex b);
Complex subtract(Complex a, Complex b);
Complex multiply(Complex a, Complex b);
Complex divide(Complex a, Complex b);
void display(Complex c);

int main(){
    Complex num1, num2, result;
    int choice;
    printf("Enter first complex number (real and imaginary): ");
    scanf("%f %f", &num1.real, &num1.imag);
    printf("Enter second complex number (real and imaginary): ");
    scanf("%f %f", &num2.real, &num2.imag);
    do {
        printf("\n------ Complex Number Operations ------\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result of Addition: ");
                display(result);
                break;

            case 2:
                result = subtract(num1, num2);
                printf("Result of Subtraction: ");
                display(result);
                break;

            case 3:
                result = multiply(num1, num2);
                printf("Result of Multiplication: ");
                display(result);
                break;

            case 4:
                result = divide(num1, num2);
                printf("Result of Division: ");
                display(result);
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}