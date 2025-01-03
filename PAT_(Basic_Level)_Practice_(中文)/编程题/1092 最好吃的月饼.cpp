// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1071785779399028736
#include <iostream>
#include <vector>
using namespace std;
int a[1005][105], sum[1005];
int main() {
    int m, n, maxn = 0, total = 0;
    vector<int> ans;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            sum[j] += a[i][j];
            maxn = max(maxn, sum[j]);
        }
    }
    cout << maxn << endl;
    for (int i = 1; i <= m; i++)
        if (sum[i] == maxn) ans.push_back(i);
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    return 0;
}