// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805061769609216
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct node {
    int left = -1, right = -1, gender;
} t[N];
bool vis[N], found;
void dfs(int u, int depth) {
    if (u != -1 && depth <= 5 && !found) {
        if (vis[u]) {
            found = true;
            return;
        }
        vis[u] = true;
        dfs(t[u].left, depth + 1);
        dfs(t[u].right, depth + 1);
    }
}
int main() {
    int n, k, id, a, b;
    char gender;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %c %d %d", &id, &gender, &a, &b);
        t[id] = {a, b, gender == 'M' ? 1 : 0};
        t[a].gender = 1;
        t[b].gender = 0;
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &a, &b);
        if (t[a].gender == t[b].gender) printf("Never Mind\n");
        else {
            fill(vis, vis + N, false);
            found = false;
            dfs(a, 1);
            dfs(b, 1);
            printf("%s\n", found ? "No" : "Yes");
        }
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct node {
    int left = -1, right = -1, gender;
} t[N];
int layer[N] = {0};
void dfs(int u, int depth) {
    if (u == -1 || depth > 5) return;
    layer[u] = depth;
    dfs(t[u].left, depth + 1);
    dfs(t[u].right, depth + 1);
}
bool is_relative(int u, int depth) {
    if (depth > 5) return false;
    if (layer[u] != 0 && layer[u] <= 5) return true;
    return (t[u].left != -1 && is_relative(t[u].left, depth + 1))
            || (t[u].right != -1 && is_relative(t[u].right, depth + 1));
}
int main() {
    int n, m, id, a, b;
    char gender;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %c %d %d", &id, &gender, &a, &b);
        t[id] = {a, b, gender == 'M' ? 1 : 0};
        t[a].gender = 1;
        t[b].gender = 0;
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        if (t[a].gender == t[b].gender) {
            printf("Never Mind\n");
            continue;
        }
        fill(layer, layer + N, 0);
        dfs(a, 1);
        printf("%s\n", is_relative(b, 1) ? "No" : "Yes");
    }
    return 0;
}
*/

/* @pintia note=start
?????????????????????????????????. ??????a, b??????????????????:
1. ??? a ????????????, ????????????????????? 5 ???????????????
2. ??? b ????????????????????? 5 ?????????????????????, ?????????????????????????????????????????????????????????
@pintia note=end */
