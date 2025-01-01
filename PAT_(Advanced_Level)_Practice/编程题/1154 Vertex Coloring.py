# https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1071785301894295552
num_vertice, num_edges = list(map(int, input().split()))
roads = [None for _ in range(num_edges)]
for i in range(num_edges):
    a, b = list(map(int, input().split()))
    roads[i] = [a, b]
for _ in range(int(input())):
    color = list(map(int, input().split()))
    for road in roads:
        if color[road[0]] == color[road[1]]:
            print("No")
            break
    else:
        print("%d-coloring" % len(set(color)))