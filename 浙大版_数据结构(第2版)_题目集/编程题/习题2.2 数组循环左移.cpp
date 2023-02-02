// https://pintia.cn/problem-sets/434/exam/problems/5653
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    m = m % n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    reverse(v.begin(), v.begin() + m);
    reverse(v.begin() + m, v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", v[i]);
    }
    return 0;
}