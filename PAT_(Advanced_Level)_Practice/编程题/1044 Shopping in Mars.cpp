// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805439202443264
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> presum;
int solve(int i, int &tempsum) {
    int left = i, right = n, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        tempsum = presum[mid] - presum[i - 1];
        if (m < tempsum) right = mid - 1;
        else if (m > tempsum) left = mid + 1;
        else break;
    }
    tempsum = presum[mid] - presum[i - 1];
    if (tempsum >= m) return mid;
    else {
        tempsum = presum[mid + 1] - presum[i - 1];
        return mid + 1;
    }
}
int main() {
    scanf("%d%d", &n, &m);
    presum.resize(n + 1);
    presum[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &presum[i]);
        presum[i] += presum[i - 1];
    }
    vector<pair<int, int> > ans;
    int minans = presum[n];
    for (int i = 1; i <= n; i++) {
        int tempsum;
        int pos = solve(i, tempsum);
        // printf("left = %d. right = %d, sum = %d\n", i, pos, tempsum);
        if (tempsum > minans) continue;
        if (tempsum >= m) {
            if (tempsum < minans) {
                ans.clear();
                minans = tempsum;
            }
            ans.push_back({i, pos});
        }
    }
    for (auto it : ans) {
        printf("%d-%d\n", it.first, it.second);
    }
    return 0;
}