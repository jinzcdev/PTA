// https://pintia.cn/problem-sets/17/problems/264
#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int main() {
    int n, order[N];
    cin >> n;
    vector<int> ans(N);
    string s = "SHCDJ";
    for (int i = 1; i <= 54; i++) scanf("%d", order + i);
    for (int i = 1; i <= 54; i++) ans[i] = i;
    while (n--) {
        vector<int> tmp(N);
        for (int i = 1; i <= 54; i++) tmp[order[i]] = ans[i];
        ans.swap(tmp);
    }
    for (int i = 1; i <= 54; i++) {
        if (i != 1) printf(" ");
        printf("%c%d", s[(ans[i] - 1) / 13], ans[i] % 13 == 0 ? 13 : ans[i] % 13);
    }
    return 0;
}