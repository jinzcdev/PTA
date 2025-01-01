// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1518582589840875520
#include <bits/stdc++.h>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int e[N][N], gender[N] = {0}, n, start;
void solve(vector<double> &score, int sex) {
    vector<int> ans;
    double MIN = INF;
    for (int i = 1; i <= n; i++) {
        if (gender[i] != sex) continue;
        if (score[i] < MIN) {
            MIN = score[i];
            ans.clear();
            ans.push_back(i);
        } else if (score[i] == MIN) {
            ans.push_back(i);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}
int main() {
    fill(e[0], e[0] + N * N, INF);
    char ch;
    int k, a, b;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ch >> k;
        if (ch == 'M') gender[i] = 1;
        while (k--) {
            scanf("%d:%d", &a, &b);
            e[i][a] = b;
        }
    }
    for (int v = 1; v <= n; v++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                e[i][j] = min(e[i][j], e[i][v] + e[v][j]);

    vector<double> score(n + 1, 0);
    for (int j = 1; j <= n; j++) {
        int maxD = -1;
        for (int i = 1; i <= n; i++) {
            if (gender[i] == gender[j]) continue;
            maxD = max(maxD, e[i][j]);
        }
        score[j] = maxD;
    }
    solve(score, 0);
    solve(score, 1);
    return 0;
}