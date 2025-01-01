// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805283241443328
#include <iostream>
using namespace std;
const int maxn = 1010;
int shop[maxn] = {0}, eva[maxn] = {0};
int main(){
    string s1, s2;
    int cnt = 0;
    cin >> s1 >> s2;
    for(auto s : s1) shop[s]++;
    for(auto s : s2) {
        if (--shop[s] < 0) cnt++;
    }
    if (cnt > 0) cout << "No " << cnt;
    else cout << "Yes " << s1.length() - s2.length();
    return 0;
}