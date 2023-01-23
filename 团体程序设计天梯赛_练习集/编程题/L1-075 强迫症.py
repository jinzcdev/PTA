# https://pintia.cn/problem-sets/994805046380707840/problems/1386335159927652354
s = input()
if len(s) == 6:
    print('%s-%s' % (s[:4], s[-2:]))
else:
    print('%d%s-%s' % (20 if int(s[:2]) < 22 else 19, s[:2], s[-2:]))