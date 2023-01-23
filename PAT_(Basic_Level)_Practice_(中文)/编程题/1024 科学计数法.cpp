// https://pintia.cn/problem-sets/994805260223102976/problems/994805297229447168
/*
#include <cmath>
#include <cstdio>
#include <cstring>
int main() {
    char str[10010];
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    str[--len] = '\0';
    if (str[0] == '-') printf("-");
    int pos = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != 'E') pos++;
        else break;
    }
    int e = 0;
    for (int i = len - 1, j = 0; i > pos + 1; i--)
        e += pow(10, j++) * (str[i] - '0');
    char ch = str[pos + 1];
    int n = pos - 3;  // 小数点后数的个数
    if (ch == '+') {
        if (n <= e) {
            for (int i = 1; i < pos; i++) {
                if (i == 2) continue;
                else printf("%c", str[i]);
            }
            for (int i = 0; i < e - n; i++) printf("0");
        } else {
            printf("%c", str[1]);
            for (int i = 3; i <= e + 2; i++) printf("%c", str[i]);
            printf(".");
            for (int i = e + 3; i < pos; i++) printf("%c", str[i]);
        }
    } else {
        for (int i = 0; i < e; i++) {
            if (i == 1) printf(".");
            printf("0");
        }
        for (int i = 1; i < pos; i++) {
            if (i == 2) continue;
            else printf("%c", str[i]);
        }
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    if (s[0] == '-') printf("-");
    s.erase(0, 1);
    int len = s.find('E'), e = stoi(s.substr(len + 2));
    if (s[len + 1] == '-') {
        printf("0.");
        for (int i = 0; i < e - 1; i++) printf("0");
        for (int i = 0; i < len; i++)
            if (s[i] != '.') printf("%c", s[i]);
    } else if (len - 2 > e) {
        cout << s[0] << s.substr(2, e) << "." << s.substr(e + 2, len - e - 2);
    } else {
        cout << s[0] << s.substr(2, len - 2);
        for (int i = 0; i < e - len + 2; i++) printf("0");
    }
    return 0;
}