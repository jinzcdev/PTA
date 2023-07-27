#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n, m, d, idx = 0, a[N], ct[N];
void dfs(int u) {
    if (u >= n) {
        return;
    }
    ct[u] = a[idx++];
    for (int i = 1; i <= d; i++) {
        dfs(u * d + i);
    }
}
int main() {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", ct[i]);
    }
    printf("\n");
    int k, x;
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &x);
        for (int i = x; i > 0; i = (i - 1) / d) {
            printf("%d ", ct[i]);
        }
        printf("%d", ct[0]);
        printf("\n");
    }
    return 0;
}