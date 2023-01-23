# https://pintia.cn/problem-sets/994805046380707840/problems/1386335159927652353
n, m, k = map(int, input().split())
n -= m * k
print('%d' % n if n >= 0 else 0)