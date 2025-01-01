// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805383929905152
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct student {
    string name, id;
    int grade;
} s;

bool cmp(student a, student b) {
    return a.grade > b.grade;
}

int main() {
    int n, gradle1, gradle2;
    vector<student> v;
    cin >> n;
    while (n--) {
        cin >> s.name >> s.id >> s.grade;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    cin >> gradle1 >> gradle2;
    if (gradle1 > gradle2) {
        swap(gradle1, gradle2);
    }
    bool flag = false;
    for (auto it : v) {
        if (it.grade >= gradle1 && it.grade <= gradle2) {
            cout << it.name << " " << it.id << endl;
            flag = true;
        }
    }
    if (!flag) cout << "NONE";
    return 0;
}