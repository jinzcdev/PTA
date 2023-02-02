// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805347523346432
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
const int INF = 0x7fffffff;
vector<int> e[N];
bool vis[N];
map<int, int> line;
vector<int> path, tempPath;
int n, m, k, st, dest, minCntStop, minCntTransfer;
int getTransferCount(vector<int> &v) {
    int preline = line[v[0] * 10000 + v[1]], cnt = 0;
    for (int i = 1; i < v.size(); i++) {
        int nowline = line[v[i - 1] * 10000 + v[i]];
        if (nowline != preline) {
            preline = nowline;
            cnt++;
        }
    }
    return cnt;
}
void dfs(int s, int cntStop) {
    vis[s] = true;
    if (cntStop > minCntStop) return;
    if (s == dest) {
        tempPath.push_back(s);
        int cntTransfer = getTransferCount(tempPath);
        if (cntStop < minCntStop || cntTransfer < minCntTransfer) {
            minCntTransfer = cntTransfer;
            minCntStop = cntStop;
            path = tempPath;
        }
        vis[s] = false;
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(s);
    for (auto next : e[s]) {
        if (!vis[next]) {
            dfs(next, cntStop + 1);
            vis[next] = false;
        }
    }
    tempPath.pop_back();
}
void init() {
    fill(vis, vis + N, false);
    path.clear();
    tempPath.clear();
    minCntStop = minCntTransfer = INF;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int preStop, nowStop;
        scanf("%d%d", &m, &preStop);
        for (int j = 1; j < m; j++) {
            scanf("%d", &nowStop);
            e[preStop].push_back(nowStop);
            e[nowStop].push_back(preStop);
            line[preStop * 10000 + nowStop] = line[nowStop * 10000 + preStop] = i;
            preStop = nowStop;
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &st, &dest);
        init();
        dfs(st, 0);
        printf("%d\n", minCntStop);
        int preLine = 0, preTransfer = st;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]*10000+path[j]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
                preLine = line[path[j-1]*10000+path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, dest);
    }
    return 0;
}