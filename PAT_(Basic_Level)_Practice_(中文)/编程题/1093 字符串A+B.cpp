// https://pintia.cn/problem-sets/994805260223102976/exam/problems/1071785884776722432
#include <bits/stdc++.h>
using namespace std;
int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);
    a += b;
    bool vis[128] = {false};
    for (int i = 0; i < a.length(); i++) {
        if (!vis[a[i]]) {
            vis[a[i]] = true;
            cout << a[i];
        }
    }
    return 0;
}