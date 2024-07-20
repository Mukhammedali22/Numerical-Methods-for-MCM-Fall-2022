import numpy as np
from numpy import (pi, exp, sin, cos)
import matplotlib.pyplot as plt


# Newton-Raphson method
# x_{n+1} = x_{n} - f(x) / f'(x)
# Look lecture 4

def f(x):
    return x**3 + 3*x - 1
    # return x**2 - x - 3

def Newton_Raphson_method(f, p0, dx=0.01, eps=1e-6, stop_iteration=1000):
    for i in range(stop_iteration):
        p = p0 - f(p0) / ((f(p0 + dx) - f(p0 - dx)) / (2*dx))
        # f'(x) = (f(x+dx) - f(x-dx)) / (2*dx)
        # central scheme, approximation error O(dx^2)
        print(f"{i}\t{p}")

        if abs(p - p0) < eps:
            return p

        p0 = p

    return p

a, b = map(float, input("a, b = ").split(", "))
p0 = float(input("p0 = "))
N = int(input("Number of points between a and b: "))

P = Newton_Raphson_method(f, p0)
print(P)

dx = (b - a) / (N - 1)
x = a + np.arange(0, N) * dx

plt.plot(x, f(x), label="f(x)")
plt.scatter(P, f(P), label=f"Solution x = {P:.3f}")

plt.grid()
plt.axhline(y=0, c="black")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.show()
