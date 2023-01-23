// https://pintia.cn/problem-sets/994805342720868352/problems/994805344222429184
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct node {
    string name;
    int cnt, sum;
    double scoreB, scoreA, scoreT;
} sch[N];
bool cmp(node &a, node &b) {
    if (a.sum != b.sum) return a.sum > b.sum;
    return a.cnt != b.cnt ? a.cnt < b.cnt : a.name < b.name;
}
int main() {
    int n, score, len = 0, rank = 1;
    scanf("%d", &n);
    string id, name;
    unordered_map<string, int> hash;
    for (int i = 0; i < n; i++) {
        cin >> id >> score >> name;
        for (int j = 0; j < name.length(); j++) name[j] = tolower(name[j]);
        int sid = hash[name];
        if (sid == 0) sid = hash[name] = ++len;
        sch[sid].name = name;
        sch[sid].cnt++;
        if (id[0] == 'B') sch[sid].scoreB += score;
        else if (id[0] == 'A') sch[sid].scoreA += score;
        else sch[sid].scoreT += score;
    }
    printf("%d\n", len);
    for (int i = 1; i <= len; i++)
        sch[i].sum = (int)(sch[i].scoreT * 1.5 + sch[i].scoreA + sch[i].scoreB / 1.5);
    sort(sch + 1, sch + len + 1, cmp);
    for (int i = 1; i <= len; i++) {
        if (i == 1 || sch[i].sum != sch[i - 1].sum) rank = i;
        printf("%d %s %d %d\n", rank, sch[i].name.c_str(), sch[i].sum, sch[i].cnt);
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
struct node {
    string name;
    int a, b, t, sum, nums;
} school[100010];
bool cmp(node &a, node &b) {
    if (a.sum != b.sum) return a.sum > b.sum;
    return a.nums != b.nums ? a.nums < b.nums : a.name < b.name;
}
int main() {
    int n, score, pos = 1;
    string id, sch;
    unordered_map<string, int> schToId;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> id >> score >> sch;
        for (int j = 0; j < sch.size(); j++) sch[j] = tolower(sch[j]);
        int schid = schToId[sch];
        if (schid == 0) schid = schToId[sch] = pos++;
        school[schid].name = sch;
        school[schid].nums++;
        if (id[0] == 'T') school[schid].t += score;
        else if (id[0] == 'A') school[schid].a += score;
        else school[schid].b += score;
    }
    for (int i = 1; i < pos; i++)
        school[i].sum = school[i].t * 1.5 + school[i].a + school[i].b / 1.5;
    sort(school + 1, school + pos, cmp);
    printf("%d\n", pos - 1);
    int rank = 1;
    for (int i = 1; i < pos; i++) {
        if (i != 1 && school[i].sum != school[i - 1].sum) rank = i;
        printf("%d %s %d %d\n", rank, school[i].name.c_str(), school[i].sum, school[i].nums);
    }
    return 0;
}
*/