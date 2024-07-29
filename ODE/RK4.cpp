#include <iostream>
#include <cmath>
#include <vector>
#define pi 3.14159265358979323846


// y' = f(t, y)
double f(double t, double y) {
    return (t - y) / 2;
}

// Exact solution when y(0) = 1
double F(double t) {
    return 3*exp(-t / 2) - 2 + t;
}

// Runge-Kutta's method for solving I.V.P 
// Initial Value Problem
// Appoximation error O(h^2)
std::vector<double> Runge_Kutta(double (*f)(double t, double y), 
                            double a, double b, double y0, int N) {
    double dt = (b - a) / (N - 1);
    std::vector<double> t (N, 0);
    std::vector<double> y (N, 0);

    for (int i = 0; i < N; ++i) {
        t[i] = a + i*dt;
    }

    double f1, f2, f3, f4;
    y[0] = y0;
    for (int i = 0; i < N-1; ++i) {
        f1 = f(t[i], y[i]);
        f2 = f(t[i] + 0.5*dt, y[i] + 0.5*dt*f1);
        f3 = f(t[i] + 0.5*dt, y[i] + 0.5*dt*f2);
        f4 = f(t[i] + dt, y[i] + dt*f3);

        y[i+1] = y[i] + dt * (f1 + 2*f2 + 2*f3 + f4) / 6;

        printf("%i\t%.3f, %.6f\n", i, t[i], y[i]);
    }

    printf("%i\t%.3f, %.6f\n", N-1, t[N-1], y[N-1]);

    return y;
}

int main() {
    // a=0, b=3, y(0)=1
    double a, b;
    std::cout << "[a b] = ";
    std::cin >> a >> b;

    double y0;
    printf("y(%f) = ", a);
    std::cin >> y0;
    
    int N;
    std::cout << "Number of discretized points: ";
    std::cin >> N;
    
    double dt = (b - a) / (N - 1);

    std::vector<double> y = Runge_Kutta(f, a, b, y0, N);

    std::vector<double> t (N, 0);
    std::vector<double> Y (N, 0);

    for (int i = 0; i < N; ++i) {
        t[i] = a + i*dt;
    }

    for (int i = 0; i < N; ++i) {
        Y[i] = F(t[i]);
    }

    double abs_err = 0;
    for (int i = 0; i < N; ++i) {
        if (abs_err < fabs(Y[i] - y[i])) {
            abs_err = fabs(Y[i] - y[i]);
        }
    }

    std::cout << "Runge-Kutta's method\n";
    std::cout << "Approximation error O(h^4)\n";
    printf("Step size: %e\n", dt);
    printf("Absolute error: %e", abs_err);

    return 0;
}
