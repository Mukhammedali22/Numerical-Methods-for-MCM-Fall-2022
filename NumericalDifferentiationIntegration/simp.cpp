#include <iostream>
#include <cmath>

#define pi 3.14159265358979323846

double f(double x) {
    return sin(x);
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
    s = s * dx / 3;
    return s;
}


int main() {
    double a, b;
    std::cout << "[a b] = ";
    std::cin >> a >> b;
    int N;
    std::cout << "Number of discretized points: ";
    std::cin >> N;

    double result = Simpson(f, a, b, N);
    std::cout << "Simpson rule\n";
    std::cout << result << "\n";
    printf("%e\n", result);
    
    return 0;
}
