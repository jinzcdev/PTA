// https://pintia.cn/problem-sets/994805046380707840/problems/994805052626026496
#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, y, z;
};
int e[65][1300][130];
int X[] = {0, 0, 0, 0, -1, 1};
int Y[] = {0, 0, -1, 1, 0, 0};
int Z[] = {-1, 1, 0, 0, 0, 0};
int m, n, l, t;
bool inq[65][1300][130] = {false};
bool judge(int x, int y, int z) {
    return !(x < 1 || x > m || y < 1 || y > n || z < 1 || z > l) &&
           e[z][x][y] != 0 && !inq[z][x][y];
}
int bfs(node a) {
    queue<node> q;
    q.push(a);
    int cnt = 0;
    inq[a.z][a.x][a.y] = true;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        int x = now.x, y = now.y, z = now.z;
        cnt += e[z][x][y];
        for (int i = 0; i < 6; i++) {
            x = now.x + X[i];
            y = now.y + Y[i];
            z = now.z + Z[i];
            if (judge(x, y, z)) {
                inq[z][x][y] = true;
                q.push({x, y, z});
            }
        }
    }
    return cnt >= t ? cnt : 0;
}
int main() {
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for (int z = 1; z <= l; z++)
        for (int x = 1; x <= m; x++)
            for (int y = 1; y <= n; y++) scanf("%d", &e[z][x][y]);
    int ans = 0;
    for (int z = 1; z <= l; z++)
        for (int x = 1; x <= m; x++)
            for (int y = 1; y <= n; y++)
                if (judge(x, y, z)) ans += bfs({x, y, z});
    printf("%d", ans);
    return 0;
}