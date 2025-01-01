# https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805081289900032
n = int(input())
a = [[] for i in range(n)]
num = list(map(int, input().split()))
maxlen, cnt = max(num) * 10, -1 if n == 1 else 0
cnt_max = num.count(max(num))
idx_max = num.index(max(num))

pre = 0
flag = True
for j in range(maxlen):
    k = sum([1 if j >= num[i] * 10 else 0 for i in range(n)])
    for i in range(n):
        if j >= num[i] * 10:
            continue
        if k == n - 1:
            if flag and i != pre:
                flag = False
                cnt -= 1
            cnt += 2
        else:
            cnt += 1
        a[i].append(str(cnt))
        pre = i
        

for i in range(n):
    print('#%d' % (i + 1))
    for j in range(num[i]):
        print(' '.join(a[i][j*10:(j+1)*10]))
