// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805111694409728
#include <cstdio>
int main() {
    int d;
    scanf("%d", &d);
    printf("%d", d <= 5 ? d + 2 : (d + 2) % 7);
    return 0;
}