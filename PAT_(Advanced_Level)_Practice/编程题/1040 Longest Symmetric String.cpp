// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805446102073344
#include <bits/stdc++.h>
using namespace std;
int middle(string s, int mid) {
    int left = mid - 1, right = mid + 1;
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}
int twosides(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}
int main() {
    string s;
    getline(cin, s);
    if (s.length() <= 1) {
        printf("1");
        return 0;
    }
    int maxLen = 1;
    for (int i = 0; i < s.length() - 1; i++) {
        int temp = max(middle(s, i), twosides(s, i, i + 1));
        maxLen = max(maxLen, temp);
    }
    printf("%d", maxLen);
    return 0;
}