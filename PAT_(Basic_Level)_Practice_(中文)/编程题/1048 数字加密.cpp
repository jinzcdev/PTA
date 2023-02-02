// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805276438282240
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b, s = "JQK";
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string ans = a.length() > b.length() ? a : b;
    int maxlen = max(a.length(), b.length());
    for (int i = 0; i < maxlen; i++) {
        int ta = i < a.length() ? a[i] - '0' : 0;
        int tb = i < b.length() ? b[i] - '0' : 0;
        if (i % 2 == 0) {
            int tmp = (ta + tb) % 13;
            ans[i] = tmp < 10 ? '0' + tmp : s[tmp - 10];
        } else {
            int tmp = tb - ta;
            ans[i] = '0' + (tmp < 0 ? tmp + 10 : tmp);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}

/*
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 110;
char a[maxn], b[maxn], ans[maxn] = {0};
int main() {
    scanf("%s %s", a, b);
    int lenA = strlen(a), lenB = strlen(b);
    int len = max(lenA, lenB);
    reverse(a, a + lenA);
    reverse(b, b + lenB);
    for (int i = 0; i < len; i++) {
        int numA = i < lenA ? a[i] - '0' : 0;
        int numB = i < lenB ? b[i] - '0' : 0;
        // 索引为偶数,序号为奇数
        if (i % 2 == 0) {
            int temp = (numA + numB) % 13;
            if (temp == 10) ans[i] = 'J';
            else if (temp == 11) ans[i] = 'Q';
            else if (temp == 12) ans[i] = 'K';
            else ans[i] = temp + '0';
        } else {
            int temp = numB - numA;
            if (temp >= 0) ans[i] = temp + '0';
            else ans[i] = (temp + 10) + '0';
        }
    }
    reverse(ans, ans + len);
    printf("%s", ans);
    return 0;
}
*/