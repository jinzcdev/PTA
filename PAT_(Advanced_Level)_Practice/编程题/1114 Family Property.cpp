// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805356599820288
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
struct node {
    int id = 99999, cntMember = 0;
    double estate = 0, area = 0;
};
int father[N];
bool cmp(node a, node b) {
    return a.area != b.area ? a.area > b.area : a.id < b.id;
}
void init() {
    for (int i = 0; i < N; i++) {
        father[i] = i;
    }
}
int findFather(int x) {
    if (x == father[x]) return x;
    int fa = findFather(father[x]);
    father[x] = fa;
    return fa;
}
void uni(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) father[faA] = faB;
}
int pos = 1;
map<int, int> numToId, idToNum;
void change(int &id) {
    if (idToNum[id] == 0) {
        numToId[pos] = id;
        idToNum[id] = pos;
        id = pos++;
    } else {
        id = idToNum[id];
    }
}
int main() {
    init();
    int n, estate[N] = {0}, area[N] = {0}, id, fa, mo, child, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &id, &fa, &mo, &k);
        change(id);
        if (fa != -1) {
            change(fa);
            uni(id, fa);
        }
        if (mo != -1) {
            change(mo);
            uni(id, mo);
        }
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            change(child);
            uni(id, child);
        }
        scanf("%d%d", &estate[id], &area[id]);
    }
    map<int, node> family;
    for (int i = 1; i < pos; i++) {
        // int fa = father[i];
        int fa = findFather(i);
        family[fa].id = min(family[fa].id, numToId[i]);
        family[fa].cntMember++;
        family[fa].estate += estate[i];
        family[fa].area += area[i];
    }
    vector<node> ans;
    for (auto it : family) {
        it.second.estate /= it.second.cntMember;
        it.second.area /= it.second.cntMember;
        ans.push_back(it.second);
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for (auto it : ans) {
        printf("%04d %d %.3f %.3f\n", it.id, it.cntMember, it.estate, it.area);
    }
    return 0;
}