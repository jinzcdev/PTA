// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1518582383141380096
#include <bits/stdc++.h>
using namespace std;
struct node {
    int h, m, s, ts;
};
typedef pair<node, node> timepair;
bool cmp(timepair &t1, timepair &t2) { return t1.first.ts < t2.first.ts; }
int main() {
    int n;
    cin >> n;
    vector<timepair> v(n);
    for (int i = 0; i < n; i++) {
        timepair &t = v[i];
        scanf("%d:%d:%d - ", &t.first.h, &t.first.m, &t.first.s);
        scanf("%d:%d:%d - ", &t.second.h, &t.second.m, &t.second.s);
        t.first.ts = t.first.h * 3600 + t.first.m * 60 + t.first.s;
        t.second.ts = t.second.h * 3600 + t.second.m * 60 + t.second.s;
    }
    sort(v.begin(), v.end(), cmp);
    if (v[0].first.ts != 0) {
        printf("00:00:00 - %02d:%02d:%02d\n", v[0].first.h,
               v[0].first.m, v[0].first.s);
    }
    for (int i = 0; i < n - 1; i++) {
        node &a = v[i].second, &b = v[i + 1].first;
        if (a.ts < b.ts) {
            printf("%02d:%02d:%02d - %02d:%02d:%02d\n", a.h, a.m, a.s, b.h, b.m,
                   b.s);
        }
    }

    if (v[n - 1].second.ts != 23 * 3600 + 59 * 60 + 59) {
        printf("%02d:%02d:%02d - 23:59:59\n", v[n - 1].second.h,
               v[n - 1].second.m, v[n - 1].second.s);
    }
    return 0;
}
