// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805360777347072
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, cnt = 0;
    double sum = 0;
    cin >> n;
    string s, tmp;
    while (n--) {
        cin >> s;
        tmp = s;
        int cntDot = 0, cntDigit = 0;
        bool valid = true;
        if (s[0] == '-') s.erase(s.begin());
        bool hasDot = s.find_last_of('.') != string::npos;
        while (hasDot && *s.rbegin() == '0') s.erase(s.end() - 1);
        if (hasDot && *s.rbegin() == '.') s.erase(s.end() - 1);
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) cntDigit++;
            if ((s[i] != '.' && !isdigit(s[i])) ||
                ((s[i] == '.' && (++cntDot > 1 || i == 0 || i == s.size() - 1 ||
                                  s.size() - 1 - i > 2)))) {
                valid = false;
                break;
            }
        }
        if (valid && cntDigit > 0) {
            double t = stod(tmp);
            if (t >= -1000 && t <= 1000) {
                sum += t;
                cnt++;
                continue;
            }
        }
        printf("ERROR: %s is not a legal number\n", tmp.c_str());
    }
    if (cnt == 0) printf("The average of 0 numbers is Undefined\n");
    else printf("The average of %d number%s is %.2f\n", cnt, cnt != 1 ? "s" : "", sum / cnt);
    return 0;
}
/* python
n = int(input())
number = map(str, input().split())
ans = 0.0
temp = 0.0
cnt = 0
for it in number:
    try:
        temp = float(it)
        if (temp < -1000 or temp > 1000) or (it.find('.') != -1 and (len(it) - it.find('.') - 1 > 2)):
            print("ERROR: %s is not a legal number" % it)
        else:
            ans += temp
            cnt = cnt + 1
    except:
        print("ERROR: %s is not a legal number" % it)
if cnt == 0:
    print("The average of 0 numbers is Undefined")
elif cnt == 1:
    print("The average of 1 number is %.2f" % ans)
else:
    print("The average of %d numbers is %.2f" % (cnt, ans / cnt))
*/