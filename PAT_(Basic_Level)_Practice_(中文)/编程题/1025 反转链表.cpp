// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805296180871168
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node {
    int data, next, ads;
} Node[maxn];
vector<node> L, ans;
int main() {
    int n, k, head, ads;
    scanf("%d%d%d", &head, &n, &k);
    while (n--) {
        scanf("%d", &ads);
        scanf("%d%d", &Node[ads].data, &Node[ads].next);
        Node[ads].ads = ads;
    }
    for (int p = head; p != -1; p = Node[p].next) L.push_back(Node[p]);
    int i = 0;
    while (i < L.size()) {
        if (i + k - 1 >= L.size()) break;
        for (int j = i + k - 1; j >= i; j--) ans.push_back(L[j]);
        i += k;
    }
    while (i < L.size()) ans.push_back(L[i++]);
    for (int i = 0; i < ans.size() - 1; i++)
        printf("%05d %d %05d\n", ans[i].ads, ans[i].data, ans[i + 1].ads);
    printf("%05d %d -1\n", ans[ans.size() - 1].ads, ans[ans.size() - 1].data);
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct node {
    int adr, data, next;
} L[N];
int head, n, k;
void solve(int s) {
    int last = L[s].next;
    for (int i = 0; i < k - 1; i++) {
        int p = L[last].next;
        L[last].next = L[p].next;
        L[p].next = L[s].next;
        L[s].next = p;
    }
}
int main() {
    scanf("%d%d%d", &head, &n, &k);
    int adr, HEAD = 100000;
    for (int i = 0; i < n; i++) {
        scanf("%d", &adr);
        scanf("%d%d", &L[adr].data, &L[adr].next);
        L[adr].adr = adr;
    }
    L[HEAD].next = head;
    int cnt = 0, p = HEAD, len = 0;
    for (int q = head; q != -1; q = L[q].next) len++;
    for (int i = 0; i < len - k + 1; i++) {
        if (i % k == 0) solve(p);
        p = L[p].next;
    }
    for (p = L[HEAD].next; L[p].next != -1; p = L[p].next)
        printf("%05d %d %05d\n", p, L[p].data, L[p].next);
    printf("%05d %d -1", p, L[p].data);
    return 0;
}
*/