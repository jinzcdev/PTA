# https://pintia.cn/problem-sets/994805046380707840/problems/1386335159927652359
a, b, n = map(int, input().split())
lst = [a, b]
for i in range(n):
    if len(lst) >= n:
        break
    t = str(lst[i] * lst[i + 1])
    lst = lst + [int(x) for x in t]
    i += 1
print(*lst[:n])