// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1038429908921778176
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k, t1, t2;
    map<int, vector<int> > mp;
    scanf("%d%d", &n, &m);
    while (n--) {
        scanf("%d%d", &t1, &t2);
        mp[t1].push_back(t2);
        mp[t2].push_back(t1);
    }
    while (m--) {
        scanf("%d", &k);
        int vis[100000] = {0};
        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &v[i]);
            vis[v[i]] = 1;
        }
        bool flag = true;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < mp[v[i]].size(); j++) {
                if (vis[mp[v[i]][j]] == 1) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        printf("%s\n", flag ? "Yes" : "No");
    }    
    return 0;
}