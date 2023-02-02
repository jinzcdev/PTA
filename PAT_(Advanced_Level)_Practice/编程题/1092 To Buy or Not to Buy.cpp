// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805374509498368
#include <iostream>
using namespace std;
const int maxn = 1010;
int shop[maxn] = {0}, eva[maxn] = {0};
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    for(auto s : s1) shop[s]++;
    int cnt = 0;
    for(auto s : s2) {
        if (--shop[s] < 0) {
            cnt++;
        }
    }
    if (cnt > 0) cout << "No " << cnt;
    else cout << "Yes " << s1.length() - s2.length();
    return 0;
}