// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1111914599412858880
#include <bits/stdc++.h>
using namespace std;
bool isOng(string s) {
    string a = s.substr(0, s.find(',') + 1);
    return s.rfind("ong,") != string::npos && s.rfind("ong.") != string::npos;
}
int main() {
    int n;
    scanf("%d", &n);
    getchar();
    string s;
    while (n--) {
        getline(cin, s);
        if (!isOng(s)) printf("Skipped\n");
        else {
            int i, cnt = 0;
            for (i = s.length() - 1; i >= 0; i--) {
                if (s[i] == ' ' && ++cnt == 3) break; 
            }
            cout << s.substr(0, i + 1) << "qiao ben zhong." << endl;
        }
    }
    return 0;
}