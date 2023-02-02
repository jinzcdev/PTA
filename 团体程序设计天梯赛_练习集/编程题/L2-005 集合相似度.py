# https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805070149828608
n = int(input())
d = {}
for i in range(n):
    lst = list(map(int, input().split()))
    d[i + 1] = set(lst[1:])
    
k = int(input())
for _ in range(k):
    a, b = map(int, input().split())
    sa, sb = d[a] & d[b], d[a] | d[b]
    print('%.2f%%' % ((len(sa) / len(sb)) * 100))

    