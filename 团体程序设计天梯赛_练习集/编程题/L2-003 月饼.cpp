// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805071789801472
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    double stock, price, sell;
};
bool cmp(node a, node b) { return a.price > b.price; }
int main() {
    int n, d;
    vector<node> v(1010);
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> v[i].stock;
    for (int i = 0; i < n; i++) {
        cin >> v[i].sell;
        v[i].price = v[i].sell / v[i].stock;
    }
    sort(v.begin(), v.begin() + n, cmp);
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        if (v[i].stock >= d) {
            ans += v[i].price * d;
            break;
        } else {
            ans += v[i].sell;
            d -= v[i].stock;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}