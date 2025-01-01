// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805301562163200
#include <bits/stdc++.h>
using namespace std;
struct node {
    double stock, price, sell;
};
bool cmp(node a, node b) { return a.price > b.price; }
int main() {
    int n;
    double d;
    cin >> n >> d;
    vector<node> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].stock;
    for (int i = 0; i < n; i++) {
        cin >> v[i].sell;
        v[i].price = v[i].sell / v[i].stock;
    }
    sort(v.begin(), v.begin() + n, cmp);
    double ans = 0.0;
    for (int i = 0; i < n && d > 0; i++) {
        ans += v[i].stock >= d ? v[i].price * d : v[i].sell;
        d -= v[i].stock;
    }
    printf("%.2f\n", ans);
    return 0;
}