// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1621699394422779904
#include <bits/stdc++.h>
using namespace std;

const int base = 30;
string num_to_char = "0123456789abcdefghijklmnopqrst";
map<char, int> char_to_num;

int to_decimal(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) res = res * base + char_to_num[s[i]];
    return res;
}

string to_base30(int num) {
    if (num == 0) return "0";
    string res;
    while (num > 0) {
        int mod = num % base;
        res += num_to_char[mod];
        num /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

string add(string a, string b) {
    string res;
    int carry = 0, i = a.length() - 1, j = b.length() - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
        int x = i >= 0 ? char_to_num[a[i--]] : 0;
        int y = j >= 0 ? char_to_num[b[j--]] : 0;
        int z = x + y + carry;
        carry = z / base;
        res += num_to_char[z % base];
    }
    reverse(res.begin(), res.end());
    while (res.size() > 1 && res[0] == '0') res.erase(res.begin());
    return res;
}

int main() {
    for (int i = 0; i < num_to_char.length(); i++)
        char_to_num[num_to_char[i]] = i;
    string a, b;
    cin >> a >> b;
    cout << add(a, b);
    return 0;
}