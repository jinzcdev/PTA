// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805066135879680
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int father[N];
int findFather(int x) {
    return x == father[x] ? x : father[x] = findFather(father[x]);
}
void uni(int a, int b) {
    int faA = findFather(a), faB = findFather(b);
    if (faA != faB) father[faA] = faB;
}
int main() {
    for (int i = 0; i < N; i++) father[i] = i;
    int n, m, k, a, b, t, hash[N][N] = {0};
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &t);
        hash[a][b] = hash[b][a] = t;
        if (t == 1) uni(a, b);
    }
    while (k--) {
        scanf("%d%d", &a, &b);
        int faA = findFather(a), faB = findFather(b);
        if (faA == faB && hash[a][b] != -1) printf("No problem\n");
        else if (faA != faB && hash[a][b] != -1) printf("OK\n");
        else if (faA == faB && hash[a][b] == -1) printf("OK but...\n");
        else printf("No way\n");
    }
    return 0;
}