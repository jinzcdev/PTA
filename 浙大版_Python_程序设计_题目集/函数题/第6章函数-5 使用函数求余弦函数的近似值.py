# https://pintia.cn/problem-sets/1111652100718116864/exam/problems/type/6?problemSetProblemId=1163035698160459781
def fac(x):
    tmp = 1
    for i in range(1, x + 1):
        tmp *= i
    return tmp


def funcos(eps, x):
    ans = 0.0
    i = 0
    while True:
        tmp = x**(i*2) / fac(i * 2)
        if tmp < eps:
            break
        if i % 2 == 1:
            tmp = -tmp
        ans += tmp
        i += 1
    return ans