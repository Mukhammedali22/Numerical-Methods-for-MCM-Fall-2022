# Solve f(x) = 0
# Secant method
# x_{n+1} = x_{n} - f(x_{n})*(x_{n} - x_{n-1}) / (f(x_{x} - f(x_{n-1}))
# Two-point iteration formula
# Look lecture 5

def f(x):
    return x**3 + 3*x - 1
    # return x**2 - x - 3

def Secant_method(f, p0, p1, eps=1e-6, stop_iteration=1000):
    """The Secant method for solving f(x) = 0"""
    for i in range(stop_iteration):
        p = p1 - f(p1) * (p1 - p0) / (f(p1) - f(p0))
        print(f"{i}\t{p1}")

        if abs(p - p1) < eps:
            return p

        p0 = p1
        p1 = p

    return p


print("The Secant method")
p0 = float(input("p0 = "))
p1 = float(input("p1 = "))
P = Secant_method(f, p0, p1)
print(f"Solution x = {P}")
