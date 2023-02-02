// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805393241260032
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10010;
struct node {
    int id, score[6], sum, cntPass;
    bool flag;      // 记录是否有通过编译的提交
    node() { memset(score, -1, sizeof(score)); }
} stu[maxn];
bool cmp(node a, node b) {
    if (a.sum != b.sum) return a.sum > b.sum;
    else if (a.cntPass != b.cntPass) return a.cntPass > b.cntPass;
    else return a.id < b.id;
}
int main() {
    int n, k, m, p[6], id, pid, score;
    cin >> n >> k >> m;
    for (int i = 1; i <= k; i++) cin >> p[i];
    for (int i = 0; i < m; i++) {
        cin >> id >> pid >> score;
        node &s = stu[id];
        if (score == -1 && s.score[pid] == -1) s.score[pid] = 0;
        if (score > s.score[pid]) {
            s.score[pid] = score;
            s.flag = true;
            if (score == p[pid]) s.cntPass++;
        }
    }
    vector<node> ans;
    for (int i = 0; i < maxn; i++) {
        if (stu[i].flag == true) {
            int sum = 0;
            for (int j = 1; j <= k; j++) {
                if (stu[i].score[j] != -1) sum += stu[i].score[j];
            }
            stu[i].sum = sum;
            stu[i].id = i;
            ans.push_back(stu[i]);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    int r = 1;
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0 && ans[i].sum != ans[i - 1].sum) r = i + 1;
        printf("%d %05d %d", r, ans[i].id, ans[i].sum);
        for (int j = 1; j <= k; j++ ) {
            int score = ans[i].score[j];
            if (score == -1) printf(" -");
            else printf(" %d", score);
        }
        printf("\n");
    }
    return 0;
}