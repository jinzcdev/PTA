# https://pintia.cn/problem-sets/994805046380707840/problems/1386335159927652355
n, p = map(int, input().split())
for _ in range(n):
    a = float(input())
    if a < p:
        print('On Sale! %.1f' % a)
