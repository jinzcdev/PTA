// https://pintia.cn/problem-sets/434/exam/problems/type/7?problemSetProblemId=5811
// 习题2.8 输出全排列 (20 分)
#include <iostream>
using namespace std;
const int N = 15;
int n;
void dfs(int x, int index, int* a, bool* vis) {
    a[index] = x;
    if (index == n) {
        for (int i = 1; i <= n; i++) {
            printf("%d", a[i]);
        }
        printf("\n");
        return;
    }
    vis[x] = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, index + 1, a, vis);
        }
    }
    vis[x] = false;
}
int main() {
    int a[N] = {0};
    bool vis[N] = {false};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        dfs(i, 1, a, vis);
    }
    return 0;
}