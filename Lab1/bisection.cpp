#include <iostream>
#include <cmath>


// f(x) = 0
// find x in [a, b]
// f(a) and f(b) must be opposite signs

// user defined function
double f(double x){
    return pow(x, 3) + 3*x - 1;
}

double Bisection_method(double (*f)(double x), double a, double b, 
                            double eps=1e-6){
    double a1 = f(a);
    double b1 = f(b);

    int N = (log(b - a) - log(eps)) / log(2) + 1;

    double c;
    double c1;

    printf("%-5s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", 
            "i", "a", "c", "b", "f(a)", "f(c)", "f(b)");
    
    for(int i = 0; i < N; ++i){
        c = (a + b) / 2;
        c1 = f(c);

        printf("%-5d\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n", 
                i, a, c, b, a1, c1, b1);

        if(c1 == 0){
            a = c;
            b = c;
        }else if(a1 * c1 < 0){
            b = c;
            b1 = c1;
        }else if(c1 * b1 < 0){
            a = c;
            a1 = c1;
        }

        if (fabs(c1) < eps) {return c;}
        if ((b - a) < eps) {return c;}
    }

    return c;
}

double Bisection_recursion(double (*f)(double x), double a, double b, 
                            int i=0, int N=100, double eps=1e-6){
    double a1 = f(a);
    double b1 = f(b);

    double c = (a + b) / 2;
    double c1 = f(c);

    if(i == 0){
        N = (log(b - a) - log(eps)) / log(2) + 1;  
        printf("%-5s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", 
                "i", "a", "c", "b", "f(a)", "f(c)", "f(b)");
    }

    printf("%-5d\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n", 
            i, a, c, b, a1, c1, b1);

    if(c1 == 0){
        a = c;
        b = c;
    }else if(a1 * c1 < 0){
        b = c;
        b1 = c1;
    }else if(c1 * b1 < 0){
        a = c;
        a1 = c1;
    }

    if (i == N) {return c;}
    if (fabs(c1) < eps) {return c;}
    if ((b - a) < eps) {return c;}

    return Bisection_recursion(f, a, b, i+1, N);
}

int main(){
    double a, b;
    std::cout << "a, b = ";
    std::cin >> a >> b;
    double P = Bisection_method(f, a, b);
    std::cout << "Solution x = " << P << "\n";
    P = Bisection_recursion(f, a, b);
    std::cout << "Solution x = " << P << "\n";
}
