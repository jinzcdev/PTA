// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805291311284224
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    long long p;
    scanf("%d%ld", &n, &p);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int ans = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + ans; j < n; j++) {
            if (v[j] <= v[i] * p) {
                temp = j - i + 1;
                if (temp > ans) ans = temp;
            } else {
                break;
            }
        }
    }
    printf("%d", ans);
    return 0;
}