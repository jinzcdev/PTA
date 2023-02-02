// https://pintia.cn/problem-sets/994805046380707840/exam/problems/1518581694528933888
#include <bits/stdc++.h>
using namespace std;
bool vis[10][10] = {false};
void solve(int i) {
    for (int j = 5; j >= 0; j--) {
        if (!vis[i][j]) {
            vis[i][j] = true;
            break;
        }
    }
}
int main() {
    int a, k;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &a);
        vis[i][a - 1] = true;
    }
    scanf("%d", &k);
    while (--k) {
        for (int i = 0; i < 6; i++) {
            solve(i);
        }
    }
    for (int i = 0; i < 6; i++) {
        if (i != 0) printf(" ");
        for (int j = 5; j >= 0; j--) {
            if (!vis[i][j]) {
                printf("%d", j + 1);
                break;
            }
        }
    }
    return 0;
}