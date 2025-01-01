// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805482919673856
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 10010;
vector<int> G[maxn];
bool visited[maxn], isTree = false;
int n, maxDepth = 0, maxH = 0;
vector<int> ans;

bool cmp(int a, int b){
    return a < b;
}

void DFS(int u, int depth){
    visited[u] = true;
    if (depth > maxDepth){
        maxDepth = depth;
    }
    for (int i = 0; i < G[u].size(); i++){
        if (!visited[G[u][i]]){
            DFS(G[u][i], depth + 1);
        }
    }
}

int main(){
    int v1, v2;
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++){
        scanf("%d%d", &v1, &v2);
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    int k = 0;
    for (int u = 1; u <= n; u++){
        if (!visited[u]){
            k++;
            DFS(u, 1);
        }
    }
    if (k > 1){
        printf("Error: %d components\n", k);
    } else if (k == 1) {
        for (int u = 1; u <= n; u++){
            maxDepth = 0;
            memset(visited, false, sizeof(visited));
            DFS(u, 1);
            if (maxDepth > maxH) {
                ans.clear();
                ans.push_back(u);
                maxH = maxDepth;
            } else if (maxDepth == maxH) {
                ans.push_back(u);
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        for (int i = 0; i < ans.size(); i++){
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}