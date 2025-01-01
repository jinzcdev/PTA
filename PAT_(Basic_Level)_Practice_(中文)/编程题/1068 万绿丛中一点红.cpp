// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805265579229184
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int X[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
int Y[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
int m, n, tol, a[maxn][maxn];
bool exceedTOL(int x, int y, int data) {
    if (x == 0 || y == 0 || x == n + 1 || y == m + 1) return true;
    if (abs(a[x][y] - data) > tol) return true;
    else return false;
}

int main() {
    memset(a, 0, maxn * maxn);
    cin >> m >> n >> tol;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            mp[a[i][j]]++;
        }
    }
    int x, y, cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            bool flag = true;
            for (int k = 0; k < 8; k++) {
                int x = i + X[k], y = j + Y[k];
                if (!exceedTOL(x, y, a[i][j])) {
                    flag = false;
                    break;
                }
            }
            if (mp[a[i][j]] == 1 && flag == true) {
                cnt++;
                x = i;
                y = j;
            }
        }
    }

    if (cnt == 1) printf("(%d, %d): %d", y, x, a[x][y]);
    else if (cnt == 0) printf("Not Exist");
    else printf("Not Unique");
    return 0;
}