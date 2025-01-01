// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805089657536512
#include <iostream>
using namespace std;
int main() {
    int d, cnt = 0;
    while (scanf("%d", &d) != EOF) {
        cnt++;
        if (d == 250) {
            printf("%d", cnt);
            return 0;
        }
    }
    return 0;
}