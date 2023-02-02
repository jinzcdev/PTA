// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805143738892288
#include <bits/stdc++.h>
using namespace std;
int main() {
    int cnt[10] = {0};
    string s;
    cin >> s;
    for (auto it : s) cnt[it - '0']++;
    for (int i = 0; i < 10; i++)
        if (cnt[i] != 0) printf("%d:%d\n", i, cnt[i]);
    return 0;
}
