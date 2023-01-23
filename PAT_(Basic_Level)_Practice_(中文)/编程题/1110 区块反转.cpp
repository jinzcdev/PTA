// https://pintia.cn/problem-sets/994805260223102976/problems/1478634682663895040
#include <bits/stdc++.h>
using namespace std;
struct node {
    int adr, data, next;
};
int main() {
    int head, n, k, adr;
    scanf("%d%d%d", &head, &n, &k);
    vector<node> v(100000), l, ans;
    for (int i = 0; i < n; i++) {
        scanf("%d", &adr);
        scanf("%d%d", &v[adr].data, &v[adr].next);
        v[adr].adr = adr;
    }
    for (int p = head; p != -1; p = v[p].next) l.push_back(v[p]);
    int pos = l.size() - l.size() % k, left = pos - k;
    for (int i = pos; i < l.size(); i++) ans.push_back(l[i]);
    while (left >= 0) {
        for (int i = left; i <= left + k - 1; i++) ans.push_back(l[i]);
        left -= k;
    }
    for (int i = 0; i < ans.size() - 1; i++)
        printf("%05d %d %05d\n", ans[i].adr, ans[i].data, ans[i + 1].adr);
    printf("%05d %d -1\n", ans[ans.size() - 1].adr, ans[ans.size() - 1].data);
    return 0;
}