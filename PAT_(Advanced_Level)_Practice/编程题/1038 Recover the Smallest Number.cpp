// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805449625288704
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 10010;
string str[maxn];
bool cmp(string a, string b) {
    return a + b < b + a;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    string ans;
    for(int i = 0; i < n; i++) {
        ans += str[i];
    }
    while(ans.size() != 0 && ans[0] == '0') {
        ans.erase(ans.begin());
    }
    if(ans.size() == 0) cout << 0;
    else cout << ans;
    return 0;
}
