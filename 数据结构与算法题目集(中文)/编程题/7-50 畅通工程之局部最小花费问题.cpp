// https://pintia.cn/problem-sets/15/exam/problems/897
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
struct node {
    int u, v, cost, flag;
} e[N * (N - 1) / 2];
int n, m, father[N];
bool cmp(node &a, node &b) { return a.cost < b.cost; }
int findFather(int x) {
    return x == father[x] ? x : father[x] = findFather(father[x]);
}
int kruskal() {
    for (int i = 0; i < N; i++) father[i] = i;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (e[i].flag == 1) {
            int faA = findFather(e[i].u), faB = findFather(e[i].v);
            if (faA != faB) {
                father[faA] = father[faB];
                cnt++;
            }
        }
    }
    sort(e, e + m, cmp);
    int ans = 0, cntEdge = 0;
    for (int i = 0; i < m; i++) {
        int faA = findFather(e[i].u), faB = findFather(e[i].v);
        if (faA != faB) {
            father[faA] = faB;
            ans += e[i].cost;
            if (++cntEdge == n - 1 - cnt) break;
        }
    }
    return cntEdge != n - 1 - cnt ? -1 : ans;
}
int main() {
    scanf("%d", &n);
    m = n * (n - 1) / 2;
    for (int i = 0; i < m; i++)
        scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].cost, &e[i].flag);
    printf("%d", kruskal());
    return 0;
}