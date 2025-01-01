// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1478633632938655744
#include <bits/stdc++.h>
using namespace std;
int n, x;
bool flag = false;
vector<int> v, tmp;
void dfs(int sum, int num, int i) {
    if (num == 4) {
        if (sum % x == 0) flag = true;
        return;
    }
    if (flag || i == v.size()) return;
    tmp.push_back(v[i]);
    dfs(sum + v[i], num + 1, i + 1);
    tmp.pop_back();
    dfs(sum, num, i + 1);
}
int main() {
    scanf("%d", &n);
    while (n--) {
        flag = false;
        v.clear();
        tmp.clear();
        scanf("%d", &x);
        int sqr = (int)sqrt(x);
        for (int p = 1; p <= sqr; p++) {
            if (x % p == 0) {
                v.push_back(p);
                if (x != p * p) v.push_back(x / p);
            }
        }
        if (v.size() < 4) printf("No\n");
        else {
            dfs(0, 0, 0);
            printf("%s\n", flag ? "Yes" : "No");
        }
    }
    return 0;
}