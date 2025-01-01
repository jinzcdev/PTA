// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805072641245184
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct node {
    int adr, data, next;
} L[N];
void print(vector<node> &l) {
    for (int i = 0; i < l.size() - 1; i++)
        printf("%05d %d %05d\n", l[i].adr, l[i].data, l[i + 1].adr);
    printf("%05d %d -1\n", l[l.size() - 1].adr, l[l.size() - 1].data);
}
int main() {
    int head, n, adr, data, next;
    scanf("%d%d", &head, &n);
    bool vis[N] = {false};
    for (int i = 0; i < n; i++) {
        scanf("%d", &adr);
        scanf("%d%d", &L[adr].data, &L[adr].next);
        L[adr].adr = adr;
    }
    vector<node> l1, l2;
    for (int p = head; p != -1; p = L[p].next) {
        if (!vis[abs(L[p].data)]) {
            l1.push_back(L[p]);
            vis[abs(L[p].data)] = true;
        } else {
            l2.push_back(L[p]);
        }
    }
    if (l1.size()) print(l1);
    if (l2.size()) print(l2);
    return 0;
}