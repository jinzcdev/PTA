// https://pintia.cn/problem-sets/994805342720868352/exam/problems/1478635841315209216
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
struct node {
    int adr, data, next;
} L[maxn];
int main() {
    int start, n, k, adr;
    scanf("%d%d%d", &start, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &adr);
        scanf("%d%d", &L[adr].data, &L[adr].next);
        L[adr].adr = adr;
    }
    vector<node> l, ans;
    for (int p = start; p != -1; p = L[p].next) {
        l.push_back(L[p]);
    }
    int pos = l.size() - l.size() % k;
    for (int i = pos; i < l.size(); i++) ans.push_back(l[i]);
    for (int i = pos - k; i >= 0; i -= k) {
        for (int j = i; j < i + k; j++) {
            ans.push_back(l[j]);
        }
    }
    for (int i = 0; i < ans.size() - 1; i++) {
        printf("%05d %d %05d\n", ans[i].adr, ans[i].data, ans[i + 1].adr);
    }
    printf("%05d %d -1\n", ans[ans.size() - 1].adr, ans[ans.size() - 1].data);
    return 0;
}