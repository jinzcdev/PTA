# https://pintia.cn/problem-sets/1111652100718116864/exam/problems/1163035698160459779
def fib(n):
    if n <= 1:
        return 1
    a, b = 1, 1
    num = 1
    while num < n:
        a, b = b, a + b
        num += 1
    return b


def PrintFN(m, n):
    a, b = 1, 1
    ans = []
    while b <= n:
        if m <= b <= n:
            ans.append(b)
        a, b = b, a + b
    return ans