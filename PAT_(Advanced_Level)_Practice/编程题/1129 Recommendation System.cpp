// https://pintia.cn/problem-sets/994805342720868352/problems/994805348471259136
#include <bits/stdc++.h>
using namespace std;
struct node {
    int id, cnt;
    node(int a, int b) : id(a), cnt(b){};
    bool operator<(const node& a) const {
        if ( cnt != a.cnt) return cnt > a.cnt;
        return id < a.id;
    }
};
int main() {
    int n, k, id, cntQuery[50010] = {0};
    cin >> n >> k;
    set<node> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &id);
        if (i != 0) {
            printf("%d:", id);
            int cnt = 0;
            for (auto it = s.begin(); cnt < k && it != s.end(); it++) {
                printf(" %d", it->id);
                cnt++;
            }
            printf("\n");
        }
        auto it = s.find(node(id, cntQuery[id]));
        if (it != s.end()) s.erase(it);
        cntQuery[id]++;
        s.insert(node(id, cntQuery[id]));
    }
    return 0;
}