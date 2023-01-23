// https://pintia.cn/problem-sets/994805342720868352/problems/994805387268571136
#include <bits/stdc++.h>
using namespace std;
struct node {
    int id, ge, gi, final;
    int choice[5];
};
bool cmp(node a, node b) {
    if (a.final != b.final)
        return a.final > b.final;
    else
        return a.ge > b.ge;
}
int main() {
    int n, k, m, quota[110] = {0}, temp;
    scanf("%d%d%d", &n, &k, &m);
    vector<node> stu(n);
    vector<int> school[110];
    for (int i = 0; i < k; i++) scanf("%d", &quota[i]);
    for (int i = 0; i < n; i++) {
        stu[i].id = i;
        scanf("%d%d", &stu[i].ge, &stu[i].gi);
        for (int j = 0; j < m; j++) {
            scanf("%d", &stu[i].choice[j]);
        }
        stu[i].final = stu[i].ge + stu[i].gi;
    }
    sort(stu.begin(), stu.end(), cmp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int stuId = stu[i].id, schId = stu[i].choice[j];
            int lastStuId = school[schId].size() - 1;
            if (school[schId].size() < quota[schId] ||
                (stu[school[schId][lastStuId]].final == stu[stuId].final &&
                 stu[school[schId][lastStuId]].ge == stu[stuId].ge)) {
                school[schId].push_back(stu[i].id);
                break;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        sort(school[i].begin(), school[i].end());
        for (int j = 0; j < school[i].size(); j++) {
            if (j != 0) printf(" ");
            printf("%d", school[i][j]);
        }
        printf("\n");
    }
    return 0;
}