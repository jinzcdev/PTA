# https://pintia.cn/problem-sets/1526027869896364032/exam/problems/type/7?problemSetProblemId=1526056162343317504
n = int(input())
cnt_m, cnt_f = 0, 0
sum_m, sum_f = 0, 0
for _ in range(n):
    sex, score = map(int, input().split())
    if sex == 1:
        cnt_m += 1
        sum_m += score
    else:
        cnt_f += 1
        sum_f += score
print("{:.1f} {} {}".format(
    (sum_m + sum_f) / n,
    "X" if cnt_m == 0 else "{:.1f}".format(sum_m / cnt_m),
    "X" if cnt_f == 0 else "{:.1f}".format(sum_f / cnt_f))
)