// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1038429484026175488
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
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
        int cnt, flag = 0, a[100000] = {0};
        scanf("%d", &cnt);
        vector<int> v(cnt);
        for (int i = 0; i < cnt; i++) {
            scanf("%d", &v[i]);
            a[v[i]] = 1;
        }
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < mp[v[i]].size(); j++)
                if (a[mp[v[i]][j]] == 1) flag = 1;
        printf("%s\n",flag ? "No" :"Yes");
    }    
    return 0;
}