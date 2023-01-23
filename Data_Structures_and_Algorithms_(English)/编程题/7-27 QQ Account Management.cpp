// https://pintia.cn/problem-sets/16/problems/689
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d", &n);
    char op;
    ll qq;
    string pwd;
    unordered_map<ll, string> hash;
    while (n--) {
        cin >> op >> qq >> pwd;
        if (op == 'L') {
            if (hash[qq] == "") printf("ERROR: Account Not Exist\n");
            else if (hash[qq] != pwd) printf("ERROR: Wrong Password\n");
            else printf("Log in Successful\n");
        } else {
            if (hash[qq] != "") printf("ERROR: Account Number Already Exists\n");
            else {
                printf("Register Successful\n");
                hash[qq] = pwd;
            }
        }
    }
    return 0;
}