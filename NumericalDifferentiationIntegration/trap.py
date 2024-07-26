from math import (pi, exp, sin, cos)


def f(x):
    return sin(x)

def Trapezoidal(f, a, b, N):
    """Trapezoidal rule for numerical integration"""
    dx = (b - a) / (N - 1)

    s = 0
    for i in range(N-1):
        # Area = Height * Base / 2
        x = a + i*dx
        s += (f(x) + f(x + dx)) * dx / 2
    
    return s

a, b = map(eval, input("a, b = ").split(", "))
N = int(input("Number of discretized points: "))

print(Trapezoidal.__doc__)
print(Trapezoidal(f, a, b, N))
