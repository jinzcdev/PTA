# https://pintia.cn/problem-sets/1526027869896364032/exam/problems/type/7?problemSetProblemId=1526203086098714624
n, m = map(int, input().split())
ans = [["."] * (n + 1) for _ in range(n + 1)]
for _ in range(m):
    t = input()
    if t.find(";") != -1:
        x, y = map(int, t.split(";"))
    elif t.find("/") != -1:
        x, y = map(int, t.split("/"))
    else:
        x, y = int(t[:-2]), int(t[-2:])
    ans[n + 1 - y][x] = "#"
for i in range(1, n + 1):
   print("".join(ans[i][1:]))
   
""" @pintia note=start
这道题的注意点在于输出的时候是以左下角为原点, 而且原点从 (1,1) 开始。
因此计算时要交换横纵坐标再逆置x轴。
@pintia note=end """