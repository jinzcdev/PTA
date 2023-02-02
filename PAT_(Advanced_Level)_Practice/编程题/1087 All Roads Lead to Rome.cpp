// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805379664297984
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
const int maxn = 210;
const int INF = 0x7FFFFFFF;
int n, k, st = 0, rom;
int G[maxn][maxn], weight[maxn];
int d[maxn], cntPath = 0;
bool vis[maxn] = {false};
int maxW = -1, maxAvg = -1;
map<string, int> cityToIndex;
map<int, string> indexToCity;
vector<int> path, tempPath;
vector<int> pre[maxn];

void Dijkstra(int s){
    fill(d, d + maxn, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++){
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++){
            if (!vis[v] && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v) {
    if (v == st) {
        cntPath++;
        tempPath.push_back(v);
        int tempW = 0;
        for (int i = tempPath.size() - 1 - 1; i >= 0; i--){
            tempW += weight[tempPath[i]];
        }
        double tempAvg = tempW * 1.0 / (tempPath.size() - 1);   // 途径的地点数需剪去出发地(即-1)
        if (tempW > maxW) {
            maxW = tempW;
            maxAvg = tempAvg;
            path = tempPath;
        } else if (tempW == maxW && tempAvg > maxAvg) {
            maxAvg = tempAvg;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int u = 0; u < pre[v].size(); u++){
        DFS(pre[v][u]);
    }
    tempPath.pop_back();
}

int main(){
    string start, city, city1, city2;
    cin >> n >> k >> start;
    cityToIndex[start] = 0;
    indexToCity[0] = start;
    for (int i = 1; i <= n - 1; i++){
        cin >> city >> weight[i];
        cityToIndex[city] = i;
        indexToCity[i] = city;
    }
    fill(G[0], G[0] + maxn * maxn, INF);
    for (int i = 0; i < k; i++){
        cin >> city1 >> city2;
        int c1 = cityToIndex[city1], c2 = cityToIndex[city2];
        cin >> G[c1][c2];
        G[c2][c1] = G[c1][c2];
    }
    rom = cityToIndex["ROM"];
    Dijkstra(st);
    DFS(rom);
    printf("%d %d %d %d\n", cntPath, d[rom], maxW, (int)maxAvg);
    for (int i = path.size() - 1; i >= 0; i--){
        if (i != path.size() - 1) printf("->");
        cout << indexToCity[path[i]];
    }
    return 0;
}