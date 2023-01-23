// https://pintia.cn/problem-sets/15/problems/864
#include <bits/stdc++.h>
using namespace std;
struct node {
    int id, score;
    string name;
};
int n, c;
bool cmp(node a, node b) {
    if (c == 1) return a.id < b.id;
    else if (c == 2) return a.name != b.name ? a.name < b.name : a.id < b.id;
    else return a.score != b.score ? a.score < b.score : a.id < b.id;
}
int main() {
    scanf("%d%d", &n, &c);
    vector<node> stu(n);
    for (int i = 0; i < n; i++) cin >> stu[i].id >> stu[i].name >> stu[i].score;
    sort(stu.begin(), stu.end(), cmp);
    for (auto it : stu) printf("%06d %s %d\n", it.id, it.name.c_str(), it.score);
    return 0;
}