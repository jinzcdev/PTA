// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805354762715136
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end(), cmp);
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (v[i] > i + 1) ans = i + 1;
    printf("%d", ans);
    return 0;
}