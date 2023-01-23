// https://pintia.cn/problem-sets/994805260223102976/problems/994805282389999616
#include <iostream>
using namespace std;
int main() {
    string str;
    cin >> str;
    int p = 0, a = 0, t = 0, ans = 0;
    for (int i = 0; i < str.length(); i++) if (str[i] == 'T') t++;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'P') p++;
        if (str[i] == 'A') ans = (ans + (p * t) % 1000000007) % 1000000007;
        if (str[i] == 'T') t--;
    }
    printf("%d", ans);
    return 0;
}
/*
// https://pintia.cn/problem-sets/994805260223102976/problems/994805282389999616
#include <iostream>
using namespace std;
const int N = 100010;
int main() {
    string s;
    cin >> s;
    int dpP[N], dpT[N], len = s.length(), ans = 0;
    dpP[0] = dpT[len - 1] = 0;
    for (int i = 1; i < len; i++) {
        dpP[i] = dpP[i - 1] + (s[i - 1] == 'P');
        dpT[len - i - 1] = dpT[len - i] + (s[len - i] == 'T');
    }
    for (int i = 0; i < len; i++)
        if (s[i] == 'A') ans = (ans + (dpP[i] * dpT[i]) % 1000000007) % 1000000007;
    cout << ans;
    return 0;
}
*/