# https://pintia.cn/problem-sets/1111652100718116864/exam/problems/1163035698160459789
def acronym(phrase):
    a = phrase.split()
    ans = ''
    for i in range(0, len(a)):
        ans += a[i][0].upper()
    return ans