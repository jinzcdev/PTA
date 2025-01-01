// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1336215880692482055
#include <iostream>
using namespace std;
int val[] = {10000, 36,  720, 360, 80,  252,  108, 72,   54,  180,
             72,    180, 119, 36,  306, 1080, 144, 1800, 3600};
int main() {
    int a[3][3], x, y, k, ans = 0;
    bool flag[3][3] = {false}, vis[10] = {false};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0) vis[a[i][j]] = true;
            else {
                flag[i][j] = true;
                x = i;
                y = j;
            }
        }
    }
    for (int i = 1; i <= 9; i++) {
        if (!vis[i]) {
            a[x][y] = i;
            break;
        }
    }
    for (int i = 0; i < 3; i++) {
        scanf("%d%d", &x, &y);
        printf("%d\n", a[x - 1][y - 1]);
    }
    scanf("%d", &k);
    if (k <= 3) for (int i = 0; i < 3; i++) ans += a[k - 1][i];
    else if (k <= 6) for (int i = 0; i < 3; i++) ans += a[i][k - 3 - 1];
    else if (k == 7) for (int i = 0; i < 3; i++) ans += a[i][i];
    else for (int i = 0; i < 3; i++) ans += a[3 - i - 1][i];
    printf("%d", val[ans - 6]);
    return 0;
}