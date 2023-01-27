// https://pintia.cn/problem-sets/91827364500/problems/91827370500
#include <bits/stdc++.h>
using namespace std;
int main() {
    char vowel[] = {'a', 'e', 'i', 'y', 'o', 'u'};
    bool isvowel[128] = {false};
    for (int i = 0; i < 6; i++) isvowel[vowel[i]] = true;
    int n;
    scanf("%d", &n);
    while (n--) {
        string s;
        cin >> s;
        cout << s[0];
        for (int i = 1; i < s.length(); i++) {
            if (!isvowel[s[i]]) cout << s[i];
        }
        cout << endl;
    }
    return 0;
}