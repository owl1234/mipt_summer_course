#ifndef CODE_H
#define CODE_H

bool is_zero(double x);

double get_discr(double a, double b, double c);

int get_solution(double a, double b, double c, double* x1, double* x2);

void launch(double* x1, double* x2);

int main();

#endif
