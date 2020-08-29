// Начнем с директив препроцессора. ADD_H – это произвольное уникальное имя (обычно используется имя заголовочного файла)
#ifndef TEST_SQUARE_EQ_SOLVER_H
#define TEST_SQUARE_EQ_SOLVER_H

// А это уже содержимое заголовочного файла
void test_square_eq_solver(double a, double b, double c, double right_answer1,
                       double right_answer2, double* x1, double* x2, int* number_of_test);
                        // прототип функции add() (не забывайте точку с запятой в конце!)

// Заканчиваем директивой препроцессора
#endif
