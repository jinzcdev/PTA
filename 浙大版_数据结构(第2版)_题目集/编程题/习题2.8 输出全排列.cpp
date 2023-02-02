// https://pintia.cn/problem-sets/434/exam/problems/5811
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

/*
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    do {
        for (int i = 0; i < n; i++) printf("%d", a[i]);
        printf("\n");
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}
*/