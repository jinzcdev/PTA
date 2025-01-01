// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805403651522560
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, pos[N];
vector<int> v;
int findError(int ie) {
    int i = ie + 1;
    while (i < n && v[i] == i) i++;
    if (i == n) return -1;  // the array is ordered
    return i;
}
int main() {
    int t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        v.push_back(t);
        pos[t] = i;
    }
    int i_zero = pos[0], i_error = 0, cnt = 0;
    while (true) {
        if (i_zero == 0) {
            i_error = findError(i_error);
            if (i_error == -1) break;
            swap(v[i_zero], v[i_error]);
            pos[v[i_zero]] = 0;
            i_zero = i_error;
        } else {
            swap(v[i_zero], v[pos[i_zero]]);
            i_zero = pos[i_zero];
        }
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}