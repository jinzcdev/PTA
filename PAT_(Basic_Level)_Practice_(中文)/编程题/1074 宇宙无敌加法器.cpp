// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805263297527808
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 30;
struct bign {
    int d[N], len;
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};
bign change(string str) {
    bign a;
    // int pos = 0;
    // while (str[pos] == '0') pos++;
    // str = str.substr(pos);
    a.len = str.length();
    for (int i = 0; i < a.len; i++) {
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}
int main() {
    string n, s1, s2;
    cin >> n >> s1 >> s2;
    bign a = change(s1), b = change(s2);
    reverse(n.begin(), n.end());
    int ans[N] = {0}, carry = 0, len = 0;
    for (int i = 0; i < a.len || i < b.len; i++) {
        int base = n[i] == '0' ? 10 : n[i] - '0';
        int temp = a.d[i] + b.d[i] + carry;
        ans[len++] = temp % base;
        carry = temp / base;
    }
    if (carry != 0) ans[len++] = carry;
    while (len > 1 && ans[len - 1] == 0) len--;
    if (len == 0)
        printf("0");
    else
        for (int i = len - 1; i >= 0; i--) {
            printf("%d", ans[i]);
        }
    return 0;
}