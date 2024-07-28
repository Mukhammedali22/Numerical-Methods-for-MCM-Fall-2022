import matplotlib.pyplot as plt
import numpy as np
from numpy import (pi, exp, sin, cos)


# 2 variant
# y' = y - 3x, y(1) = 0, x=[1, 2.2], h=0.3

# y' = f(x, y)
def f(x, y):
    return  y - 3*x


# Exact solution when y(0) = 1
def F(x):
    return 3*(x + 1) - 6*exp(-1) * exp(x)


def Euler(f, a, b, y0, N):
    """Euler's method for solving the I.V.P (Initial Value Problem)
    Approximation error O(h)"""
    print("Euler's method")
    dx = (b - a) / (N - 1)
    t = a + np.arange(0, N) * dx
    y = np.zeros(N)

    y[0] = y0    
    for i in range(N-1):
        y[i+1] = y[i] + f(t[i], y[i]) * dx
        print(f"{t[i]:.3f}, {y[i]:.6f}")

    print(f"{t[-1]:.3f}, {y[-1]:.6f}")
    return y


def Heun(f, a, b, y0, N):
    """Heun's method for solving the I.V.P (Inital Value Problem)
    Approximation error O(h^2)"""
    print("Heun's method")
    dx = (b - a) / (N - 1)
    t = a + np.arange(0, N) * dx
    y = np.zeros(N)

    y[0] = y0    
    for i in range(N-1):
        p = y[i] + dx * f(t[i], y[i])
        y[i+1] = y[i] + (f(t[i], y[i]) + f(t[i+1], p)) * dx / 2
        print(f"{t[i]:.3f}, {y[i]:.6f}")

    print(f"{t[-1]:.3f}, {y[-1]:.6f}")
    return y


a, b = map(eval, input("a, b = ").split(", "))
y0 = float(input(f"y({a}) = "))
dx = float(input("Step size h = "))

N = int((b - a) / dx) + 1

y = Euler(f, a, b, y0, N)
y1 = Heun(f, a, b, y0, N)

x = a + np.arange(0, N) * dx
Y = F(x)

abs_err = np.max(np.abs(Y - y))
abs_err1 = np.max(np.abs(Y - y1))

print(f"Step size: {dx:e}")
print(Euler.__doc__)
print(f"Absolute error (Euler): {abs_err:e}")
print(Heun.__doc__)
print(f"Absolute error (Heun): {abs_err1:e}")

plt.title("ODE")
plt.plot(x, y, "--", label="Euler")
plt.plot(x, y1, "--", label="Heun")
plt.plot(x, Y, label="Exact")
plt.grid()
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.show()
