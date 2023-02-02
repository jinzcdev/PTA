// https://pintia.cn/problem-sets/15/exam/problems/2999
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    unordered_map<int, int> cnt;
    vector<int> ans;
    while (scanf("%d", &a), a != -1) cnt[a]++;
    while (scanf("%d", &a), a != -1) {
        if (cnt[a]-- > 0) {
            ans.push_back(a);
        }
    }
    if (ans.size() == 0) {
        printf("NULL\n");
        return 0;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}