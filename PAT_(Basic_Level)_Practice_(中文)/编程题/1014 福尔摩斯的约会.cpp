// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805308755394560
#include <bits/stdc++.h>
using namespace std;
int main() {
    char day[10][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int cnt1 = 0, cnt2 = 0;
    bool flag = false;
    for (int pos = 0; pos < s1.size() && pos < s2.size(); pos++) {
        if (s1[pos] != s2[pos]) continue;
        if (flag && (isdigit(s1[pos]) || (s1[pos] >= 'A' && s1[pos] <= 'N')) && ++cnt2 == 1) {
            printf("%02d", isdigit(s1[pos]) ? s1[pos] - '0' : s1[pos] - 'A' + 10);
        }
        if ((s1[pos] >= 'A' && s1[pos] <= 'G') && ++cnt1 == 1) {
            printf("%s ", day[s1[pos] - 'A']);
            flag = true;
        }
    }
    for (int i = 0; i < s3.size() && i < s4.size(); i++) {
        if (s3[i] == s4[i] && isalpha(s3[i])) {
            printf(":%02d", i);
            break;
        }
    }
    return 0;
}