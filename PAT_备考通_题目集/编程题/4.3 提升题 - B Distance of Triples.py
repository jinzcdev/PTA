# https://pintia.cn/problem-sets/1526027869896364032/exam/problems/type/7?problemSetProblemId=1526203766528069632
def get_max_index(arr, i, j, k):
    if arr[0][i] >= arr[1][j] and arr[0][i] >= arr[2][k]:
        return 0
    elif arr[1][j] >= arr[0][i] and arr[1][j] >= arr[2][k]:
        return 1
    return 2


def get_distance(*lst):
    lst = list(lst)
    assert len(lst) == 3
    lst.sort()
    return lst[1] - lst[0] + lst[2] - lst[1] + lst[2] - lst[0]


input()
arr = []
for _ in range(3):
    arr.append(sorted(list(map(int, input().split())), reverse=True))
i, j, k = 0, 0, 0
MIN = 999999
ans = []
while i < len(arr[0]) and j < len(arr[1]) and k < len(arr[2]):
    dis = get_distance(arr[0][i], arr[1][j], arr[2][k])
    if dis < MIN:
        MIN = dis
        ans = [arr[0][i], arr[1][j], arr[2][k]]
    max_i = get_max_index(arr, i, j, k)
    if max_i == 0:
        i += 1
    elif max_i == 1:
        j += 1
    else:
        k += 1
print(f"MinD({', '.join(map(str, ans))}) = {MIN}")