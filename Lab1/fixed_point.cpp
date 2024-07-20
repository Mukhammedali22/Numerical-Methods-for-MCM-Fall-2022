#include <iostream>
#include <cmath>

// Lab1, problem 3
// f(x) = x^3 + 3x - 1
// f(x)
double f(double x){
    return pow(x, 3) + 3*x - 1;
}
// f'(x)
double dfdx(double x){
    return 3*pow(x, 2) + 3;
}
// g(x) = x - f(x)
double g(double x){
    return x - f(x);
}
// g(x) = x - f'(x) / M
double g1(double x, int M){
    return x - f(x) / M;
}
// g'(x) = 1 - f'(x)
double dgdx(double x){
    return -3*pow(x, 2) - 2;
}
// g'(x) = 1 - f'(x) / M
double dgdx1(double x, int M){
    return x - (3*pow(x, 2) + 3) / M;
}

double Fixed_point_iteration(double a, double b, double p0, double eps=1e-6, double N=1000){
    bool isConverge = true;
    int M;

    if (g(a) > a && g(a) <= b and g(b) >= a && g(b) < b)
    {
        printf("g(x) has a fixed point at region [%.3f, %.3f].\n", a, b);
    }
    else
    {
        isConverge = false;
        M = ceil(std::fmax(dfdx(a), dfdx(b)));
        if (g1(a, M) > a && g1(a, M) <= b and g1(b, M) >= a && g1(b, M) < b)
        {
            printf("g(x) has a fixed point at region [%.3f, %.3f].\n", a, b);
        }
   
    }

    if (isConverge)
    {
        if (dgdx(a) < 1 && dgdx(b) < 1)
        {
            printf("g(x) has a unique fixed point at region [%.3f, %.3f].\n", a, b);
        }
    }
    else
    {
        if (dgdx1(a, M) < 1 && dgdx1(b, M) < 1)
        {
            printf("g(x) has a unique fixed point at region [%.3f, %.3f].\n", a, b);
        }

    }

    printf("M = %d\n", M);
    double p;
    for (int i = 0; i < N; ++i)
    {
        if (isConverge) 
        {
            p = g(p0);
        }
        else
        {
            p = g1(p0, M);
        }

        printf("iter = %d\tp = %f\n", i, p);

        if (fabs(p - p0) < eps)
        {
            return p;
        }

        p0 = p;
    }

    return p;
}

int main(){
    double a, b, p0;
    std::cout << "a, b = ";
    std::cin >> a >> b;
    std::cout << "p0 = ";
    std::cin >> p0;
    double P = Fixed_point_iteration(a, b, p0);
    std::cout << "Solution x = " << P << "\n";
}
