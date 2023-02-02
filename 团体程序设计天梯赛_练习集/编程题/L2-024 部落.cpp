// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805056736444416
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
    int n, m, a, b, cnt = 0;
    unordered_set<int> s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &a);
        s.insert(a);
        for (int j = 0; j < m - 1; j++) {
            scanf("%d", &b);
            s.insert(b);
            uni(a, b);
        }
    }
    unordered_map<int, int> hash;
    for (auto it : s) hash[findFather(it)] = 1;
    printf("%d %d\n", s.size(), hash.size());
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        printf("%s\n", findFather(a) == findFather(b) ? "Y" : "N");
    }
    return 0;
}