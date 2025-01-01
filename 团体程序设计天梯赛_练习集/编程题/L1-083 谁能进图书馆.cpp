// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1518581226784346112
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, q1, q2;
    scanf("%d%d%d%d", &a, &b, &q1, &q2);
    if (q1 >= a && q2 >= a) {
        printf("%d-Y %d-Y\nhuan ying ru guan", q1, q2);
    } else if (q1 >= b || q2 >= b) {
        printf("%d-Y %d-Y\n", q1, q2);
        if (q1 >= b) printf("qing %d zhao gu hao %d", 1, 2);
        else printf("qing %d zhao gu hao %d", 2, 1);
    } else if (q1 < a && q2 < a) {
        printf("%d-N %d-N\nzhang da zai lai ba", q1, q2);
    } else {
        if (q1 >= a) printf("%d-Y %d-N\n", q1, q2);
        else printf("%d-N %d-Y\n", q1, q2);
        printf("%d: huan ying ru guan", q1 >= a ? 1 : 2);
    }
    return 0;
}