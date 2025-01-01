# https://pintia.cn/problem-sets/1526027869896364032/exam/problems/type/7?problemSetProblemId=1526202787833364480
n, k, x = map(int, input().split())
arr = [[] for _ in range(n)]
for i in range(n):
    for j, val in enumerate(map(int, input().split())):
        arr[j].append(val)
m = 0
for i in range(1, n, 2):
    m = m % k + 1
    arr[i][m:] = arr[i][:n - m]
    arr[i][:m] = [x] * m
ans = []
for i in range(n):
   sum = 0
   for j in range(n):
      sum += arr[j][i]
   ans.append(sum)
print(" ".join(list(map(str, ans))))