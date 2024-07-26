#include <iostream>
#include <cmath>

double f(double x) {
    return x*x + 3*x - 4;
}

double dfdx(double x) {
    return 2*x + 3;
}

double forward_difference(double x, double dx=0.01) {
    // Forward difference scheme with appoximation error O(h)
    return (f(x + dx) - f(x)) / dx;
}

double backward_difference(double x, double dx=0.01) {
    // Backward difference scheme with appoximation error O(h)
    return (f(x) - f(x - dx)) / dx;
}

double central_difference(double x, double dx=0.01) {
    // Central difference scheme with appoximation error O(h^2)
    return (f(x + dx) - f(x - dx)) / (2*dx);
}

void error_evaluation(double (*f)(double x, double dx), 
                        double x, double dx=0.01, std::string name="diff") {
    double exact = dfdx(x);
    double numeric = f(x, dx);
    double error = exact - numeric;

    printf("Method: %s\n", name.c_str());
    printf("Exact: %e\n", exact);
    printf("Numeric: %e\n", numeric);
    printf("Absolute error: %e\n", fabs(error));
}


int main() {
    double x, dx;
    std::cout << "x = ";
    std::cin >> x;
    std::cout << "dx = ";
    std::cin >> dx;
    error_evaluation(forward_difference, x, dx, "Forward O(h)");
    error_evaluation(backward_difference, x, dx, "Backward O(h)");
    error_evaluation(central_difference, x, dx, "Central O(h^2)");

    return 0;
}
