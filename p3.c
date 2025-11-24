#include <stdio.h>

// Function to add two polynomials
void addPolynomials(int *poly1, int *poly2, int *result, int n1, int n2) {
    int max = (n1 > n2) ? n1 : n2;

    // Initialize result array with 0
    for (int i = 0; i < max; i++)
        result[i] = 0;

    // Add elements of first polynomial
    for (int i = 0; i < n1; i++)
        result[i] += poly1[i];

    // Add elements of second polynomial
    for (int i = 0; i < n2; i++)
        result[i] += poly2[i];
}

// Function to print the polynomial
void printPolynomial(int poly[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%dx^%d", poly[i], i);
            if (i != 0)
                printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    int n1, n2;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &n1);
    int poly1[n1 + 1];
    printf("Enter coefficients for first polynomial (from x^0 to x^%d):\n", n1);
    for (int i = 0; i <= n1; i++)
        scanf("%d", &poly1[i]);

    printf("Enter degree of second polynomial: ");
    scanf("%d", &n2);
    int poly2[n2 + 1];
    printf("Enter coefficients for second polynomial (from x^0 to x^%d):\n", n2);
    for (int i = 0; i <= n2; i++)
        scanf("%d", &poly2[i]);

    int maxDegree = (n1 > n2) ? n1 : n2;
    int result[maxDegree + 1];

    addPolynomials(poly1, poly2, result, n1 + 1, n2 + 1);

    printf("\nFirst Polynomial: ");
    printPolynomial(poly1, n1 + 1);

    printf("Second Polynomial: ");
    printPolynomial(poly2, n2 + 1);

    printf("Sum of Polynomials: ");
    printPolynomial(result, maxDegree + 1);

    return 0;
}