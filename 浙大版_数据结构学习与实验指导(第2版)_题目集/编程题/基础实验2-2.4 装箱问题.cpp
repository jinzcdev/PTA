// https://pintia.cn/problem-sets/988034414048743424/exam/problems/988036689915572224
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a;
    vector<int> r;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        int i = 0, flag = 0;
        for (; i < r.size(); i++) {
            if (r[i] >= a) {
                flag = 1;
                r[i] -= a;
                break;
            }
        }
        if (!flag) r.push_back(100 - a);
        printf("%d %d\n", a, i + 1);
    }
    printf("%d", r.size());
    return 0;
}