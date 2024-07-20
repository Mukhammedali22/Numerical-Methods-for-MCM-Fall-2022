import numpy as np
from numpy import (pi, exp, sin, cos)
import matplotlib.pyplot as plt


# f(x) = 0
# find x in [a, b]
# f(a) and f(b) must be opposite signs

# user defined function
def f(x):
    return x**3 + 3*x - 1

def Bisection_method(f, a, b, eps=1e-6):
    """Bisection method"""
    a1 = f(a)
    b1 = f(b)

    if a1 * b1 > 0:
        raise Exception("f(a) and f(b) has the same sign!\nThe Bisection method won't work.")
    
    print(f"{"i":5}\t{"a":10}\t{"c":10}\t{"b":10}\t{"f(a)":10}\t{"f(c)":10}\t{"f(b)":10}")
    
    stop_iteration = int((np.log(b - a) - np.log(eps)) / np.log(2)) + 1
    for i in range(stop_iteration):
        c = (a + b) / 2
        c1 = f(c)

        print(f"{i:<5}\t{a:.6f}\t{c:.6f}\t{b:.6f}\t{a1:.6f}\t{c1:.6f}\t{b1:.6f}")

        if c1 == 0:
            a, b = c, c
        elif a1 * c1 < 0:
            b, b1 = c, c1
        elif c1 * b1 < 0:
            a, a1 = c, c1

        if abs(c1) < eps:
            break
        
        if (b - a) < eps:
            break

    return c


def Bisection_recursion(f, a, b, i=0, N=100, eps=1e-6):
    """Recursively designed function of the bisection method."""
    a1 = f(a)
    b1 = f(b)

    if a1 * b1 > 0:
        raise Exception("f(a) and f(b) has the same sign!\nThe Bisection method won't work.")

    if i == 0:
        N = int((np.log(b - a) - np.log(eps)) / np.log(2)) + 1
        print(f"{"i":5}\t{"a":10}\t{"c":10}\t{"b":10}\t{"f(a)":10}\t{"f(c)":10}\t{"f(b)":10}")

    c = (a + b) / 2
    c1 = f(c)

    print(f"{i:<5}\t{a:.6f}\t{c:.6f}\t{b:.6f}\t{a1:.6f}\t{c1:.6f}\t{b1:.6f}")

    if c1 == 0:
        a, b = c, c
    elif a1 * c1 < 0:
        b, b1 = c, c1
    elif c1 * b1 < 0:
        a, a1 = c, c1
    
    if i == N:
        return c

    if abs(c1) < eps:
        return c
    
    if (b - a) < eps:
        return c
    
    return Bisection_recursion(f, a, b, i+1, N)


a, b = map(eval, input("a, b = ").split(", "))
N = 100
dx = (b - a) / (N - 1)
x = a + np.arange(0, N) * dx

P = Bisection_method(f, a, b)
P = Bisection_recursion(f, a, b)
print(P)

plt.plot(x, f(x), label="f(x)")
plt.scatter(P, f(P), c="red", label=f"Solution x={P:.3f}")
plt.grid()
plt.axhline(y=0, c="black")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.show()
