// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805099426070528
#include <cstdio>
int main() {
    int year, n, age = 0;
    scanf("%d%d", &year, &n);
    while (true) {
        int temp = year, cnt = 0;
        bool vis[10] = {false};
        for (int i = 0; i < 4; i++) {
            if (!vis[temp % 10]) {
                cnt++;
                vis[temp % 10] = true;
            }
            temp /= 10;
        }

        if (cnt == n) {
            printf("%d %04d", age, year);
            return 0;
        }
        year++;
        age++;
    }
    return 0;
}