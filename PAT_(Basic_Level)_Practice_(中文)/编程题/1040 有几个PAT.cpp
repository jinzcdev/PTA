// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805282389999616
#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    string str;
    cin >> str;
    int p = 0, a = 0, t = 0, ans = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'T') t++;
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'P') p++;
        if (str[i] == 'A') {
            ans = (ans + (p * t) % MOD) % MOD;
        }
        if (str[i] == 'T') t--;
    }
    printf("%d", ans);
    return 0;
}