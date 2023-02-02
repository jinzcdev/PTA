// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805076512587776
#include <bits/stdc++.h>
using namespace std;
int main() {
    char ch;
    int n;
    scanf("%c %d", &ch, &n);
    getchar();
    vector<string> a(n), b(n);
    for (int i = 0; i < n; i++) {
        getline(cin, a[i]);
        int x = n - i - 1;
        b[x].resize(n);
        for (int j = 0; j < n; j++) {
            b[x][j] = a[i][j];
            if (a[i][j] != ' ') b[x][j] = ch;
        }
        reverse(b[x].begin(), b[x].end());
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (a[i][j] != ' ') a[i][j] = ch;
        if (a[i] != b[i]) {
            flag = false;
            break;
        }
    }
    if (flag) cout << "bu yong dao le" << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i] << endl;
    }
    return 0;
}