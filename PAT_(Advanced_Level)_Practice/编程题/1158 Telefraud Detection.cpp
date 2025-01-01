// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635060278108160
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int father[N];
int findfather(int x) {
    return x == father[x] ? x : father[x] = findfather(father[x]);
}
void uni(int a, int b) {
    int faA = findfather(a), faB = findfather(b);
    if (faA < faB) father[faB] = faA;
    else father[faA] = faB;
}
int main() {
    for (int i = 0; i < N; i++) father[i] = i;
    int k, n, m, a, b, d, record[N][N] = {0};
    scanf("%d%d%d", &k, &n, &m);
    while (m--) {
        scanf("%d%d%d", &a, &b, &d);
        record[a][b] += d;
    }
    vector<int> suspect;
    for (int i = 1; i <= n; i++) {
        int callto = 0, callback = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (record[i][j] != 0 && record[i][j] <= 5) {
                callto++;
                if (record[j][i] != 0) callback++;
            }
        }
        if (callto > k && callback * 1.0 / callto <= 0.2) suspect.push_back(i);
    }
    if (suspect.size() == 0) {
        printf("None");
        return 0;
    }
    for (int i = 0; i < suspect.size(); i++) {
        for (int j = i + 1; j < suspect.size(); j++) {
            int a = suspect[i], b = suspect[j];
            if (record[a][b] > 0 && record[b][a] > 0) uni(suspect[i], suspect[j]);
        }
    }
    map<int, vector<int> > mp;
    for (auto it : suspect) mp[findfather(it)].push_back(it);
    for (auto it : mp) {
        vector<int> gang = move(it.second);
        for (int i = 0; i < gang.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", gang[i]);
        }
        printf("\n");
    }
    return 0;
}