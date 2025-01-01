// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805396953219072
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1020;
const int INF = 0x7FFFFFFF;

int n, m, k, DS;
int G[maxn][maxn];
int d[maxn];
bool vis[maxn] = {false};

int getID(char *str){
    int i = 0, id = 0, len = strlen(str);
    while (i < len) {
        if (str[i] != 'G') {
            id = id * 10 + (str[i] - '0');
        }
        i++;
    }
    if (str[0] != 'G') return id;
    else return id + n;
}

void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    memset(vis, false, sizeof(vis));
    d[s] = 0;
    for (int i = 0; i < n + m; i++){
        int u = -1, MIN = INF;
        for (int j = 1; j <= n + m; j++){
            if (!vis[j] && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 1; v <= n + m; v++){
            if (!vis[v] && G[u][v] < INF && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d", &n, &m, &k, &DS);
    char city1[5], city2[5];
    fill(G[0], G[0] + maxn * maxn, INF);
    int u, v, w;
    for (int i = 0; i < k; i++){
        scanf("%s %s %d", city1, city2, &w);
        u = getID(city1);
        v = getID(city2);
        G[v][u] = G[u][v] = w;
    }

    int ansID = -1;
    double ansDis = -1, ansAvg = INF;
    for (int i = n + 1; i <= n + m; i++) {
        double minDis = INF, avg = 0;
        Dijkstra(i);
        for (int city = 1; city <= n; city++){
            if (d[city] > DS) {
                minDis = -1;
                break;
            } else {
                if (d[city] < minDis) minDis = d[city];
                avg += 1.0 * d[city] / n;
            }
        }
        if (minDis == -1) continue;
        if (minDis > ansDis) {
            ansID = i - n;
            ansDis = minDis;
            ansAvg = avg;
        } else if (minDis == ansDis && avg < ansAvg) {
            ansID = i - n;
            ansAvg = avg;
        }
    }
    if (ansID == -1) printf("No Solution\n");
    else printf("G%d\n%.1f %.1f", ansID, ansDis, ansAvg);
    return 0;
}