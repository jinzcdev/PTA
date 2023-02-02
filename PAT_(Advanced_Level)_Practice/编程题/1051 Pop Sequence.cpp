// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805427332562944
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    while (k--) {
        stack<int> s;
        vector<int> v(n);
        bool pushed[1010] = {false};
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);
        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= v[i]; j++) {
                if (!pushed[j]) {
                    if (s.size() == m) break;
                    s.push(j);
                    pushed[j] = true;
                }
            }
            if (s.top() != v[i]) {
                printf("NO\n");
                flag = false;
                break;
            }
            s.pop();
        }
        if (flag) printf("YES\n");
    }
    return 0;
}