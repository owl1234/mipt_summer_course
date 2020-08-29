/**
 * @file
 * @author Kolesnikova Xenia <heiduk.k.k.s@yandex.ru>
 * @version 1.0 *
 */

#include "TXLib.h"
#include "test_square_eq_solver.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>


// This code solve a square equation of the form ax^2 + bx + c = 0
// I want to learn from Dedinsky

/**
 * \brief A necessary constant for its convenient use
 */

const double epsilon = 1e-7;

/**
*   \brief This function compares a number with 0
*
*   @param x The number that you want to compare
*
*   @return True or False (equivalent to 0 or not)
*/

bool is_zero(double x);

/**
*   \brief This function calculates discriminant of the
*   square equation
*
*   @param a,b,c Coefficients of the square equation
*
*   @return Discriminant your square equation
*/

double get_discr(double a, double b, double c);

/**
*   \brief This function calculates solutions of the
*   square equation
*
*   @param a,b,c Coefficients of the square equation
*   @param x1,x2 Pointers to variables that solutions are written to
*
*   @return Number of solutions.
*   If the discriminant is less than 0, the solutions not written to a variables.
*   If the discriminant is 0, the solution is written to a variable x1.
*   If the discriminant is greater than 0, the solution is written to a
*   variables x1 and x2
*/

int get_solution(double a, double b, double c, double* x1, double* x2);

/**
*   \brief This function tests function get_solution()
*
*   @param a,b,c Coefficients of the square equation
*   @param right_answer1,right_answer2 Correct roots of the equation
*   @param x1,x2 Pointers to variables that solutions are written to
*   @param number_of_test Test number
*
*   @return Nothing
*/

void test_square_eq_solver(double a, double b, double c, double right_answer1,
                       double right_answer2, double* x1, double* x2, int* number_of_test);

/**
*   \brief This function contains a set of tests and starts testing function get_solution()
*
*   @param x1,x2 Pointers to variables that solutions are written to
*   @param number_of_test Test number
*
*   @return Nothing
*/

void launch(double* x1, double* x2);

int main () {
    double x1 = 0, x2 = 0;

    launch(&x1, &x2);

    return 0;

    printf("This code solves the square equation\n");

    double a = 0, b = 0, c = 0;


    printf("Enter the coefficients:\n");
    scanf("%lg %lg %lg", &a, &b, &c);

    int count_solutions = get_solution(a, b, c, &x1, &x2);

    switch (count_solutions) {
        case 0:
            printf("No roots\n");
            break;

        case 1:
            printf("x = %lg\n", x1);
            break;

        case 2:
            printf("x1 = %lg\nx2 = %lg\n", x1, x2);
            break;

        case -1:
            printf("Any number\n");
            break;

        default:
            printf("main(): ERROR: count_solutions = %d\n", count_solutions);

    }

    return 0;
}

bool is_zero(double x) {

    return (fabs(x) - epsilon < 0) ? true : false;
}

double get_discr(double a, double b, double c) {

    return b * b - 4 * a * c;
}

int get_solution(double a, double b, double c, double* x1, double* x2) {

//    assert(isfinite(a));
//    assert(isfinite(b));
//    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    double discr = get_discr(a, b, c);

    if (discr < - epsilon) {
        return 0;
    } else if (is_zero(a)) {
        if (is_zero(b) && is_zero(c)) {
            return -1;
        } else if (is_zero(b)) {
            return 0;
        } else {
            if (is_zero(- c / b)) {
                *x1 = 0;
            } else {
                *x1 = - c / b;
            }
            return 1;
        }
    } else if (is_zero(discr)) {
        if (is_zero(b / 2 / a)) {
            *x1 = 0;
        } else {
            *x1 = - b / 2 / a;
        }
        return 1;
    } else {
        double sqrt_discr = sqrt(discr);
        *x1 = (- b + sqrt_discr) / 2 / a;
        *x2 = (- b - sqrt_discr) / 2 / a;
        return 2;
    }

}


void launch(double* x1, double* x2) {
    int number_of_test = 1;
    test_square_eq_solver(1, 2, 1, -1, 0, x1, x2, &number_of_test);
    test_square_eq_solver(1, -2, 1, 1, 0, x1, x2, &number_of_test);
    test_square_eq_solver(1, -3, 2, 1, 2, x1, x2, &number_of_test);
    test_square_eq_solver(5, 1, 5, 0, 0, x1, x2, &number_of_test);
    test_square_eq_solver(0, 0, 0, 0, 0, x1, x2, &number_of_test);
    test_square_eq_solver(0, 0, 9, 0, 0, x1, x2, &number_of_test);
}
