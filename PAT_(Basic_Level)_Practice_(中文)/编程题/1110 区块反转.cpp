// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1478634682663895040
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct node {
    int data, adr, next;
} L[N];
int main() {
    int head, n, k, adr, data, next;
    scanf("%d%d%d", &head, &n, &k);
    while (n--) {
        scanf("%d", &adr);
        scanf("%d%d", &L[adr].data, &L[adr].next);
        L[adr].adr = adr;
    }
    vector<node> v, ans;
    vector<vector<node> > l;
    for (int p = head; p != -1; p = L[p].next) {
        v.push_back(L[p]);
    }
    for (int i = 0; i <= v.size() - v.size() % k; i += k) {
        vector<node> tmp;
        for (int j = 0; j < k && j + i < v.size(); j++) {
            tmp.push_back(v[i + j]);
        }
        l.push_back(tmp);
    }
    for (int i = l.size() - 1; i >= 0; i--) {
        for (int j = 0; j < l[i].size(); j++) {
            ans.push_back(l[i][j]);
        }
    }
    for (int i = 0; i < ans.size() - 1; i++) {
        printf("%05d %d %05d\n", ans[i].adr, ans[i].data, ans[i + 1].adr);
    }
    printf("%05d %d -1", ans[ans.size() - 1].adr, ans[ans.size() - 1].data);
    return 0;
}