// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805468327690240
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 100010;

struct Student {
    int id;
    char name[10];
    int score;
} stu[maxn];

int n, c;

bool sortById(Student a, Student b) {
    if (c == 1)
        return a.id < b.id;
    else if (c == 2) {
        int rs = strcmp(a.name, b.name);
        if (rs == 0) return a.id < b.id;
        else
            return rs < 0;
    } else {
        if (a.score == b.score) return a.id < b.id;
        else
            return a.score < b.score;
    }
}


int main() {
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i) {
        scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].score);
    }
    sort(stu, stu + n, sortById);

    for (int i = 0; i < n; ++i) {
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
    }
    return 0;
}