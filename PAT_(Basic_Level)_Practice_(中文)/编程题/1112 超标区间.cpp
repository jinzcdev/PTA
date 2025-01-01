// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1621699370158747648
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t;
    scanf("%d%d", &n, &t);
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    bool found = false, flag = false;
    int start = 0, MAX = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] > t) {
            if (!found) {
                found = true;
                start = i;
            }
            flag = true;
        } else if (found) {
            printf("[%d, %d]\n", start, i - 1);
            found = false;
        }
        MAX = max(MAX, v[i]);
    }
    if (found) {
        printf("[%d, %d]\n", start, n - 1);
        flag = true;
    }
    if (!flag) printf("%d", MAX);
    return 0;
}