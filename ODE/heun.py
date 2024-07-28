from math import (pi, exp, sin, cos)
import matplotlib.pyplot as plt

def f(t, y):
    return (t - y) / 2

# Exact solution when y(0) = 1
def F(t):
    return 3*exp(-t / 2) - 2 + t 

def Heun(f, a, b, y0, N):
    """Heun's method for solving the I.V.P (Inital Value Problem)
    Approximation error O(h^2)"""
    dt = (b - a) / (N - 1)
    t = [a + i*dt for i in range(N)]
    y = [0 for i in range(N)]

    y[0] = y0    
    for i in range(N-1):
        p = y[i] + dt*f(t[i], y[i])
        y[i+1] = y[i] + (f(t[i], y[i]) + f(t[i+1], p)) * dt / 2
        print(f"{t[i]:.3f}, {y[i]:.6f}")

    print(f"{t[-1]:.3f}, {y[-1]:.6f}")
    return y


# a=0, b=3, y0=1
a, b = map(eval, input("a, b = ").split(", "))
y0 = eval(input(f"y({a}) = "))
N = int(input("Number of discretized points: "))

y = Heun(f, a, b, y0, N)

dt = (b - a) / (N - 1)
t = [a + i*dt for i in range(N)]
Y = [F(t[i]) for i in range(N)]

abs_err = max([abs(Y[i] - y[i]) for i in range(N)])
print(Heun.__doc__)
print(f"Step size: {dt:e}")
print(f"Absolute error: {abs_err:e}")

plt.title("Heun's method")
plt.plot(t, y, "--", label="Numerical")
plt.plot(t, Y, label="Exact")
plt.grid()
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.show()
