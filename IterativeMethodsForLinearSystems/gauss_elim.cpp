#include <iostream>
#include <cmath>
#include <vector>


// The Gaussian Elimination algorithm for solving system of linear equations
// Elementary row operations
// 1. Interchanges
// 2. Scaling
// 3. Replacement

// Passing by value
void print_vector(std::vector<double> v, std::string sep=" ", 
                    std::string end="\n") {
    // Prints values of 1D vector to the console
    int N = v.size();
    for (int i = 0; i < N; ++i) {
        std::cout << v[i];
        if (i != N-1) {
            std::cout << sep;
        }
    }
    std::cout << end;
}

// Passing by reference
void print_2Dvector(std::vector<std::vector<double>> &v, std::string sep=" ", 
                    std::string end="\n") {
    // Prints values of 2D vector to the console
    int N = v.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            std::cout << v[i][j];
            if (j != v[i].size()-1) {
                std::cout << sep;
            }
        }
        std::cout << end;
    }
}

// Passing by reference
std::vector<double> Gaussian_Elimination(std::vector<std::vector<double>> &Aug) {
    int N = Aug.size();
    int M = Aug[0].size();

    if (N != M-1) {
        std::cout << "Matrix is not square";
        return std::vector<double>();
    }

    if (Aug[N-1][N-1] == 0) {
        std::cout << "No solution";
        return std::vector<double>();
    }

    std::vector<double> temp(N+1, 0);

    for (int p = 0; p < N-1; ++p) {
        int j = p;
        double maxx = 0;
        for (int k = p; k < N; ++k) {
            if (maxx < fabs(Aug[k][p])) {
                maxx = fabs(Aug[k][p]);
                j = k;
            }
        }

        for (int i = 0; i < N+1; ++i) {
            temp[i] = Aug[p][i];
            Aug[p][i] = Aug[j][i];
            Aug[j][i] = temp[i];
        }

        if (Aug[p][p] == 0) {
            std::cout << "No unique solution";
            return std::vector<double>();
        }

        for (int k = p+1; k < N; ++k) {
            double m = Aug[k][p] / Aug[p][p];
            for (int i = 0; i < p+1; ++i) {
                Aug[k][i] = 0;
            }
            for (int i = p+1; i < N+1; ++i) {
                Aug[k][i] = Aug[k][i] - m * Aug[p][i];
            }
        }
    }

    std::vector<double> x(N, 0);

    for (int k = N-1; k >= 0; --k) {
        double s = 0;
        for (int i = k+1; i < N; ++i) {
            s = s + Aug[k][i] * x[i];
        }
        x[k] = (Aug[k][N] - s) / Aug[k][k];
    }

    return x;
}


int main() {
    int N;
    std::cout << "N = ";
    std::cin >> N;
    std::vector<std::vector<double>> Aug(N, std::vector<double> (N+1, 0));

    std::cout << "Augmented matrix:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N+1; ++j) {
            std::cin >> Aug[i][j];
        }
    }

    std::vector<double> x = Gaussian_Elimination(Aug);

    std::cout << "Solution vector x:\n";
    print_vector(x);
    std::cout << "Augmented matrix after row operations:\n";
    print_2Dvector(Aug);

    return 0;
}
