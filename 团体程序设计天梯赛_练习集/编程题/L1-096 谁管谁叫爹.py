# https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1649748772841508871
n = int(input())
while n != 0:
    na, nb = map(int, input().split())
    sa = sum(map(int, list(str(na))))
    sb = sum(map(int, list(str(nb))))
    
    if (na % sb == 0 and nb % sa == 0) or (na % sb != 0 and nb % sa != 0):
        print('A' if na > nb else 'B')
    elif na % sb == 0:
        print('A')
    else:
        print('B')
    n -= 1
