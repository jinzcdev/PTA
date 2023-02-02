// https://pintia.cn/problem-sets/14/exam/problems/2990
#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > ans;
vector<int> tmp;
int n;
void dfs(int x, int sum) {
    tmp.push_back(x);
    if (sum == n) {
        ans.push_back(tmp);
        tmp.pop_back();
        return;
    }
    for (int i = x; i <= n; i++)
        if (sum + i <= n) dfs(i, sum + i);
    tmp.pop_back();
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) dfs(i, i);
    for (int i = 0; i < ans.size(); i++) {
        printf("%d=", n);
        for (int j = 0; j < ans[i].size(); j++) {
            if (j != 0) printf("+");
            printf("%d", ans[i][j]);
        }
        if ((i + 1) % 4 == 0) printf("\n");
        else if (i != ans.size() - 1) printf(";");
    }
    return 0;
}