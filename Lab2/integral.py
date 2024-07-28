from math import (pi, exp, sin, cos, sqrt)


# 2 variant
def f(x):
    return 3*x*x - sqrt(x)

# Exact solution
def F(x, c=0):
    return x**3 - 2*x*sqrt(x) / 3 + c


def Midpoint(f, a, b, N):
    """Midpoint rule for numerical integration
    Approximation error O(h^2)"""
    dx = (b - a) / (N - 1)

    s = 0
    for i in range(N-1):
        x = a + i*dx
        s += f(x + 0.5*dx) * dx
    
    return s


def Simpson(f, a, b, N):
    """Simpson rule for numerical integration
    Approximation error O(h^4)"""
    # number of subdivision must be even so
    # number of points will be odd
    N = N + (N + 1) % 2
    dx = (b - a) / (N - 1)

    s = f(a)
    for i in range(1, N-1):
        x = a + i*dx 
        s += f(x) * (4 if i % 2 == 1 else 2)
    s += f(b)

    return s * dx / 3


a, b = map(eval, input("a, b = ").split(", "))
N = int(input("n: ")) + 1

y = Midpoint(f, a, b, N)
y1 = Simpson(f, a, b, N)
exact = F(b) - F(a)

abs_err = abs(exact - y)
abs_err1 = abs(exact - y1)

print(f"Midpoint: {y}")
print(f"Simpson:  {y1}")
print(f"Exact:    {exact}")

print(Midpoint.__doc__)
print(f"Absolute error (Midpoint): {abs_err:e}")

print(Simpson.__doc__)
print(f"Absolute error (Simpson): {abs_err1:e}")
