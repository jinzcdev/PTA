// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805343979159552
#include <bits/stdc++.h>
using namespace std;
int e[201][201];
bool isClique(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (e[v[i]][v[j]] == 0) return false;
        }
    }
    return true;
}
int main() {
    int nv, ne, u, v, m, k;
    scanf("%d%d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        scanf("%d%d", &u, &v);
        e[u][v] = e[v][u] = 1;
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &k);
        vector<int> v(k), vis(nv + 1);
        for (int i = 0; i < k; i++) {
            scanf("%d", &v[i]);
            vis[v[i]] = 1;
        }
        if (!isClique(v)) {
            printf("Not a Clique\n");
            continue;
        }
        bool isMaximal = true;
        for (int i = 1; i <= nv; i++) {
            if (!vis[i]) {
                bool flag = true;
                for (int j = 0; j < k; j++) {
                    if (e[i][v[j]] == 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag == true) isMaximal = false;
            }
        }
        printf("%s\n", isMaximal ? "Yes" : "Not Maximal");
    }
    return 0;
}