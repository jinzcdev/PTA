# https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805074646122496
n = int(input())
name, num = [], []
ans = -1
min_loss = 99999
for _ in range(n):
    a, b = input().split()
    name.append(a)
    num.append(int(b))
avg = sum(num) // (2 * n)
for i in range(n):
    tmp = abs(avg - num[i])
    if tmp < min_loss:
        min_loss = tmp
        ans = i
print(avg, name[ans])

