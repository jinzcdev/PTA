# https://pintia.cn/problem-sets/1111652100718116864/problems/1163035698160459776
# def fn(a, n):
#     sum = 0
#     tmp = 0
#     for i in range(n):
#         tmp = tmp * 10 + a
#         sum += tmp
#     return sum

def fn(a, n):
	ch = str(a)
	return sum([int(ch * i) for i in range(1, n + 1)])