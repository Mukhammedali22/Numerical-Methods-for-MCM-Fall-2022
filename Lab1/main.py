import numpy as np
import sympy as sp
import matplotlib.pyplot as plt
import matplotlib.animation as animation


def FPI_util(f:str, a, b):
    x = sp.symbols("x")
    f = sp.sympify(f)
    f_ans = f
    g = "x" + f" - ({f})"
    g_ans = g
    g = sp.sympify(g)
    dgdx = sp.diff(g, x)

    if a < g.subs(x, a) <= b and a <= g.subs(x, b) < b:
        print(f"g(x) has a fixed point at region [{a}, {b}].")
    else:
        # when it is diverges
        g = f"x - ({f}) / M"
        dfdx = sp.diff(f, x)
        M = int(max(dfdx.subs(x, a), dfdx.subs(x, b)) + 0.5)
        # g = g.subs("M", M)
        g = g.replace("M", f"{M}")
        g_ans = g
        g = sp.sympify(g)
        dgdx = sp.diff(g, x)

        if a < g.subs(x, a) <= b and a <= g.subs(x, b) < b:
            print(f"g(x) has a fixed point at region [{a}, {b}].")

    if abs(dgdx.subs(x, a)) < 1 and abs(dgdx.subs(x, b)) < 1: 
        print(f"g(x) has a unique fixed point at region [{a}, {b}].")   

    print("g(x) =", g_ans)
    print("g'(x) =", dgdx)

    f = sp.lambdify(x, f)
    g = sp.lambdify(x, g)
    return f, g, f_ans, g_ans


def fixed_point_iteration(g, p0, eps=1e-6, stop_iteration=1000):
    history = {}
    iteration = 0
    while iteration < stop_iteration:
        p = g(p0)
        history[p0] = p
        maximum = abs(p - p0)
        if maximum < eps:
            break

        print(f"{iteration}\t{p}")
        p0 = p
        iteration += 1

    return p, history


# User defined function
f = input("f(x) = ")
a, b = map(eval, input("a, b = ").split(", "))
p0 = eval(input("p0 = "))
N = int(input("Number of points between a and b: "))
# dx = eval(input("dx = "))

# N = int((b - a) / dx) + 1
dx = (b - a) / (N - 1)
x = a + np.arange(0, N) * dx

f, g, f_name, g_name = FPI_util(f, a, b)
P, data = fixed_point_iteration(g, p0)

points = list(data.items())

def update(frame):
    if frame < len(points) - 2:
        plt.title("Fixed point iteration")
        x_d = [points[frame][0], points[frame+1][0]]
        y_d = [points[frame][1], points[frame+1][1]]
        plt.plot(x_d, y_d, "--", c="blue")
        plt.scatter(x_d, y_d, c="red")
    else:
        plt.plot(np.ones(10)*P, np.linspace(0, P, 10), "--", c="red")
        plt.plot(np.linspace(0, P, 10), np.ones(10)*P, "--", c="red")
        plt.scatter(P, P, label="Intersection of g(x) and y=x")
        plt.scatter(P, f(P), s=20, c="red", label=f"Solution at x={P:.3f}")
        plt.plot(x, f(x), label=f"f(x)={f_name}")
        plt.plot(x, g(x), label=f"g(x)={g_name}")
        plt.plot(x, x, label="y=x")
        plt.legend()
        plt.savefig("Result.png")

    plt.axhline(y=0, color='black')
    plt.axvline(x=0, color='black')
    plt.xlabel("x")
    plt.ylabel("y")


fig, ax = plt.subplots(figsize=(6, 5))
ani = animation.FuncAnimation(fig=fig, func=update, frames=len(data)-1, interval=500)
ani.save(filename=f"FixedPointIteration.gif", writer="pillow")

print(f"Solution is x = {P:.6f}")
print(f"f({P:.6f}) = {f(P):.6f}")

# plt.plot(np.ones(10)*P, np.linspace(0, P, 10), "--", c="red")
# plt.plot(np.linspace(0, P, 10), np.ones(10)*P, "--", c="red")
# plt.scatter(P, P, label="Intersection of g(x) and y=x")
# plt.scatter(P, f(P), s=20, c="red", label=f"Solution at x={P:.3f}")
# plt.plot(x, f(x), label=f"f(x)={f_name}")
# plt.plot(x, g(x), label=f"g(x)={g_name}")
# plt.plot(x, x, label="y=x")
# # plt.axis("equal")
# plt.grid()
# plt.axhline(y=0, color='black')
# plt.axvline(x=0, color='black')
# plt.legend()
# plt.xlabel("x")
# plt.ylabel("y")
# plt.show()
