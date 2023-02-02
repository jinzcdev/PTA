// https://pintia.cn/problem-sets/15/exam/problems/840
#include <bits/stdc++.h>
using namespace std;
const int N = 30010;
int father[N];
int findFather(int x) { return x == father[x] ? x : father[x] = findFather(father[x]); }
void uni(int a, int b) {
    int faA = findFather(a), faB = findFather(b);
    if (faA != faB) father[faA] = faB;
}
int main() {
    int n, m, k, a, b;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) father[i] = i;
    while (m--) {
        scanf("%d", &k);
        vector<int> v(k);
        // scanf("%d", &a);
        for (int i = 0; i < k; i++) scanf("%d", &v[i]);
        for (int i = 0; i < k - 1; i++) uni(v[i], v[i + 1]);
    }
    unordered_map<int, int> mp;
    int Max = -1;
    for (int i = 1; i <= n; i++) {
        Max = max(Max, ++mp[findFather(i)]);
    }
    printf("%d", Max);
    return 0;
}