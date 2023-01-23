# https://pintia.cn/problem-sets/994805046380707840/problems/994805075543703552
x, y = map(int, input().split())
s = input().split()
cnta = s.count('0')
if x > y and cnta >= 1:
    print('The winner is a: %d + %d' % (x, cnta))
else:
    print('The winner is b: %d + %d' % (y, len(s) - cnta))
    