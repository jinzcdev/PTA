// https://pintia.cn/problem-sets/994805342720868352/problems/1038430013544464384
#include <bits/stdc++.h>
using namespace std;
const int N = 210, INF = 0x3f3f3f3f;
int main() {
    int e[N][N], n, m, k, a, b, dist;
    scanf("%d%d", &n, &m);
    fill(e[0], e[0] + N * N, INF);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &dist);
        e[a][b] = e[b][a] = dist;
    }
    scanf("%d", &m);
    int ans, mindist = INF;
    for (int i = 1; i <= m; i++) {
        printf("Path %d: ", i);
        scanf("%d", &k);
        vector<int> v(k);
        for (int j = 0; j < k; j++) scanf("%d", &v[j]);
        unordered_set<int> s;
        int totalDist = 0, iscycle = 1;
        for (int j = 0; j < k - 1; j++) {
            if (e[v[j]][v[j + 1]] == INF) {
                iscycle = 0;
                break;
            }
            s.insert(v[j]);
            totalDist += e[v[j]][v[j + 1]];
        }
        if (!iscycle) printf("NA (Not a TS cycle)\n");
        else {
            printf("%d ", totalDist);
            if (v[0] != v[k - 1] || s.size() < n) printf("(Not a TS cycle)\n");
            else {
                printf("(%s)\n", k - 1 == n ? "TS simple cycle" : "TS cycle");
                if (totalDist < mindist) {
                    mindist = totalDist;
                    ans = i;
                }
            }
        }
    }
    printf("Shortest Dist(%d) = %d", ans, mindist);
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int main() {
    int n, m, k, a, b, temp, e[N][N] = {0}, ans = 0, MIN = 0x7fffffff;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &a, &b, &temp);
        e[a][b] = e[b][a] = temp;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        printf("Path %d: ", i);
        scanf("%d", &k);
        vector<int> v(k);
        int isvalid = 1, dist = 0;
        unordered_set<int> s;
        for (int i = 0; i < k; i++) {
            scanf("%d", &v[i]);
            s.insert(v[i]);
        }
        for (int i = 0; i < k - 1; i++) {
            dist += e[v[i]][v[i + 1]];
            if (e[v[i]][v[i + 1]] == 0) {
                isvalid = false;
                break;
            }
        }
        if (!isvalid) printf("NA (Not a TS cycle)\n");
        else if (v[0] != v[k - 1] || s.size() != n) printf("%d (Not a TS cycle)\n", dist);
        else {
            if (k != n + 1) printf("%d (TS cycle)\n", dist);
            else printf("%d (TS simple cycle)\n", dist);
            if (dist < MIN) {
                ans = i;
                MIN = dist;
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n", ans, MIN);
    return 0;
}
*/