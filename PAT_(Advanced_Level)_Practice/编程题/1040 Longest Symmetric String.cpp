// https://pintia.cn/problem-sets/994805342720868352/problems/994805446102073344
#include <bits/stdc++.h>
using namespace std;
string str;
int solve(int left, int right) {
    while (left >= 0 && right < str.length() && str[left] == str[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}
int main() {
    getline(cin, str);
    int maxLen = 1;
    for (int i = 0; i < str.length() - 1; i++)
        maxLen = max(max(solve(i - 1, i + 1), solve(i, i + 1)), maxLen);
    printf("%d", maxLen);
    return 0;
}

/*
#include <bits/stdc++.h>
#define N 1010
using namespace std;
bool dp[N][N] = {false};
int main() {
    string s;
    getline(cin, s);
    int maxLen = 1;
    for (int i = 0; i < s.length(); i++) {
        dp[i][i] = true;
        if (i < s.length() - 1 && s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            maxLen = 2;
        }
    }
    for (int len = 3; len <= s.length(); len++) {
        for (int i = 0; i < s.length() - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
            if (dp[i][j]) maxLen = max(maxLen, j - i + 1);
        }
    }
    cout << maxLen;
    return 0;
}
*/


/*
#include <bits/stdc++.h>
using namespace std;
int main() {
    int maxLen = 1;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        int left = i - 1, right = i + 1, len = 0;
        while (left >= 0 && right <= s.length() - 1 && s[left] == s[right]) {
            len = right - left + 1;
            left--;
            right++;
        }
        maxLen = max(maxLen, len);
    }
    for (int i = 0; i < s.length() - 1; i++) {
        int left = i, right = i + 1, len = 0;
        while (left >= 0 && right <= s.length() - 1 && s[left] == s[right]) {
            len = right - left + 1;
            left--;
            right++;
        }
        maxLen = max(maxLen, len);
    }
    printf("%d", maxLen);
    return 0;
}
*/