#include <iostream>
#include <cmath>

#define pi 3.14159265358979323846

// 3 variant
double f(double x) {
    return 3*x*x - sqrt(x);
}

// Exact solution
double F(double x, double c=0) {
    return x*x*x - 2*x*sqrt(x) / 3 + c;
}

// Midpoint rule for numerical integration
double Midpoint(double (*f)(double x), double a,
                    double b, int N) {
    double dx = (b - a) / (N - 1);
    double x = a;

    double s = 0;
    for (int i = 0; i < N-1; ++i) {
        x = a + i*dx;
        s += f(x + 0.5*dx) * dx;
    }

    return s;
}

// Simpson rule for numerical integration
double Simpson(double (*f)(double x), double a,
                    double b, int N) {
    // number of subdivisions must be even so
    // number of points will be odd
    N = N + (N + 1) % 2;
    double dx = (b - a) / (N - 1);
    double x = a;

    double s = f(a);
    for (int i = 1; i < N-1; ++i) {
        x = a + i*dx;
        s += f(x) * ((i % 2) ? 4 : 2);
    }
    s += f(b);

    return s * dx / 3;
}


int main() {
    // a=0, b=3, n=6
    double a, b;
    std::cout << "[a b] = ";
    std::cin >> a >> b;

    int N;
    std::cout << "n: ";
    std::cin >> N;
    N = N + 1;

    double dx = (b - a) / (N - 1);

    double y = Midpoint(f, a, b, N);
    double y1 = Simpson(f, a, b, N);
    double exact = F(b) - F(a);

    double abs_err = fabs(exact - y);
    double abs_err1 = fabs(exact - y1);

    printf("Step size h = %f\n", dx);

    printf("Midpoint: %f\n", y);
    printf("Simpson:  %f\n", y1);
    printf("Exact:    %f\n", exact);

    printf("Absolute error (Midpoint): %e\n", abs_err);
    printf("Absolute error (Simpson): %e\n", abs_err1);

    std::cout << "Midpoint: Approximation error O(h^2)\n";    
    std::cout << "Simpson: Approximation error O(h^4)\n";    

    return 0;
}
