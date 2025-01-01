// https://pintia.cn/problem-sets/12/exam/problems/type/7?problemSetProblemId=274
#include <stdio.h>
int main() {
    int x;
    scanf("%d", &x);
    if (x >= 90) {
        printf("A");
    } else if (x >= 80) {
        printf("B");
    } else if (x >= 70) {
        printf("C");
    } else if (x >= 60) {
        printf("D");
    } else {
        printf("E");
    }   
    return 0;
}