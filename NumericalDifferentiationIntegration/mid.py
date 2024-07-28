from math import (pi, exp, sin, cos)

def f(x):
    return sin(x)

def Midpoint(f, a, b, N):
    """Midpoint rule for numerical integration"""
    dx = (b - a) / (N - 1)

    s = 0
    for i in range(N-1):
        x = a + i*dx
        s += f(x + 0.5*dx) * dx
    
    return s

a, b = map(eval, input("a, b = ").split(", "))
N = int(input("Number of discretized points: "))

print(Midpoint.__doc__)
print(Midpoint(f, a, b, N))
