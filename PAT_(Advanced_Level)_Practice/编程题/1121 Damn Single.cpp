// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805352359378944
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, a, b;
    map<int, int> couple;
    bool hasMate[100000] = {false};
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        couple[a] = b;
        couple[b] = a;
        hasMate[a] = hasMate[b] = true;
    }
    scanf("%d", &m);
    vector<int> v(m), ans;
    bool inq[100000] = {false};
    for (int i = 0; i < m; i++) {
        scanf("%d", &v[i]);
        inq[v[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        if (!hasMate[v[i]] || !inq[couple[v[i]]]) {
            ans.push_back(v[i]);
        }
    }
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%05d", ans[i]);
    }
    return 0;
}