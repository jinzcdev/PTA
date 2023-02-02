// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805113036587008
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == 'g' || ch == 'G') a++;
        if (ch == 'p' || ch == 'P') b++;
        if (ch == 'l' || ch == 'L') c++;
        if (ch == 't' || ch == 'T') d++;
    }
    while (a > 0 || b > 0 || c > 0 || d > 0) {
        if (a-- > 0) printf("G");
        if (b-- > 0) printf("P");
        if (c-- > 0) printf("L");
        if (d-- > 0) printf("T");
    }
    return 0;
}