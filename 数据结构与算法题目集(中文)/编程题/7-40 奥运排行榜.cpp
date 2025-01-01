// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=867
#include <bits/stdc++.h>
using namespace std;
const int N = 230;
struct node {
    float medal[5], rank[5];
    int id;
};
int type = 1;
bool cmp(node &a, node &b) { return a.medal[type] > b.medal[type]; }
int main() {
    int n, m, k, num = 0;
    scanf("%d%d", &n, &m);
    vector<node> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%f%f%d", &v[i].medal[1], &v[i].medal[2], &num);
        v[i].medal[3] = v[i].medal[1] * 1.0 / num;
        v[i].medal[4] = v[i].medal[2] * 1.0 / num;
        v[i].id = i;
    }
    for (int i = 1; i <= 4; i++) {
        type = i;
        sort(v.begin(), v.end(), cmp);
        int rank = 1;
        for (int j = 0; j < n; j++) {
            if (j != 0 && v[j].medal[i] != v[j - 1].medal[i]) rank = j + 1;
            v[j].rank[i] = rank;
        }
    }
    sort(v.begin(), v.end(), [](node &a, node &b) { return a.id < b.id; });
    for (int i = 0; i < m; i++) {
        if (i != 0) printf(" ");
        scanf("%d", &k);
        int ans = 0, rank = 999;
        for (int j = 1; j <= 4; j++) {
            if (v[k].rank[j] < rank) {
                rank = v[k].rank[j];
                ans = j;
            }
        }
        printf("%d:%d", rank, ans);
    }
    return 0;
}