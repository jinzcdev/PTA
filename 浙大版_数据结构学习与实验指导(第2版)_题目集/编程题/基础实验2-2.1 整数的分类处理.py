# https://pintia.cn/problem-sets/988034414048743424/problems/988036281675845632
# #include <bits/stdc++.h>
# using namespace std;
# int main() {
#     int n, a = 0, a1 = 0, a2 = 0, a3 = 0, cnt = 0;
#     cin >> n;
#     for (int i = 0; i < n; i++) {
#         cin >> a;
#         a1 = max(a1, a % 3 == 0 ? a : 0);
#         a2 += (a - 1) % 3 == 0;
#         if ((a - 2) % 3 == 0) {
#             a3 += a;
#             cnt++;
#         }
#     }
#     if (a1 == 0) printf("NONE ");
#     else printf("%d ", a1);
#     if (a2 == 0) printf("NONE ");
#     else printf("%d ", a2);
#     if (cnt == 0) printf("NONE");
#     else printf("%.1f", a3 * 1.0 / cnt);
#     return 0;
# }

n = int(input())
s = list(map(int, input().split()))
a, cnt = [0] * 3, 0
for x in s:
    a[0] = max(a[0], x if x % 3 == 0 else 0)
    a[1] += 1 if (x - 1) % 3 == 0 else 0
    if (x - 2) % 3 == 0:
        a[2] += x
        cnt += 1
for i in range(3):
    if a[i] == 0:
        a[i] = 'NONE'
if cnt != 0 and a[2] != 'NONE':
    a[2] = '{:.1f}'.format(a[2] / cnt)
print(*a, sep=' ')
