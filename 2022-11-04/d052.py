import bisect
T = int(input())
for i in range(T):
    N = int(input())
    Nums = [int(input()) for _ in range(N)]
    A = list(reversed(Nums)) + Nums

    L = 0
    V = []
    for i in A:
        if len(V) == 0 or V[-1] < i:
            V.append(i)
        V[bisect.bisect_right(V, i-1)] = i
    print(len(V))
