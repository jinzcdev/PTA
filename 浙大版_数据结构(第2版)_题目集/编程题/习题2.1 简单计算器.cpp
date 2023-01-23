// https://pintia.cn/problem-sets/434/problems/5405
#include <bits/stdc++.h>
using namespace std;
bool isvalid(char ch) {
    string s = "+-*/";
    return isdigit(ch) || s.find(ch) != string::npos;
}
int main() {
    string s, it = "";
    cin >> s;
    char pre = '*';
    int sum = 1;
    for (int i = 0; i < s.length() - 1; i++) {
        if (!isvalid(s[i])) {
            printf("ERROR\n");
            return 0;
        }
        if (isdigit(s[i])) it += s[i];
        if (!isdigit(s[i]) || (i == s.length() - 1 - 1)) {
            int tmp = stoi(it);
            it = "";
            if (pre == '/' && tmp == 0) {
                printf("ERROR\n");
                return 0;
            }
            switch (pre) {
                case '+': sum += tmp; break;
                case '-': sum -= tmp; break;
                case '*': sum *= tmp; break;
                case '/': sum /= tmp; break;
            }
            pre = s[i];
        }
    }
    printf("%d", sum);
    return 0;
}