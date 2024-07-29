from math import (pi, exp, sin, cos, sqrt)
import matplotlib.pyplot as plt


def f(t, y):
    return (t - y) / 2

# Exact solution when y(0) = 1
def F(t):
    return 3*exp(-t / 2) - 2 + t 

def Runge_Kutta(f, a, b, y0, N):
    """Runge-Kutta method for solving the I.V.P (Inital Value Problem)
    Approximation error O(h^4)"""

    dt = (b - a) / (N - 1)
    t = [a + i*dt for i in range(N)]
    y = [0 for i in range(N)]
    
    y[0] = y0
    for i in range(N-1):
        f1 = f(t[i], y[i])
        f2 = f(t[i] + 0.5*dt, y[i] + 0.5*dt*f1)
        f3 = f(t[i] + 0.5*dt, y[i] + 0.5*dt*f2)
        f4 = f(t[i] + dt, y[i] + dt*f3)

        y[i+1] = y[i] + dt * (f1 + 2*f2 + 2*f3 + f4) / 6

        print(f"{t[i]:.3f}, {y[i]:.6f}")

    print(f"{t[-1]:.3f}, {y[-1]:.6f}")

    return y


# a=0, b=3, y0=1
a, b = map(eval, input("a, b = ").split(", "))
y0 = eval(input(f"y({a}) = "))
N = int(input("Number of discretized points: "))

y = Runge_Kutta(f, a, b, y0, N)

dt = (b - a) / (N - 1)
t = [a + i*dt for i in range(N)]
Y = [F(t[i]) for i in range(N)]

abs_err = max([abs(Y[i] - y[i]) for i in range(N)])

print(Runge_Kutta.__doc__)
print(f"Step size: {dt:e}")
print(f"Absolute error: {abs_err:e}")

plt.title("Runge-Kutta method")
plt.plot(t, y, "--", label="Numerical")
plt.plot(t, Y, label="Exact")
plt.grid()
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.show()
