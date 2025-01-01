// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=861
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
vector<int> e[N];
bool vis[N] = {false}, recStack[N] = {false};
bool isCyclic(int u) {
    vis[u] = true;
    recStack[u] = true;
    for (auto it : e[u]) {
        if (recStack[it]) return true;
        if (!vis[it] && isCyclic(it)) return true;
    }
    recStack[u] = false;
    return false;
}
int main() {
    int n, k, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &a);
            e[a].push_back(i);
        }
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) flag = flag || isCyclic(i);
    }
    printf("%d", flag ? 0 : 1);
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
vector<int> e[N];
bool isCircle = false, vis[N] = {false}, recStack[N] = {false};
void dfs(int u) {
    vis[u] = true;
    recStack[u] = true;
    for (auto it : e[u]) {
        if (recStack[it]) isCircle = true;
        if (!vis[it]) {
            dfs(it);
        }
    }
    recStack[u] = false;
}
int main() {
    int n, k, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &a);
            e[a].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    printf("%d", isCircle ? 0 : 1);
    return 0;
}
*/