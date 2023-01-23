// https://pintia.cn/problem-sets/15/problems/723
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    map<string, string> account;
    cin >> n;
    string op, id, pwd;
    for (int i = 0; i < n; i++) {
        cin >> op >> id >> pwd;
        if (op == "L") {
            if (account[id] == "") printf("ERROR: Not Exist\n");
            else if (account[id] != pwd) printf("ERROR: Wrong PW\n");
            else printf("Login: OK\n");
        } else {
            if (account[id] != "") printf("ERROR: Exist\n");
            else {
                printf("New: OK\n");
                account[id] = pwd;
            }
        }
    }
    return 0;   
}