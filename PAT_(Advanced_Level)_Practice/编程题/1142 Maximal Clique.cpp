// https://pintia.cn/problem-sets/994805342720868352/problems/994805343979159552
#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int n, m, k, a, b, e[N][N] = {0};
bool isClique(vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++)
        for (int j = i + 1; j < v.size(); j++)
            if (!e[v[i]][v[j]]) return false;
    return true;
}
bool isMaximal(vector<int> &v, bool *has) {
    for (int i = 1; i <= n; i++) {
        if (has[i]) continue;
        bool flag = true;
        for (int j = 0; j < v.size(); j++) {
            if (!e[i][v[j]]) {
                flag = false;
                break;
            }
        }
        if (flag) return false;
    }
    return true;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        e[a][b] = e[b][a] = 1;
    }
    scanf("%d", &m);
    while (m--) {
        bool has[N] = {false};
        scanf("%d", &k);
        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &v[i]);
            has[v[i]] = true;
        }
        if (!isClique(v)) {
            printf("Not a Clique\n");
            continue;
        }
        printf("%s\n", isMaximal(v, has) ? "Yes" : "Not Maximal");
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 210;
vector<int> e[N];
bool isclip(vector<int> &v, vector<bool> &exist) {
    for (int i = 0; i < v.size(); i++) {
        int cnt = 0;
        for (auto it : e[v[i]]) {
            if (exist[it]) cnt++;
        }
        if (cnt != v.size() - 1) return false;
    }
    return true;
}
int main() {
    int n, m, k, a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &k);
        vector<int> v(k);
        vector<bool> exist(N);
        for (int i = 0; i < k; i++) {
            scanf("%d", &v[i]);
            exist[v[i]] = true;
        }
        if (!isclip(v, exist)) printf("Not a Clique\n");
        else {
            bool ismaximal = true;
            for (int i = 1; i <= n; i++) {
                if (exist[i]) continue;
                int cnt = 0;
                for (auto it : e[i]) {
                    if (exist[it]) cnt++;
                }
                if (cnt == k) ismaximal = false;
            }
            printf("%s\n", ismaximal ? "Yes" : "Not Maximal");
        }
    }
    return 0;
}
*/