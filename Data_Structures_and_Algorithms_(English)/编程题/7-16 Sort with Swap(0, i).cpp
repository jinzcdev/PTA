// https://pintia.cn/problem-sets/16/exam/problems/type/7?problemSetProblemId=678
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, pos[N];
vector<int> v;
int findError(int ie) {
    for (int i = ie + 1; i < v.size(); i++)
        if (v[i] != i) return i;
    return -1;
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