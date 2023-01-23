// https://pintia.cn/problem-sets/994805260223102976/problems/994805292322111488
#include <iostream>
using namespace std;
bool hashMap[260], vis[260];
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s2.size(); i++) {
        hashMap[s2[i]] = true;
    }
    for (int i = 0; i < s1.size(); i++) {
        if (hashMap[s1[i]] == false) {
            char ch = s1[i];
            if (ch >= 'a' && ch <= 'z') ch -= 32;
            if (!vis[ch]) {
                printf("%c", ch);
                vis[ch] = true;
            }
        }
    }
    return 0;
}