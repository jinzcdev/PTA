// https://pintia.cn/problem-sets/994805342720868352/problems/994805369774129152
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct node {
    int adr, data, next;
} L[N];
void print(vector<node> &v) {
    if (v.size() == 0) return;
    for (int i = 0; i < v.size() - 1; i++)
        printf("%05d %d %05d\n", v[i].adr, v[i].data, v[i + 1].adr);
    printf("%05d %d -1\n", v[v.size() - 1].adr, v[v.size() - 1].data);
}
int main() {
    int head, n, adr;
    scanf("%d%d", &head, &n);
    while (n--) {
        scanf("%d", &adr);
        scanf("%d%d", &L[adr].data, &L[adr].next);
        L[adr].adr = adr;
    }
    unordered_map<int, bool> vis;
    vector<node> l1, l2;
    for (int p = head; p != -1; p = L[p].next) {
        int k = abs(L[p].data);
        if (vis[k]) l2.push_back(L[p]);
        else {
            vis[k] = true;
            l1.push_back(L[p]);
        }
    }
    print(l1);
    print(l2);
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct node {
    int adr, data, next;
} L[N];
int main() {
    int head, n, adr;
    scanf("%d%d", &head, &n);
    while (n--) {
        scanf("%d", &adr);
        scanf("%d%d", &L[adr].data, &L[adr].next);
        L[adr].adr = adr;
    }
    vector<node> l, l1, l2;
    for (int p = head; p != -1; p = L[p].next) l.push_back(L[p]);
    bool vis[100010] = {false};
    for (int i = 0; i < l.size(); i++) {
        if (!vis[abs(l[i].data)]) {
            l1.push_back(l[i]);
            vis[abs(l[i].data)] = true;
        } else {
            l2.push_back(l[i]);
        }
    }
    for (int i = 0; i < l1.size() - 1; i++)
        printf("%05d %d %05d\n", l1[i].adr, l1[i].data, l1[i + 1].adr);
    printf("%05d %d -1\n", l1[l1.size() - 1].adr, l1[l1.size() - 1].data);
    if (l2.size() != 0) {
        for (int i = 0; i < l2.size() - 1; i++)
            printf("%05d %d %05d\n", l2[i].adr, l2[i].data, l2[i + 1].adr);
        printf("%05d %d -1\n", l2[l2.size() - 1].adr, l2[l2.size() - 1].data);    
    }
    return 0;
}
*/