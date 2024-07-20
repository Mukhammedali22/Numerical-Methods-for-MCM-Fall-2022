#include <iostream>
#include <cmath>


// Newton-Raphson method
// x_{n+1} = x_{n} - f(x) / f'(x)
// Look lecture 4

// f'(x) = (f(x+dx) - f(x-dx)) / (2*dx)
// central scheme, approximation error O(dx^2)

double f(double x){
    return pow(x, 3) + 3*x - 1;
}

double Newton_Raphson_method(double (*f)(double x), double p0, double dx=0.01, 
                                double eps=1e-6, int stop_iteration=1000){
    double p;
    for (int i = 0; i < stop_iteration; ++i)
    {
        p = p0 - f(p0) / ((f(p0 + dx) - f(p0 - dx)) / (2*dx));

        printf("iter = %d\tp = %f\n", i, p);

        if (fabs(p - p0) < eps) {return p;}

        p0 = p;
    }

    return p;
}


int main(){
    double p0;
    std::cout << "p0 = ";
    std::cin >> p0;
    double P = Newton_Raphson_method(f, p0);
    std::cout << "Solution x = " << P << "\n";
}
