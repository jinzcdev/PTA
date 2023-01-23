// https://pintia.cn/problem-sets/994805342720868352/problems/994805394512134144
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100000;

struct node {
    int adr, data, next;
} s;

int main() {
    int head, n, k;
    scanf("%d%d%d", &head, &n, &k);
    vector<node> temp(maxn), l, ans;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &s.adr, &s.data, &s.next);
        temp[s.adr] = s;
    }
    for (int p = head; p != -1; p = temp[p].next) {
        l.push_back(temp[p]);
    }
    if (l.size() < k) {
        ans = l;
    } else {
        int i = 0;
        for (; i < l.size();) {
            if (i + k - 1 <= l.size() - 1) {
                for (int j = i + k - 1; j >= i; j--){
                    ans.push_back(l[j]);
                }
                i += k;
            } else {
                break;
            }
        }
        while (i < l.size()) {
            ans.push_back(l[i++]);
        }
    }
    for (int i = 0; i < ans.size() - 1; i++) {
        printf("%05d %d %05d\n", ans[i].adr, ans[i].data, ans[i + 1].adr);
    }
    printf("%05d %d -1\n", ans[l.size() - 1].adr, ans[l.size() - 1].data);
    return 0;
}