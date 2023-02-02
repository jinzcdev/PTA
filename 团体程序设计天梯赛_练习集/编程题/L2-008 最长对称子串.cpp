// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805067704549376
#include <bits/stdc++.h>
using namespace std;
int solve(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left + 1 - 2;
}
int main() {
    string s;
    getline(cin, s);
    int ans = 1;
    for (int i = 0; i < s.length(); i++) {
        ans = max(ans, solve(s, i, i));
        ans = max(ans, solve(s, i, i + 1));
    }
    printf("%d", ans);
    return 0;
}
/*
def solve(s, left, right):
    while left >= 0 and right < len(s) and s[left] == s[right]:
        left -= 1
        right += 1
    return right - left + 1 - 2

s = list(input())
ans = 1
for i in range(len(s)):
    ans = max(ans, solve(s, i, i))
    ans = max(ans, solve(s, i, i + 1))
print(ans)
*/