#include "polynomial.h"

int main() {
    Polynomial p1, p2, result;

    printf("== Create p1 ==\n");
    CreatePolynomial(&p1);
    SetCoefficient(&p1, 0, 1);   // constant term
    SetCoefficient(&p1, 1, 2);   // 2x
    SetCoefficient(&p1, 2, 3);   // 3x^2
    p1.degree = GetDegree(&p1);

    printf("p1: ");
    PrintPolynomial(&p1);        // Expected: 3x^2 + 2x + 1

    printf("\n== Create p2 ==\n");
    CreatePolynomial(&p2);
    SetCoefficient(&p2, 0, -1);
    SetCoefficient(&p2, 1, 0);
    SetCoefficient(&p2, 2, 4);
    SetCoefficient(&p2, 3, -2);
    p2.degree = GetDegree(&p2);

    printf("p2: ");
    PrintPolynomial(&p2);        // Expected: -2x^3 + 4x^2 - 1

    printf("\n== Addition (p1 + p2) ==\n");
    AddPolynomials(&p1, &p2, &result);
    PrintPolynomial(&result);    // Expected: -2x^3 + 7x^2 + 2x

    printf("\n== Subtraction (p1 - p2) ==\n");
    SubtractPolynomials(&p1, &p2, &result);
    PrintPolynomial(&result);    // Expected: 2x^3 - x^2 + 2x + 2

    printf("\n== Evaluate p1 at x = 2 ==\n");
    int eval = Evaluate(&p1, 2);
    printf("p1(2) = %d\n", eval); // Expected: 3*(2^2) + 2*2 + 1 = 12 + 4 + 1 = 17

    printf("\n== Equality Check (p1 == p1) ==\n");
    printf("%s\n", IsEqual(&p1, &p1) ? "Equal" : "Not Equal");

    printf("\n== Equality Check (p1 == p2) ==\n");
    printf("%s\n", IsEqual(&p1, &p2) ? "Equal" : "Not Equal");

    return 0;
}
