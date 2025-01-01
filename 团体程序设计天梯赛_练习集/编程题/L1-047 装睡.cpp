// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805083282194432
#include <cstdio>
int main() {
    int n, hx, mb;
    char name[10];
    scanf("%d", &n);
    while (n--) {
        scanf("%s %d%d", name, &hx, &mb);
        if (hx < 15 || hx > 20 || mb < 50 || mb > 70) {
            printf("%s\n", name);
        }
    }
    return 0;
}