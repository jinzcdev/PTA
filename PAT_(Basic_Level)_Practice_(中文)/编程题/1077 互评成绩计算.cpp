// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805262303477760
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, t, teacher;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> teacher;
        vector<int> v;
        double student = 0;
        for (int j = 0; j < n - 1; j++) {
            cin >> t;
            if (t >= 0 && t <= m) v.push_back(t);
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size() - 1; i++) student += v[i];
        student /= v.size() - 2;
        printf("%.0f\n", round((teacher + student) / 2));
    }
    return 0;
}