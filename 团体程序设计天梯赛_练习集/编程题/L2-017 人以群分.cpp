// https://pintia.cn/problem-sets/994805046380707840/problems/994805061056577536
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    printf("Outgoing #: %d\nIntroverted #: %d\n", (n + 1) / 2, n / 2);
    int sum = 0;
    for (int i = 0; i < n / 2; i++) sum += (v[n - i - 1] - v[i]);
    if (n % 2 == 1) sum += v[n / 2];
    printf("Diff = %d", sum);
    return 0;
}
