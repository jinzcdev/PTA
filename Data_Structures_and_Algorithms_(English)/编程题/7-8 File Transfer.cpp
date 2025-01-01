// https://pintia.cn/problem-sets/16/exam/problems/type/7?problemSetProblemId=670
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
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
    int n, a, b;
    char ch;
    scanf("%d", &n);
    while (scanf("\n%c", &ch), ch != 'S') {
        scanf("%d%d", &a, &b);
        int faA = findFather(a), faB = findFather(b);
        if (ch == 'C') printf("%s\n", faA == faB ? "yes" : "no");
        else if (faA != faB) father[faA] = faB;
    }
    int vis[N] = {0}, cnt = 0;
    for (int i = 1; i <= n; i++) {
        int fa = findFather(i);
        if (!vis[fa]) cnt++;
        vis[fa] = true;
    }
    if (cnt == 1) printf("The network is connected.\n");
    else printf("There are %d components.", cnt);
    return 0;
}