// https://pintia.cn/problem-sets/14/exam/problems/type/7?problemSetProblemId=796
#include <bits/stdc++.h>
using namespace std;
int main() {
    bool vis[20] = {false};
    int n, cnt = 0;
    cin >> n;
    for (int x = n; x <= n + 3; x++) {
        vis[x] = true;
        for (int y = n; y <= n + 3; y++) {
            if (vis[y]) continue;
            vis[y] = true;
            for (int z = n; z <= n + 3; z++) {
                if (vis[z]) continue;
                vis[z] = true;
                printf("%d", x * 100 + y * 10 + z);
                if (++cnt % 6 == 0) printf("\n");
                else printf(" ");
                vis[z] = false; 
            }
            vis[y] = false;
        }
        vis[x] = false;
    }
}