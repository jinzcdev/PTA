// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805361586847744
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
        while (k--) {
            scanf("%d", &a);
            if (hobby[a] == 0) hobby[a] = i;
            else uni(i, findFather(hobby[a]));
        }
    }
    unordered_map<int, int> mcnt;
    vector<int> ans;
    for (int i = 1; i <= n; i++) mcnt[findFather(i)]++;
    for (auto it : mcnt) ans.push_back(it.second);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = ans.size() - 1; i >= 0; i--) {
        printf("%d", ans[i]);
        if (i != 0) printf(" ");
    }
    return 0;
}