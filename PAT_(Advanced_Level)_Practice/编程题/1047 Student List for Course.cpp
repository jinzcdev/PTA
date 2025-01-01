// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805433955368960
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 2510;
const int STUN = 40010;
vector<int> course[maxn];
char name[STUN][5];
bool cmp(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}
int main() {
    int n, k, c, courseID;
    string stu;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s%d", name[i], &c);
        while (c--) {
            scanf("%d", &courseID);
            course[courseID].push_back(i);
        }
    }
    for (int i = 1; i <= k; i++) {
        sort(course[i].begin(), course[i].end(), cmp);
        printf("%d %d\n", i, course[i].size());
        for (auto it : course[i]) {
            printf("%s\n", name[it]);
        }
    }
    return 0;
}