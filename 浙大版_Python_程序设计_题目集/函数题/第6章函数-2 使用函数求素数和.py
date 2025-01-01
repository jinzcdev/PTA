# https://pintia.cn/problem-sets/1111652100718116864/exam/problems/type/6?problemSetProblemId=1163035698160459777
def prime(p):
    if p <= 1:
        return False
    i = 2
    while i * i <= p:
        if p % i == 0:
            return False
        i = i + 1
    return True


def PrimeSum(m, n):
    sum = 0
    for i in range(m, n + 1):
        if prime(i):
            sum = sum + i
    return sum

