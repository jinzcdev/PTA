// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805286714327040
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> origin(n), v(n);
    for (int i = 0; i < n; i++) scanf("%d", &origin[i]);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    int pos = 1, len;
    while (pos < n && v[pos - 1] <= v[pos]) pos++;
    len = pos;
    while (pos < n && v[pos] == origin[pos]) pos++;
    if (pos == n) {
        cout << "Insertion Sort\n";
        sort(origin.begin(), origin.begin() + len + 1);
    } else {
        printf("Merge Sort\n");
        int step = 2;
        while (step <= n) {
            for (int i = 0; i < n; i += step) {
                int end = min(i + step, n);
                sort(origin.begin() + i, origin.begin() + end);
            }
            step *= 2;
            bool flag = true;
            for (int i = 0; i < n; i++) {
                if (origin[i] != v[i]) {
                    flag = false;
                }
            }
            if (flag) break;
        }
        if (step > n) step = n;
        for (int i = 0; i < n; i += step) {
            int end = min(i + step, n);
            sort(origin.begin() + i, origin.begin() + end);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", origin[i]);
    }
    return 0;
}