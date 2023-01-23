// https://pintia.cn/problem-sets/994805046380707840/problems/994805100684361728
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    char ch;
    string s;
    scanf("%d %c", &n, &ch);
    getchar();
    getline(cin, s);
    if (s.length() >= n) {
        cout << s.substr(s.length() - n);
    } else {
        for (int i = 0; i < n - s.length(); i++) {
            printf("%c", ch);
        }
        cout << s;
    }
    return 0;
}