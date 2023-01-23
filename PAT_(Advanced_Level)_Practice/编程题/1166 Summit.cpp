// https://pintia.cn/problem-sets/1203317538312806400/problems/1203317626619691010
#include <bits/stdc++.h>
using namespace std;
const int N = 210;
bool isfriend[N][N] = {false};
int main() {
    int n, m, k, l, a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        isfriend[a][b] = isfriend[b][a] = true;
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        printf("Area %d ", i);
        scanf("%d", &l);
        vector<int> v(l);
        for (int j = 0; j < l; j++) {
            scanf("%d", &v[j]);
        }
        bool flag = true;
        for (int x = 0; x < v.size(); x++) {
            for (int y = 0; y < v.size(); y++) {
                if (x == y) continue;
                if (!isfriend[v[x]][v[y]]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (!flag) printf("needs help.\n");
        else {
            int other = -1;
            for (int x = 1; x <= n; x++) {
                int cnt = 0;
                for (int y = 0; y < v.size(); y++) {
                    if (isfriend[x][v[y]]) cnt++;
                }
                if (cnt == v.size()) {
                    other = x;
                    break;
                }
            }
            if (other != -1) printf("may invite more people, such as %d.\n", other);
            else printf("is OK.\n");
        }
    }
    return 0;
}