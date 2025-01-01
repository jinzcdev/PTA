# https://pintia.cn/problem-sets/1526027869896364032/exam/problems/type/7?problemSetProblemId=1526201856433639424
sheng = {2: 4, 4: 5, 5: 1, 1: 3, 3: 2}
ke = {1: 2, 2: 5, 5: 3, 3: 4, 4: 1}

n = int(input())
while n != 0:
    a, b = map(int, input().split())
    if sheng[a] == b or sheng[b] == a:
        print("%d sheng %d" % ((a, b) if sheng[a] == b else (b, a)))
    else:
        print("%d ke %d" % ((a, b) if ke[a] == b else (b, a)))
    n -= 1