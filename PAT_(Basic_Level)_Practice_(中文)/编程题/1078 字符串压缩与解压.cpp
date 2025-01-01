// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805262018265088
#include <iostream>
#include <cctype>
using namespace std;
void compress(string s) {
    char ch = s[0];
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (ch == s[i]) cnt++;
        else {
            if (cnt > 1) printf("%d", cnt);
            printf("%c", s[i - 1]);
            ch = s[i];
            cnt = 1;
        }
    }
    if (cnt > 1) printf("%d", cnt);
    printf("%c", ch);
}
void decompress(string s) {
    int pos = 0;
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            int cnt;
            if (pos != i) cnt = stoi(s.substr(pos, i));
            else cnt = 1;
            while (cnt--) cout << s[i];
            pos = i + 1;
        }
    }
}
int main() {
    char op;
    string str;
    cin >> op;
    getchar();
    getline(cin, str);
    if (op == 'C') compress(str);
    else decompress(str);
    return 0;
}