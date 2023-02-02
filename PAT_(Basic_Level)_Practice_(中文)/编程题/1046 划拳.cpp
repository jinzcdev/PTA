// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805277847568384
#include <cstdio>
int main(){
    int n, cntA = 0, cntB = 0;
    int p1, p2, num1, num2;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d%d", &p1, &num1, &p2, &num2);
        int ans = p1 + p2;
        if (num1 == ans && num2 != ans) cntB++;
        else if (num1 != ans && num2 == ans) cntA++;
    }
    printf("%d %d", cntA, cntB);
    return 0;
}