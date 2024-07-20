#include <iostream>
#include <cmath>


// f(x) = x^N - A
// N is positive number
// Solve f(x) = 0
// Look 4 lecture

double Find_Nth_root(double p0, double A, double N=2, 
                        double eps=1e-6, int stop_iteration=1000){
    double p;
    for (int i = 1; i <= stop_iteration; ++i)
    {
        p = ((N - 1)*p0 + A / pow(p0, N-1)) / N;

        printf("iter = %d\tp = %f\n", i, p);
     
        if (fabs(p - p0) < eps) {return p;}

        p0 = p;
    }

    return p;
}


int main(){
    double p0, A, N;

    std::cout << "N = ";
    std::cin >> N;
    std::cout << "A = ";
    std::cin >> A;
    std::cout << "p0 = ";
    std::cin >> p0;

    double P = Find_Nth_root(p0, A, N);
    double F = pow(A, 1/N);
    
    std::cout << "Solution x = " << P << "\n";
    std::cout << "Numerical solution: " << P << "\n";
    std::cout << "Exact solution: " << F << "\n";
    std::cout << "Absolute error: " << fabs(F - P) << "\n";
    return 0;
}
