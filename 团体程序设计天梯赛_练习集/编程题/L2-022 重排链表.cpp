// https://pintia.cn/problem-sets/994805046380707840/problems/994805057860517888
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
struct node {
    int adr, data, next;
} L[N];
int main() {
    int head, n, adr, data, next;
    scanf("%d%d", &head, &n);
    while (n--) {
        scanf("%d", &adr);
        scanf("%d%d", &L[adr].data, &L[adr].next);
        L[adr].adr = adr;
    }
    vector<node> v, ans;
    for (int p = head; p != -1; p = L[p].next) v.push_back(L[p]);
    for (int i = 0; i < v.size() / 2; i++) {
        ans.push_back(v[v.size() - i - 1]);
        ans.push_back(v[i]);
    }
    if (v.size() % 2 != 0) ans.push_back(v[v.size() / 2]);
    for (int i = 0; i < ans.size() - 1; i++)
        printf("%05d %d %05d\n", ans[i].adr, ans[i].data, ans[i + 1].adr);
    printf("%05d %d -1\n", ans[ans.size() - 1].adr, ans[ans.size() - 1].data);
    return 0;
}
