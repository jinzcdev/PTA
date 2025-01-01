// https://pintia.cn/problem-sets/14/exam/problems/type/7?problemSetProblemId=801
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int sqr = (int)sqrt(n * 1.0), flag = 0, vis[10010] = {0};
    for (int x = 1; x <= sqr; x++) {
        if (vis[x]) break;
        int yy = n - x * x, y = (int)sqrt(yy * 1.0);
        if (y * y == yy) {
            printf("%d %d\n", x, y);
            vis[y] = flag = 1;
        }
    }
    if (!flag) cout << "No Solution";
    return 0;
}