// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805395707510784
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    if (s[0] == '-') printf("-");
    s.erase(s.begin());
    int pos = s.find('E'), e = stoi(s.substr(pos + 2));
    if (s[pos + 1] == '+') {
        cout << s[0];
        if (e >= pos - 2) {
            cout << s.substr(2, pos - 2);
            for (int i = 0; i < e - pos + 2; i++) cout << "0";
        } else {
            cout << s.substr(2, e) << ".";
            cout << s.substr(e + 2, pos - e - 2);
        }
    } else {
        cout << "0.";
        for (int i = 0; i < e - 1; i++) cout << "0";
        cout << s[0] << s.substr(2, pos - 2);
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    char op;
    scanf("%c", &op);
    if (op == '-') printf("-");
    cin >> s;
    int pose = s.find('E');
    string number = s.substr(0, pose);
    int len = stoi(s.substr(pose + 2));
    if (s[pose + 1] == '-') {
        printf("0.");
        for (int i = 0; i < len - 1; i++) printf("0");
        printf("%c%s", number[0], number.substr(2).c_str());
    } else {
        if (number.length() - 2 > len) {
            cout << number[0];
            cout << number.substr(2, len) << "." << number.substr(2 + len);
        } else {
            number.erase(1, 1);
            cout << number;
            for (int i = 0; i < len - (number.length() - 1); i++) printf("0");
        }
    }
    return 0;
}
*/