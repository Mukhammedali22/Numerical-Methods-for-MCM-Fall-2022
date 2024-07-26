def f(x):
    return x**2 + 3*x - 4

def dfdx(x):
    return 2*x + 3

def forward_difference(f, x, dx=0.01):
    """Forward difference scheme with appoximation error O(h)"""
    return (f(x + dx) - f(x)) / dx

def backward_difference(f, x, dx=0.01):
    """Backward difference scheme with appoximation error O(h)"""
    return (f(x) - f(x - dx)) / dx

def central_difference(f, x, dx=0.01):
    """Central difference scheme with appoximation error O(h^2)"""
    return (f(x + dx) - f(x - dx)) / (2*dx)

def central_h4(f, x, dx=0.01):
    """Centreped formula with appoximation error O(h^4)"""
    return (-f(x + 2*dx) + 8*f(x + dx) - 8*f(x - dx) + f(x - 2*dx)) / (12*dx)

def error_evaluation(F, N, f, x, dx=0.01):
    print(N.__doc__)
    exact = F(x)
    numeric = N(f, x, dx)
    error = exact - numeric
    print(f"Exact: {exact}")
    print(f"Numeric: {numeric}")
    print(f"Absolute error: {abs(error)}")


x = float(input("x = "))

error_evaluation(dfdx, forward_difference, f, x)
error_evaluation(dfdx, backward_difference, f, x)
error_evaluation(dfdx, central_difference, f, x)
error_evaluation(dfdx, central_h4, f, x)
