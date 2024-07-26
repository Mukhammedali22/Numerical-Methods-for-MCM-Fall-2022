from math import (pi, exp, sin, cos)


def f(x):
    return sin(x)

def Simpson(f, a, b, N):
    """Simpson rule for numerical integration"""
    # number of subdivisions must be even so
    # number of points will be odd
    N = N + (N + 1) % 2
    dx = (b - a) / (N - 1)

    s = f(a)
    for i in range(1, N-1):
        s = s + f(a + i*dx) * (4 if i % 2 == 1 else 2)
    s = s + f(b)
    return s * dx / 3


a, b = map(eval, input("a, b = ").split(", "))
N = int(input("Number of discretized points: "))

print(Simpson.__doc__)
print(Simpson(f, a, b, N))
