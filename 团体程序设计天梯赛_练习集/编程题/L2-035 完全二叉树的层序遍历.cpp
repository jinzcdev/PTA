// https://pintia.cn/problem-sets/994805046380707840/exam/problems/1336215880692482058
#include <bits/stdc++.h>
using namespace std;
const int N = 40;
int cbt[N], a[N], n, cnt = 0;
void postOrder(int u) {
    if (u > n) return;
    postOrder(u * 2);
    postOrder(u * 2 + 1);
    cbt[u] = a[cnt++];
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    postOrder(1);
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", cbt[i]);
    }
    return 0;
}