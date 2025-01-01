// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805344222429184
#include <bits/stdc++.h>
using namespace std;
struct node {
    string school;
    int cntMember = 0;
    double score = 0.0;
} s[100010];
bool cmp(node a, node b) {
    if ((int)a.score != (int)b.score)
        return (int)a.score > (int)b.score;
    else if (a.cntMember != b.cntMember)
        return a.cntMember < b.cntMember;
    return a.school < b.school;
}
void tolower(string &s) {
    for (int i = 0; i < s.length(); i++)
        if (isupper(s[i])) s[i] = s[i] + ('a' - 'A');
}
int main() {
    int n, score, idx = 1;
    string id, school;
    map<string, int> vis;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id >> score >> school;
        tolower(school);
        int sid = vis[school];
        if (sid == 0) {
            vis[school] = idx++;
            sid = vis[school];
            s[sid].school = school;
        }
        s[sid].cntMember++;
        if (id[0] == 'A')
            s[sid].score += score;
        else if (id[0] == 'B')
            s[sid].score += score / 1.5;
        else
            s[sid].score += score * 1.5;
    }
    sort(s + 1, s + idx, cmp);
    cout << idx - 1 << endl;
    int tscore = (int)s[1].score, r = 1;
    for (int i = 1; i < idx; i++) {
        if ((int)s[i].score != tscore) {
            r = i;
            tscore = s[i].score;
        }
        printf("%d %s %d %d\n", r, s[i].school.c_str(), (int)s[i].score,
               s[i].cntMember);
    }
    return 0;
}