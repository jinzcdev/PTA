// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805117167976448
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k, a, cnt = 0;
    unordered_map<int, bool> has, vis;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &k);
        if (k == 1) {
            scanf("%d", &a);
            continue;
        }
        while (k--) {
            scanf("%d", &a);
            has[a] = true;
        }
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &a);
        if (!has[a] && !vis[a]) {
            if (cnt++ > 0) printf(" ");
            printf("%05d", a);
            vis[a] = true;
        }
    }
    if (cnt == 0) printf("No one is handsome\n");
    return 0;
}