// https://pintia.cn/problem-sets/994805260223102976/problems/994805266007048192
#include <bits/stdc++.h>
using namespace std;
int main() {
    string pwd, s;
    int n, cntErr = 0, cnt = 0;
    cin >> pwd >> n;
    getchar();
    while (getline(cin, s)) {
        if (s == "#" || ++cnt > n) break;
        if (s == pwd) {
            printf("Welcome in\n");
            break;
        }
        printf("Wrong password: %s\n", s.c_str());
        if (++cntErr == n) {
            printf("Account locked\n");
            break;
        }
    }
    return 0;
}