// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805421066272768
#include <bits/stdc++.h>
using namespace std;
struct node {
    char name[10];
    int age, worth;
};
bool cmp(node a, node b) {
    if (a.worth != b.worth) return a.worth > b.worth;
    else if (a.age != b.age) return a.age < b.age;
    else return strcmp(a.name, b.name) < 0;
}
int main() {
    int n, k, m, minage, maxage;
    scanf("%d%d", &n, &k);
    vector<node> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", v[i].name, &v[i].age, &v[i].worth);
    }
    sort(v.begin(), v.end(), cmp);
    // map<int, vector<node> > mp;
    // for (auto it : v) {
    //     mp[it.age].push_back(it);
    // }
    for (int i = 1; i <= k; i++) {
        printf("Case #%d:\n", i);
        scanf("%d%d%d", &m, &minage, &maxage);
        int cnt = 0, flag = 0;
        for (auto it : v) {
            if (it.age >= minage && it.age <= maxage) {
                printf("%s %d %d\n", it.name, it.age, it.worth);
                flag = 1;
                if (++cnt == m) break;
            }
        }
        if (!flag) printf("None\n");
    }
    return 0;
}
