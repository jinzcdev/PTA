# https://pintia.cn/problem-sets/1111652100718116864/exam/problems/1111653447408467968
x = float(input())
ans = 0.0 if x == 0 else 1 / x
print("f({:.1f}) = {:.1f}".format(x, ans))