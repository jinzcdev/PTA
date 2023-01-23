// https://pintia.cn/problem-sets/15/problems/866
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, ans = 0;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, posa = a.size() - 1, posb = b.size() - 1;
    while (posa >= i && posb >= i && a[posa] * b[posb] > 0) ans += a[posa--] * b[posb--];
    while (i < posa && i < posb && a[i] * b[i] > 0) ans += a[i] * b[i++];
    printf("%d", ans);
    return 0;
}