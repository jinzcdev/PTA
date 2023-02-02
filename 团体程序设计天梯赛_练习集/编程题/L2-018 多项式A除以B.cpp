// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805060372905984
#include <bits/stdc++.h>
using namespace std;
void printPloy(map<int, double> &poly) {
    vector<pair<int, double> > ans;
    for (auto &[k, v] : poly)
        if (v != 0 && fabs(v) * 100 >= 5) ans.push_back({k, v});
    if (ans.size() == 0) printf("0 0 0.0\n");
    else {
        printf("%d", ans.size());
        for (int i = ans.size() - 1; i >= 0; i--)
            printf(" %d %.1f", ans[i].first, ans[i].second);
        printf("\n");
    }
}
int main() {
    int n, e, maxE;
    double c, maxC;
    map<int, double> a, b, rs;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> e >> c;
        a[e] = c;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> e >> c;
        if (i == 0) {
            maxC = c;
            maxE = e;
        }
        b[e] = c;
    }
    while (true) {
        double tc = 0;
        int te = 0;
        for (auto &[k, v] : a) {
            if (k > te && v != 0) {
                te = k;
                tc = v;
            }
        }
        if (tc == 0 || te < maxE) break;
        tc /= maxC;
        te -= maxE;
        rs[te] = tc;
        for (auto &[k, v] : b) a[te + k] -= v * tc;
    }
    printPloy(rs);
    printPloy(a);
    return 0;
}