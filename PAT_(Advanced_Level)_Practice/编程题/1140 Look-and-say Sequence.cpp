// https://pintia.cn/problem-sets/994805342720868352/problems/994805344490864640
#include <bits/stdc++.h>
using namespace std;
int main() {
    int d, n;
    scanf("%d%d", &d, &n);
    vector<int> ans, temp;
    ans.push_back(d);
    while (n--) {
        int pre = ans[0], cnt = 0;
        temp = ans;
        ans.clear();
        for (int j = 0; j < temp.size(); j++) {
            if (pre == temp[j]) cnt++;
            else {
                ans.push_back(pre);
                ans.push_back(cnt);
                cnt = 1;
                pre = temp[j];
            }
        }
        ans.push_back(pre);
        ans.push_back(cnt);
    }
    for (auto it : temp) printf("%d", it);
    return 0;
}