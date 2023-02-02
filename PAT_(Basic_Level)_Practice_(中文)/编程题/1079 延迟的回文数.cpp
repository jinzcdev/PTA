// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805261754023936
#include <algorithm>
#include <iostream>
using namespace std;
bool isPalindrome(string str) {
    for (int i = 0; i < str.length() / 2; i++)
        if (str[i] != str[str.length() - i - 1]) return false;
    return true;
}
string sumStr(string str) {
    string ans = str;
    reverse(ans.begin(), ans.end());
    printf("%s + %s = ", str.c_str(), ans.c_str());
    int carry = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
        int temp = (str[i] - '0') + (ans[i] - '0') + carry;
        ans[i] = temp % 10 + '0';
        carry = temp / 10;
    }
    if (carry != 0) ans = "1" + ans;
    cout << ans << endl;
    return ans;
}
void solve(string str, int cnt) {
    if (isPalindrome(str)) {
        printf("%s is a palindromic number.\n", str.c_str());
        return;
    }
    if (cnt == 10) {
        printf("Not found in 10 iterations.\n");
        return;
    }
    solve(sumStr(str), cnt + 1);
}
int main() {
    string str;
    cin >> str;
    solve(str, 0);
    return 0;
}