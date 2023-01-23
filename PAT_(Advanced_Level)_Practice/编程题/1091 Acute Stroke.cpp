// https://pintia.cn/problem-sets/994805342720868352/problems/994805375457411072
#include <cstdio>
#include <queue>
using namespace std;
struct node {
    int x, y, z;
} Node;
int n, m, slice, T;
int pixel[1290][130][61];
bool inq[1290][130][61] = {false};
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

bool judge(int x, int y, int z){
    if (x >= n || x < 0 || y >= m || y < 0 || z >= slice || z < 0) return false;
    if (pixel[x][y][z] == 0 || inq[x][y][z]) return false;
    return true;
}

int BFS(int x, int y, int z) {
    int tot = 0;
    queue<node> q;
    Node = {x, y, z};
    q.push(Node);
    inq[x][y][z] = true;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        tot++;
        for (int i = 0; i < 6; i++) {
            int newX = now.x + X[i];
            int newY = now.y + Y[i];
            int newZ = now.z + Z[i];
            if (judge(newX, newY, newZ)) {
                Node = {newX, newY, newZ};
                q.push(Node);
                inq[newX][newY][newZ] = true;
            }
        }
    }
    if (tot >= T) return tot;
    else return 0;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &slice, &T);
    for (int z = 0; z < slice; z++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                scanf("%d", &pixel[x][y][z]);
            }
        }
    }
    int ans = 0;
    for (int z = 0; z < slice; z++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (pixel[x][y][z] == 1 && !inq[x][y][z]) {
                    ans += BFS(x, y, z);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}