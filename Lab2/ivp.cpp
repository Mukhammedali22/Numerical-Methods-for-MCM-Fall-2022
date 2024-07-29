#include <iostream>
#include <cmath>
#include <vector>
#define pi 3.14159265358979323846

// 2 variant
// y' = y - 3x, y(1) = 0, x=[1, 2.2], h=0.3

// y' = f(t, y)
double f(double x, double y) {
    return y - 3*x;
}

// Exact solution when y(0) = 1
double F(double x) {
    return 3*(x + 1) - 6*exp(-1) * exp(x);
}

// Euler's method for solving I.V.P 
// Initial Value Problem
// Appoximation error O(h)
std::vector<double> Euler(double (*f)(double x, double y), 
                            double a, double b, double y0, int N) {
    double dx = (b - a) / (N - 1);
    std::vector<double> x (N, 0);
    std::vector<double> y (N, 0);

    for (int i = 0; i < N; ++i) {
        x[i] = a + i*dx;
    }

    std::cout << "Euler's method\n";

    y[0] = y0;
    for (int i = 0; i < N-1; ++i) {
        y[i+1] = y[i] + dx * f(x[i], y[i]);
        printf("%i\t%.3f, %.6f\n", i, x[i], y[i]);
    }

    printf("%i\t%.3f, %.6f\n", N-1, x[N-1], y[N-1]);
    
    return y;
}

// Heun's method for solving I.V.P 
// Initial Value Problem
// Appoximation error O(h^2)
std::vector<double> Heun(double (*f)(double x, double y), 
                            double a, double b, double y0, int N) {
    double dx = (b - a) / (N - 1);
    std::vector<double> x (N, 0);
    std::vector<double> y (N, 0);

    for (int i = 0; i < N; ++i) {
        x[i] = a + i*dx;
    }

    std::cout << "Heun's method\n";

    double p;
    y[0] = y0;
    for (int i = 0; i < N-1; ++i) {
        p = y[i] + dx * f(x[i], y[i]);
        y[i+1] = y[i] + (f(x[i], y[i]) + f(x[i+1], p)) * dx / 2;
        printf("%i\t%.3f, %.6f\n", i, x[i], y[i]);
    }

    printf("%i\t%.3f, %.6f\n", N-1, x[N-1], y[N-1]);
    
    return y;
}


int main() {
    // y' = y - 3x, y(1) = 0, x=[1, 2.2], h=0.3
    double a, b;
    std::cout << "[a b] = ";
    std::cin >> a >> b;

    double y0;
    printf("y(%f) = ", a);
    std::cin >> y0;
    
    double dx;
    std::cout << "Step size h = ";
    std::cin >> dx;
    
    int N = (b - a) / dx + 1;

    std::vector<double> y = Euler(f, a, b, y0, N);
    std::vector<double> y1 = Heun(f, a, b, y0, N);
    std::vector<double> Y (N, 0);

    double x = a;
    for (int i = 0; i < N; ++i) {
        x = a + i*dx;
        Y[i] = F(x);
    }

    double abs_err = 0;
    double abs_err1 = 0;
    for (int i = 0; i < N; ++i) {
        if (abs_err < fabs(Y[i] - y[i])) {
            abs_err = fabs(Y[i] - y[i]);
        }

        if (abs_err1 < fabs(Y[i] - y1[i])) {
            abs_err1 = fabs(Y[i] - y1[i]);
        }
    }

    printf("Step size h = %e\n", dx);
    printf("Absolute error (Euler): %e\n", abs_err);
    printf("Absolute error (Heun): %e\n", abs_err1);
    std::cout << "Euler: Approximation error O(h)\n";    
    std::cout << "Heun: Approximation error O(h^2)\n";    

    return 0;
}
