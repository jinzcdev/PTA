// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805281567916032
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1010;
struct student {
    char id[20];
    int pt, pe; // position test, exam
} stu;
int main() {
    vector<student> v(maxn);
    int n, m, pt;
    scanf("%d", &n);
    while (n--) {
        scanf("%s%d%d", stu.id, &stu.pt, &stu.pe);
        v[stu.pt] = stu;
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &pt);
        printf("%s %d\n", v[pt].id, v[pt].pe);
    }
    return 0;
}
