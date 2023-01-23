// https://pintia.cn/problem-sets/994805260223102976/problems/994805286714327040
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, pos = 1, j;
    scanf("%d", &n);
    vector<int> origin(n), v(n);
    for (int i = 0; i < n; i++) scanf("%d", &origin[i]);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    while (pos < n && v[pos - 1] <= v[pos]) j = ++pos;
    while (pos < n && origin[pos] == v[pos]) pos++;
    if (pos == n) {
        printf("Insertion Sort\n");
        sort(origin.begin(), origin.begin() + j + 1);
    } else {
        printf("Merge Sort\n");
        for (int step = 2; step <= n; step *= 2) {
            bool flag = (origin == v);
            for (int i = 0; i + step - 1 < n; i += step)
                sort(origin.begin() + i, origin.begin() + i + step);
            sort(origin.begin() + n / step * step, origin.end());
            if (flag) break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", origin[i]);
    }
    return 0;
}