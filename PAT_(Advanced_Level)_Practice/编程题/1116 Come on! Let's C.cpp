// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805355358306304
#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    int n, k, id, rank[10000] = {0};
    bool vis[10000] = {false};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &id);
        rank[id] = i;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &id);
        printf("%04d: ", id);
        if (rank[id] == 0) printf("Are you kidding?\n");
        else if (vis[id]) printf("Checked\n");
        else {
            vis[id] = true;
            if (rank[id] == 1) printf("Mystery Award\n");
            else if (isprime(rank[id])) printf("Minion\n");
            else printf("Chocolate\n");
        }
    }
    return 0;
}