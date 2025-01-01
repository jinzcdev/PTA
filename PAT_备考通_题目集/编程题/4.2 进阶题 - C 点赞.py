# https://pintia.cn/problem-sets/1526027869896364032/exam/problems/type/7?problemSetProblemId=1526202265231478784
n = int(input())
cnt = dict()
for _ in range(n):
    d = list(map(int, input().split()))[1:]
    for x in d:
        cnt[x] = cnt.get(x, 0) + 1
ans, MAX = 0, -1
for k in cnt:
    if cnt[k] > MAX:
        MAX = cnt[k]
        ans = k
    elif cnt[k] == MAX:
        ans = max(ans, k)
print(ans, MAX)