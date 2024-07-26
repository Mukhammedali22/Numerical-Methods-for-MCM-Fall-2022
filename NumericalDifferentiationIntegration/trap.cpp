#include <iostream>
#include <cmath>

#define pi 3.14159265358979323846

double f(double x) {
    return sin(x);
}

// Trapezoidal rule for numerical integration
double Trapezoidal(double (*f)(double x), double a,
                    double b, int N) {
    double dx = (b - a) / (N - 1);
    double x = a;

    double s = 0;
    for (int i = 0; i < N-1; ++i) {
        x = a + i*dx;
        s += (f(x) + f(x + dx)) * dx / 2;
    }

    return s;
}


int main() {
    double a, b;
    std::cout << "[a b] = ";
    std::cin >> a >> b;
    int N;
    std::cout << "Number of discretized points: ";
    std::cin >> N;

    double result = Trapezoidal(f, a, b, N);
    std::cout << "Trapezoidal rule\n";
    std::cout << result << "\n";
    printf("%e\n", result);
    
    return 0;
}
