// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805278589960192
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n), dpMax(n), dpMin(n), ans;
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    dpMax[0] = v[0];
    dpMin[n - 1] = v[n - 1];
    for (int i = 1; i < n; i++) {
        dpMax[i] = max(dpMax[i - 1], v[i]);
        dpMin[n - i - 1] = min(dpMin[n - i], v[n - i - 1]);
    }
    // for (int i = 0; i < n; i++) {
    //     cout << dpMax[i] << " ";
    // }
    // return 0;

    int left = 0;
    for (int i = 0; i < v.size(); i++) {
        bool flag = true;
        if (dpMax[i] != v[i] || dpMin[i] != v[i]) flag = false;
        // if (flag) {
        //     for (int j = i; j < v.size(); j++) {
        //         if (dpMax[i] > dpMax[j] || v[j] < v[i]) {
        //             flag = false;
        //             break;
        //         }
        //     }
        // }
        if (flag) {
            ans.push_back(v[i]);
            left = i;
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    if (ans.size() == 0) printf("\n");
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}