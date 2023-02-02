// https://pintia.cn/problem-sets/434/exam/problems/6542
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
struct edge {
    int u, v, cost;
};
vector<edge> v;
bool cmp(edge &a, edge &b) { return a.cost < b.cost; }
int n, father[N];
int findfather(int x) {
    return x == father[x] ? x : father[x] = findfather(father[x]);
}
void uni(int a, int b) {
    int faA = findfather(a), faB = findfather(b);
    if (faA != faB) father[faB] = faA;
}
bool isconnected() {
    for (int i = 1; i < n; i++)
        if (findfather(i) != findfather(i + 1)) return false;
    return true;
}
int kruskal() {
    sort(v.begin(), v.end(), cmp);
    int cost = 0, cntEdge = 0;
    for (auto it : v) {
        int faA = findfather(it.u), faB = findfather(it.v);
        if (faA != faB) {
            father[faA] = faB;
            cost += it.cost;
            if (isconnected()) break;
        }
    }
    return cost;
}
int main() {
    for (int i = 0; i < N; i++) father[i] = i;
    scanf("%d", &n);
    int a, b, cost, built, m = n * (n - 1) / 2;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &a, &b, &cost, &built);
        if (built) uni(a, b);
        else v.push_back({a, b, cost});
    }
    printf("%d", kruskal());
    return 0;
}