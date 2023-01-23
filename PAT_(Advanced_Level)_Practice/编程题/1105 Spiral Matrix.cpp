// https://pintia.cn/problem-sets/994805342720868352/problems/994805363117768704
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    int length, width;
    for (width = sqrt(n); width >= 1; width--) {
        if (n % width == 0) {
            length = n / width;
            break;
        }
    }
    vector<vector<int>> m(length, vector<int>(width));
    int border[4] = {width - 1, length - 1, 0, 1};
    int x = 0, y = -1, d = 0;
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i--) {
        if (d == 0 && ++y == border[0]) {
            d = 1;
            border[0]--;
        } else if (d == 1 && ++x == border[1]) {
            d = 2;
            border[1]--;
        } else if (d == 2 && --y == border[2]) {
            d = 3;
            border[2]++;
        } else if (d == 3 && --x == border[3]) {
            d = 0;
            border[3]++;
        }
        m[x][y] = v[i];
    }
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            if (j != 0) printf(" ");
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}