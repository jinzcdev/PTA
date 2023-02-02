// https://pintia.cn/problem-sets/16/exam/problems/665
// 5 7 5
// 1 2 3 4 5 6 7
// 3 2 1 7 5 6 4
// 7 6 5 4 3 2 1
// 5 6 4 3 7 2 1
// 1 7 6 5 4 3 2
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