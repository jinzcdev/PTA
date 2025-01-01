// https://pintia.cn/problem-sets/91827364500/exam/problems/type/7?problemSetProblemId=91827364577
#include <bits/stdc++.h>
using namespace std;
bool ispali(string s) {
    for (int i = 0; i < s.length() / 2; i++)
        if (s[i] != s[s.length() - i - 1]) return false;
    return true;
}
string convert(int n, int d) {
    string s;
    while (n != 0) {
        s += (n % d + '0');
        n /= d;
    }
    return s;
}
int main() {
    int n;
    while (scanf("%d", &n), n != 0) {
        vector<int> ans;
        for (int i = 2; i <= 16; i++) {
            if (ispali(convert(n, i))) ans.push_back(i);
        }
        if ((int)ans.size() == 0) printf("Number %d is not a palindrom", n);
        else {
            printf("Number %d is palindrom in basis", n);
            for (int i = 0; i < ans.size(); i++) printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}