// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=721
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a;
    cin >> n;
    map<int, int> mp;
    while (n--) {
        scanf("%d", &a);
        mp[a]++;
    }
    for (auto &[k, v] : mp) printf("%d:%d\n", k, v);
    return 0;
}
