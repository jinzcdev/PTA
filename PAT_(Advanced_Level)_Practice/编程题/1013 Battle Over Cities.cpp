// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805500414115840
#include <cstdio>
const int maxn = 1010;
int G[maxn][maxn], visited[maxn];
int n, m, k;

void DFS(int v, int city){
    visited[v] = true;
    for (int i = 1; i <= n; i++){
        if (G[v][i] > 0 && !visited[i] && i != city){
            DFS(i, city);
        }
    }
}

int DFSTraverse(int city){
    int ans = 0;
    for (int i = 1; i <= n; i++){
        visited[i] = false;
    }
    for (int i = 1; i <= n; i++){
        if (i == city) continue;
        if (!visited[i]){
            ans++;
            DFS(i, city);
        }
    }
    return ans - 1;
}

int main(){
    int v1, v2, city;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++){
        scanf("%d%d", &v1, &v2);
        G[v1][v2] = G[v2][v1] = 1;
    }
    for (int i = 0; i < k; i++){
        scanf("%d", &city);
        printf("%d\n", DFSTraverse(city));
    }
}