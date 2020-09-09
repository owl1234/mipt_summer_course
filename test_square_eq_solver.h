#ifndef TEST_SQUARE_EQ_SOLVER_H
#define TEST_SQUARE_EQ_SOLVER_H

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

#endif
