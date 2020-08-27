#include <stdio.h>
#include <math.h>
#include <assert.h>

// This code solve a square equation of the form ax^2 + bx + c = 0
// I want to learn from Dedinsky

double get_discr (double a, double b, double c)
{
    return b * b - 4 * a * c;
}
int get_solve (double a, double b, double c, double* x1, double* x2)
{
	assert (isfinite (a));
	assert (isfinite (b));
	assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    double discr = get_discr (a, b, c);

    if (discr < 0)
    {
        return 0;
    }

    else if (a == 0)
    {
        if (b == 0 && c == 0)
        {
            return -1;
        }

        else if (b == 0)
        {
            return 0;
        }

        else
        {
            if (- c / b == 0)
            {
                *x1 = 0;
            }

            else
            {
                *x1 = - c / b;
            }
            return 1;
        }
    }

    else if (discr == 0)
    {
        if (b / 2 / a == 0)
        {
            *x1 = 0;
        }

        else
        {
            *x1 = - b / 2 / a;
        }

        return 1;
    }

    else
    {
        *x1 = (- b + sqrt (discr)) / 2 / a;
        *x2 = (- b - sqrt (discr)) / 2 / a;
        return 2;
    }

}
int main ()
{
    printf ("This code solves the square equation\n");

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    printf ("Enter the coefficients:\n");
    scanf ("%lg %lg %lg", &a, &b, &c);

    int count_solves = get_solve (a, b, c, &x1, &x2);

    switch (count_solves)
    {
        case 0:
            printf ("No roots\n");
            break;

        case 1:
            printf ("x = %lg\n", x1);
            break;

        case 2:
            printf ("x1 = %lg\nx2 = %lg\n", x1, x2);
            break;

        case -1:
            printf ("Any number\n");
            break;

        default:
            printf ("main(): ERROR: count_solves = %d\n", count_solves);

    }

    return 0;
}
