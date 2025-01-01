// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805321640296448
#include <bits/stdc++.h>
using namespace std;
struct node {
    string name, id;
    int score;
};
int main() {
    int n, i_min, i_max, MAX = -1, MIN = 9999;
    cin >> n;
    vector<node> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].name >> v[i].id >> v[i].score;
        if (v[i].score > MAX) {
            MAX = v[i].score;
            i_max = i;
        }
        if (v[i].score < MIN) {
            MIN = v[i].score;
            i_min = i;
        }
    }
    printf("%s %s\n%s %s", v[i_max].name.c_str(), v[i_max].id.c_str(),
           v[i_min].name.c_str(), v[i_min].id.c_str());
    return 0;
}