// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1038430013544464384
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 210;
const int INF = 0x7777777F;
int G[maxn][maxn], d[maxn];

int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    fill(G[0], G[0] + maxn * maxn, INF);
    int city1, city2;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &city1, &city2);
        scanf("%d", &G[city1][city2]);
        G[city2][city1] = G[city1][city2];
    }
    scanf("%d", &k);
    int path[maxn], ansPath, ansDist = INF;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", path + i);
        }
        int start = path[0], ans = 0, numCycle = 0;
        bool isNotCycle = false;
        set<int> visCity;
        G[start][start] = 0;
        for (int j = 0; j < m; j++) {
            if (j != 0 && path[j] == path[0]) {
                numCycle++;
            }
            if (G[start][path[j]] != INF) {
                ans += G[start][path[j]];
                start = path[j];
            } else {
                isNotCycle = true;
            }
            visCity.insert(path[j]);
        }
        if (visCity.size() != n) {
            printf("Path %d: %d (Not a TS cycle)\n", i, ans);
        } else if (isNotCycle) {
            printf("Path %d: NA (Not a TS cycle)\n", i);
        } else {
            if (numCycle == 0) {
                printf("Path %d: %d (Not a TS cycle)\n", i, ans);
            } else {
                if (numCycle == 1) {
                    printf("Path %d: %d (TS simple cycle)\n", i, ans);
                } else {
                    printf("Path %d: %d (TS cycle)\n", i, ans);
                }
                if (ans < ansDist) {
                    ansPath = i;
                    ansDist = ans;
                }
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n", ansPath, ansDist);
    return 0;
}
