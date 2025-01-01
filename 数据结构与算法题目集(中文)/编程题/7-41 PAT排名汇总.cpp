// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=888
#include <bits/stdc++.h>
using namespace std;
struct node {
    string id;
    int siteId, score, rank;
};
bool cmp(node& a, node& b) {
    if (a.score != b.score) return a.score > b.score;
    return a.id < b.id;
}
int main() {
    int n, m, cnt = 0, score;
    string id;
    scanf("%d", &n);
    vector<node> stu;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        cnt += m;
        vector<node> v;
        for (int j = 0; j < m; j++) {
            cin >> id >> score;
            v.push_back({id, i, score});
        }
        sort(v.begin(), v.end(), cmp);
        v[0].rank = 1;
        for (int i = 1; i < v.size(); i++) {
            if (v[i].score != v[i - 1].score) v[i].rank = i + 1;
            else v[i].rank = v[i - 1].rank;
        }
        stu.insert(stu.end(), v.begin(), v.end());
    }
    printf("%d\n", cnt);
    int rank = 1, pre = stu[0].score;
    sort(stu.begin(), stu.end(), cmp);
    for (int i = 0; i < stu.size(); i++) {
        if (stu[i].score != pre) rank = i + 1;
        pre = stu[i].score;
        printf("%s %d %d %d\n", stu[i].id.c_str(), rank, stu[i].siteId, stu[i].rank);
    }
    return 0;
}