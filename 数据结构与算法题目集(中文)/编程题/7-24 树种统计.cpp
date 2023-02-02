// https://pintia.cn/problem-sets/15/exam/problems/839
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    string s;
    map<string, int> cnt;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        cnt[s]++;
    }
    for (auto it : cnt) {
        printf("%s %.4f%%\n", it.first.c_str(), it.second * 100.0 / n);
    }
    return 0;
}