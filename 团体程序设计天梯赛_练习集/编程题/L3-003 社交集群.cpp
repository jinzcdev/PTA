// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805053141925888
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int father[N];
int findFather(int x) {
    return x == father[x] ? x : father[x] = findFather(father[x]);
}
void uni(int a, int b) {
    int faA = findFather(a), faB = findFather(b);
    if (faA != faB) father[faA] = faB;
}
int main() {
    for (int i = 0; i < N; i++) father[i] = i;
    int n, k, a, hobby[N] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &a);
            if (hobby[a] == 0)
                hobby[a] = i;
            else
                uni(i, hobby[a]);
        }
    }
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int i = 1; i <= n; i++) mp[findFather(i)]++;
    for (auto it : mp) ans.push_back(it.second);
    printf("%d\n", mp.size());
    sort(ans.begin(), ans.end());
    for (int i = ans.size() - 1; i >= 0; i--) {
        printf("%d", ans[i]);
        if (i != 0) printf(" ");
    }
    return 0;
}