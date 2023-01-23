# https://pintia.cn/problem-sets/1111652100718116864/problems/1111653447408467981
ans = 0
m = int(input())
for i in range(11, m + 1):
    ans += i
print('sum = {0:}'.format(ans))
