// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805145370476544
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 1, a;
    char ch;
    cin >> a >> ch;
    while (n * n * 2 - 1 <= a) n++;
    n--;
    a -= (n * n * 2 - 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i - 1; j++) cout << " ";
        for (int j = 0; j < 1 + 2 * (n - i); j++) cout << ch;
        cout << endl;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < n - i; j++) cout << " ";
        for (int j = 0; j < 1 + 2 * (i - 1); j++) cout << ch;
        cout << endl;
    }
    cout << a;
    return 0;
}