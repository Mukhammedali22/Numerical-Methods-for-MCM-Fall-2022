#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


void print_vector(std::vector<double> v, std::string sep=" ", 
                    std::string end="\n") {
    // Prints values of vector to the console
    int N = v.size();
    for (int i = 0; i < N; ++i) {
        std::cout << v[i];
        if (i != N-1) {
            std::cout << sep;
        }
    }
    std::cout << end;
}

bool checkDiagonalDominant(std::vector<std::vector<double>> A) {
    int N = A.size();
    int M = A[0].size();

    if (N != M) {
        std::cout << "A is not square\n";
        return false;
    }

    std::vector<int> maxval(N);
    std::vector<int> maxind(N);

    for (int i = 0; i < N; ++i) {
        double maxx = 0;
        double indx = 0;

        for (int j = 0; j < N; ++j) {
            if (maxx < abs(A[i][j])) {
                maxx = abs(A[i][j]);
                indx = j;
            }
        }
        
        maxval[i] = maxx;
        maxind[i] = indx;
    }

    std::vector<int> v = maxind;
    sort(v.begin(), v.end());

    for (int i = 0; i < N; ++i) {
        double s = 0;
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                s += abs(A[i][j]);
            }
        }

        // check diagonal dominance condition
        if (maxval[i] <= s or v[i] != i) { 
            return false;
        }
    }

    return true;    
}

std::vector<double> Jacobi_iterative_method(std::vector<std::vector<double>> A, std::vector<double> B, 
                                        std::vector<double> p0, double eps=1e-9, int stop_iteration=1000){
    // Jacobi iterative method
    int N = A.size();
    std::vector<double> p = p0;

    for (int n = 0; n < stop_iteration; ++n) {
        for (int i = 0; i < N; ++i) {
            double s = 0;
            for (int j = 0; j < N; ++j) {
                if (i != j) {
                    s += A[i][j] * p0[j];
                }
            }

            p[i] = (B[i] - s) / A[i][i];
        }

        std::cout << "i: " << n << "\tsol: ";
        print_vector(p);

        double maxx = 0;
        for (int i = 0; i < N; ++i) {
            if (maxx < fabs(p[i] - p0[i])) {
                maxx = fabs(p[i] - p0[i]);
            }
        }

        if (maxx < eps) {
            return p;
        }

        p0 = p;
    }

    return p;
}

int main(){
    int N;
    std::cout << "N = ";
    std::cin >> N;

    std::vector<std::vector<double>> A(N, std::vector<double> (N, 0));
    std::vector<double> B(N, 0);
    std::vector<double> p0(N, 0);
    std::vector<double> p(N, 0);

    std::cout << "A = \n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> A[i][j];
        }
    }

    std::cout << "B = ";
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }

    std::cout << "p0 = ";
    for (int i = 0; i < N; ++i) {
        std::cin >> p0[i];
    }

    if (!checkDiagonalDominant(A)) {
        std::cout << "Sorry, but this matrix can never be made to be diagonally dominant.";
    } else {
        std::vector<double> p = Jacobi_iterative_method(A, B, p0);
        std::cout << "Solution: ";
        print_vector(p);
    }

    return 0;
}
