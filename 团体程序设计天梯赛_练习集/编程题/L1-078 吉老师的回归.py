# https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1386335159927652357
n, m = map(int, input().split())
cnt = 0
flag = False
for _ in range(n):
    s = input()
    if s.find('easy') != -1 or s.find('qiandao') != -1:
        continue
    if cnt == m:
        print(s)
        flag = True
        break
    cnt += 1
if flag == False:
    print('Wo AK le')
        