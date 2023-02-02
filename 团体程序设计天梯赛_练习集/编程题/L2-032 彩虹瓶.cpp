// https://pintia.cn/problem-sets/994805046380707840/exam/problems/1111914599412858889
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    while (k--) {
        stack<int> s;
        queue<int> q;
        int a, need = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            q.push(a);
        }
        while (need <= n) {
            if (!s.empty() && s.top() == need) {
                need++;
                s.pop();
            } else if (!q.empty()) {
                if (q.front() == need) need++;
                else {
                    if (s.size() == m) break;
                    s.push(q.front());
                }
                q.pop();
            } else break;
        }
        printf("%s\n", need == n + 1 ? "YES" : "NO");
    }
    return 0;
}