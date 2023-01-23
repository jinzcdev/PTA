# https://pintia.cn/problem-sets/994805046380707840/problems/1386335159927652356
mood = list(map(int,input().split()))
while True:
    h = int(input())
    if h not in range(0, 24):
        break
    print(mood[h], 'Yes' if mood[h] > 50 else 'No')