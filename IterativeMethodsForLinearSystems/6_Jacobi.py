# Jacobi iterative method
# Look lecture 6

# 4x - y + z = 7
# 4x - 8y + z = -21
# -2x + y + 5z = 15

# x = (7 + y - z) / 4
# y = (21 + 4x + z) / 8
# z = (15 + 2x - y) / 5

def checkDiagonalDominant(A) -> bool:  
    N = len(A)
    M = len(A[0])

    if N != M:
        print("A is not square")
        return False
    
    maxval = [0 for i in range(N)]
    maxind = [0 for i in range(N)]

    for i in range(N):
        maxx = 0
        indx = 0
        for j in range(N):
            if maxx < abs(A[i][j]):
                maxx = abs(A[i][j])
                indx = j

        maxval[i] = maxx
        maxind[i] = indx

    for i in range(N):
        s = 0
        for j in range(N):
            if i != j:
                s += abs(A[i][j])
        
        # check for diagonal dominance 
        if maxval[i] <= s or sorted(maxind) != list(range(N)):
            return False
        
    return True


def Jacobi_iterative_method(A, B, p0, eps=1e-9, stop_teration=1000):    
    N = len(A)
    p = [0 for i in range(N)]

    for n in range(stop_teration):
        for i in range(N):
            # 1 way
            # a_s = A[i][:i] + A[i][i+1:]
            # p_s = p[:i] + p0[i+1:]
            # s = sum([a_i * p_i for a_i, p_i in zip(a_s, p_s)])
            
            # 2 way
            s = 0
            for j in range(N):
                if i != j:
                    s += A[i][j] * p0[j]
            
            p[i] = (B[i] - s) / A[i][i]
        
        print(n, p)

        if max(map(abs, [a_i - b_i for a_i, b_i in zip(p0, p)])) < eps:
            return p

        p0[:] = p[:]

    return p


N = int(input("N = "))
A = [0 for i in range(N)]
B = [0 for i in range(N)]
p0 = [0 for i in range(N)]

print("A:")
for i in range(N):
    A[i] = list(map(float, input().split()))

print("B:")
B[0:N] = list(map(float, input().split()))

print("p0:")
p0[0:N] = list(map(float, input().split()))

if not checkDiagonalDominant(A):
    print("Sorry, but this matrix can never be made to be diagonally dominant")
else:
    p = Jacobi_iterative_method(A, B, p0)

    print("A:")
    print("[", *A, "]", sep="\n")
    print("B:")
    print(B)
    print("Solution:")
    print(p)
