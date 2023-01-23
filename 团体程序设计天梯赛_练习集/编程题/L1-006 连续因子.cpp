// https://pintia.cn/problem-sets/994805046380707840/problems/994805138600869888
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> ans, fac;
    int sqr = sqrt(n) + 1;
    for (int i = 2; i <= sqr; i++)
        if (n % i == 0) fac.push_back(i);
    for (int i = 0; i < fac.size(); i++) {
        vector<int> v = {fac[i]};
        int tmp = n / fac[i];
        for (int j = i + 1; j < fac.size() && fac[j] <= tmp; j++) {
            if (fac[j] != fac[j - 1] + 1 || tmp % fac[j] != 0) break;
            v.push_back(fac[j]);
            tmp /= fac[j];
        }
        if (v.size() > ans.size()) ans = v;
    }
    if (ans.size() == 0) printf("1\n%d", n);
    else {
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) cout << "*";
            printf("%d", ans[i]);
        }
    }
    return 0;
}