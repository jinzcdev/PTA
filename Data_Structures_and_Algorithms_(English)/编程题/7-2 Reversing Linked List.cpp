// https://pintia.cn/problem-sets/16/exam/problems/type/7?problemSetProblemId=664
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct node {
    int adr, data, next;
} L[N];
int main() {
    int head, n, k, adr;
    scanf("%d%d%d", &head, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &adr);
        scanf("%d%d", &L[adr].data, &L[adr].next);
        L[adr].adr = adr;
    }
    vector<node> l, ans;
    for (int p = head; p != -1; p = L[p].next) l.push_back(L[p]);
    for (int i = 0; i + k - 1 < l.size(); i += k) {
        for (int j = i + k - 1; j >= i; j--) {
            ans.push_back(l[j]);
        }
    }
    int j = l.size() - l.size() % k;
    while (j < l.size()) ans.push_back(l[j++]);
    for (int i = 0; i < l.size() - 1; i++)
        printf("%05d %d %05d\n", ans[i].adr, ans[i].data, ans[i + 1].adr);
    printf("%05d %d -1", ans[l.size() - 1].adr, ans[l.size() - 1].data);
    return 0;
}