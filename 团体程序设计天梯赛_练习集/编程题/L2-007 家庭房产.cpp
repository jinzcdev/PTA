// https://pintia.cn/problem-sets/994805046380707840/problems/994805068539215872
#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
struct node {
    int id, cnt;
    double avgM, avgA;
};
int father[N];
int findFather(int x) {
    return x == father[x] ? x : father[x] = findFather(father[x]);
}
void uni(int a, int b) {
    int faA = findFather(a), faB = findFather(b);
    if (faA < faB) father[faB] = faA;
    else if (faA > faB) father[faA] = faB;
}
bool cmp(node &a, node &b) {
    return a.avgA != b.avgA ? a.avgA > b.avgA : a.id < b.id;
}
int main() {
    for (int i = 0; i < N; i++) father[i] = i;
    int n, a, child, fa, mo, k, mestate[N] = {0}, area[N] = {0};
    scanf("%d", &n);
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a, &fa, &mo, &k);
        s.insert(a);
        if (fa != -1) {
            uni(a, fa);
            s.insert(fa);
        }
        if (mo != -1) {
            uni(a, mo);
            s.insert(mo);
        }
        while (k--) {
            scanf("%d", &child);
            s.insert(child);
            uni(a, child);
        }
        scanf("%d%d", &mestate[a], &area[a]);
    }
    unordered_map<int, node> mp;
    vector<node> ans;
    for (auto it : s) {
        int fa = findFather(it);
        mp[fa].cnt++;
        mp[fa].avgM += mestate[it];
        mp[fa].avgA += area[it];        
    }
    for (auto it : mp) {
        node temp = move(it.second);
        ans.push_back({it.first, temp.cnt, temp.avgM / temp.cnt, temp.avgA / temp.cnt});
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for (auto it : ans)
        printf("%04d %d %.3f %.3f\n", it.id, it.cnt, it.avgM, it.avgA);
    return 0;
}