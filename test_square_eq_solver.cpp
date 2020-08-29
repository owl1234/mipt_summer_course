#include "code.h"

void test_square_eq_solver(double a, double b, double c, double right_answer1,
                       double right_answer2, double* x1, double* x2, int* number_of_test) {
    *x1 = 0;
    *x2 = 0;

    double result = get_solution(a, b, c, x1, x2);

    if (result == 1) {
        if (*x1 == right_answer1) {
            $o;
            printf("Test #%d OK\n", *number_of_test);
        } else {
            $e;
            printf("Test #%d BAD: get_solution(%lg, %lg, %lg) == %lg, should be %lg\n", *number_of_test, a, b, c, *x1, right_answer1);
        }
    } else if (result == 2) {
        if (*x1 == right_answer1 && *x2 == right_answer2 || *x1 == right_answer2 && *x2 == right_answer1) {
            $o;
            printf("Test #%d OK\n", *number_of_test);
        } else {
            $e;
            printf("Test #%d BAD: get_solution(%lg, %lg, %lg) == %lg, %lg, should be %lg, %lg\n", *number_of_test, a, b, c, *x1, *x2, right_answer1, right_answer2);
        }
    } else if (result == 0) {
        if (*x1 == *x2 && *x1 == 0) {
            $o;
            printf("Test #%d OK\n", *number_of_test);
        } else {
            $e;
            printf("Test #%d BAD: get_solution(%lg, %lg, %lg) == %lg, but there are no roots\n", *number_of_test, a, b, c, *x1);
        }
    } else if (result == -1) {
        if (*x1 == *x2 && *x1 == 0) {
            $o;
            printf("Test #%d OK\n", *number_of_test);
        } else {
            $e;
            printf("Test #%d BAD: get_solution(%lg, %lg, %lg) == %lg, but the roots are any numbers\n", *number_of_test, a, b, c, result);
        }
    } else {
        $f;
        printf("Test #%d IS VERY BAD: it is very strange number of solutions: %d\n", *number_of_test, *x1);
    }


    (*number_of_test)++;

    $d;
}
