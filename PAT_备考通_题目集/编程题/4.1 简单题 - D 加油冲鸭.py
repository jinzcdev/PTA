# https://pintia.cn/problem-sets/1526027869896364032/exam/problems/type/7?problemSetProblemId=1526055711443042304
n, m, s = map(int, input().split())
rest = n - m * s
if rest <= n / 2:
    print("hai sheng %d mi! chong ya!" % rest)
else:
    print("hai sheng %d mi! jia you ya!" % rest)