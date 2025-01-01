# https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1386335159927652358
n = int(input())
lst = map(int, input().split())
Min, Max = 9999999, -1
d = {}
for x in lst:
    Min = min(Min, x)
    Max = max(Max, x)
    d[x] = d.get(x, 0) + 1
print(Min, d[Min])
print(Max, d[Max])