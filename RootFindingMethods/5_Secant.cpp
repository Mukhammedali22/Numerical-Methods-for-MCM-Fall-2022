#include <iostream>
#include <cmath>


// Solve f(x) = 0
// Secant method
// x_{n+1} = x_{n} - f(x_{n})*(x_{n} - x_{n-1}) / (f(x_{x} - f(x_{n-1}))
// Two-point iteration formula
// Look lecture 5

// User defined function
double f(double x){
    return pow(x, 3) + 3*x - 1;
}

// The Secant method for solving f(x) = 0
double Secant_method(double (*f)(double x), double p0, double p1, 
                                double eps=1e-6, int stop_iteration=1000){
    double p;
    for (int i = 0; i < stop_iteration; ++i)
    {
        p = p1 - f(p1) * (p1 - p0) / (f(p1) - f(p0));

        printf("iter = %d\tp = %f\n", i, p);

        if (fabs(p - p1) < eps) {return p;}

        p0 = p1;
        p1 = p;
    }

    return p;
}


int main(){
    double p0, p1;
    std::cout << "p0 = ";
    std::cin >> p0;
    std::cout << "p1 = ";
    std::cin >> p1;
    double P = Secant_method(f, p0, p1);
    std::cout << "Solution x = " << P << "\n";
    return 0;
}
