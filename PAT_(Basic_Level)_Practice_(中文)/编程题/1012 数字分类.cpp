// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805311146147840
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ans(5, 0);
    int t, cntA4 = 0, cntA2 = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t % 5 == 0 && t % 2 == 0) ans[0] += t;
        if (t % 5 == 1) {
            if (flag) ans[1] += t;
            else ans[1] -= t;
            flag = !flag;
            cntA2++;
        }
        if (t % 5 == 2) ans[2]++;
        if (t % 5 == 3) {
            ans[3] += t;
            cntA4++;
        }
        if (t % 5 == 4) ans[4] = max(ans[4], t);
    }
    for (int i = 0; i < 5; i++) {
        if (i != 0) printf(" ");
        if (i == 1) {
            if (cntA2 == 0) printf("N");
            else printf("%d", ans[1]);
            continue;
        }
        if (ans[i] == 0) printf("N");
        else if (i == 3) printf("%.1f", ans[i] * 1.0 / cntA4);
        else printf("%d", ans[i]);
    }
    return 0;
}