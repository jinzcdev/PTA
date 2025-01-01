// https://pintia.cn/problem-sets/16/exam/problems/type/7?problemSetProblemId=665
#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n, k, a;
    scanf("%d%d%d", &m, &n, &k);
    vector<int> v(n);
    while (k--) {
    bool ins[1010] = {false};
        stack<int> s;
        bool flag = true;
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);
        for (int i = 0; i < n; i++) {
            for (int j = 1; s.size() < m && j <= v[i]; j++) {
                if (ins[j] == false) {
                    s.push(j);
                    ins[j] = true;
                }
            }
            if (v[i] != s.top()) {
                flag = false;
                break;
            }
            s.pop();
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}