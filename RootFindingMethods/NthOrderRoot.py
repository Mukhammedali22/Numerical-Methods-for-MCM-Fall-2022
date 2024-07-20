# f(x) = x^N - A
# N is positive number
# solve f(x) = 0
def Find_Nth_root(p0, A, N=2, eps=1e-6, stop_iteration=1000):
    for i in range(stop_iteration):
        p = ((N - 1)*p0 + A / p0**(N - 1)) / N

        print(f"{i}\t{p}")

        if abs(p - p0) < eps:
            return p
        
        p0 = p

    return p


print("f(x) = x^N - A")
N = float(input("N = "))
A = float(input("A = "))
p0 = float(input("p0 = "))
P = Find_Nth_root(p0, A, N)
F = A**(1/N)
print(f"Numerical solution: {P}")
print(f"Exact solution: {F}")
print(f"Absolute error {abs(F - P)}")
