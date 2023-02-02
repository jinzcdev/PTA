// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805054698012672
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, k, ismale[N] = {0};
double w[N][N] = {0};
set<int> s;
void solve(vector<int> &ans, int a, double &MAX) {
    for (const auto &it : s) {
        if (ismale[it] + ismale[a] != 1) continue;
        if (w[it][a] > MAX) {
            MAX = w[it][a];
            ans.clear();
            ans.push_back(it);
        } else if (w[it][a] == MAX) {
            ans.push_back(it);
        }
    }
}
int main() {
    string a, b;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d", &k);
        vector<int> a;
        string str;
        for (int i = 0; i < k; i++) {
            cin >> str;
            int tmp = abs(stoi(str));
            if (str[0] != '-') ismale[tmp] = 1;
            a.push_back(tmp);
            s.insert(tmp);
        }
        for (int u = 0; u < k - 1; u++) {
            for (int v = u + 1; v < k; v++) {
                if (ismale[a[u]] + ismale[a[v]] != 1) continue;
                w[a[u]][a[v]] = (w[a[v]][a[u]] += 1.0 / k);
            }
        }
    }
    cin >> a >> b;
    int ia = abs(stoi(a)), ib = abs(stoi(b));
    double MAXA = -1, MAXB = -1;
    vector<int> ansA, ansB;
    solve(ansA, ia, MAXA);
    solve(ansB, ib, MAXB);
    if (w[ia][ib] == MAXA && MAXA == MAXB) {
        cout << a << " " << b;
        return 0;
    }
    for (const auto &it : ansA) printf("%s %s%d\n", a.c_str(), ismale[it] ? "" : "-", it);
    for (const auto &it : ansB) printf("%s %s%d\n", b.c_str(), ismale[it] ? "" : "-", it);
    return 0;
}