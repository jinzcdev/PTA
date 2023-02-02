// https://pintia.cn/problem-sets/434/exam/problems/5865
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
bool cmp(pii a, pii b) { return a.second > b.second; }
void print(unordered_map<int, int> &mp) {
    vector<pii> v;
    for (const auto &it : mp) {
        if (it.second != 0) {
            v.push_back({it.second, it.first});
        }
    }
    sort(v.begin(), v.end(), cmp);
    if (v.size() == 0) {
        printf("0 0\n");
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d %d", v[i].first, v[i].second);
    }
    printf("\n");
}
int main() {
    int n, a, b;
    unordered_map<int, int> ca, cb, ans;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        ca[b] = cb[b] = a;
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        ca[b] += a;
        for (const auto &it : cb) {
            ans[it.first + b] += it.second * a;
        }
    }
    print(ans);
    print(ca);
    return 0;
}