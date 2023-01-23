// https://pintia.cn/problem-sets/994805260223102976/problems/994805264706813952
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    if (n == 1)
        printf("%d", v[0]);
    else {
        double ans = v[0];
        for (int i = 1; i < v.size(); i++) {
            ans = (ans + v[i]) / 2;
        }
        printf("%d", (int)ans);
    }
    return 0;
}