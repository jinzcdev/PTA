// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805264312549376
#include <iostream>
using namespace std;
int main() {
    int T, k, b, t, n1, n2;
    scanf("%d%d", &T, &k);
    while (k--) {
        scanf("%d%d%d%d", &n1, &b, &t, &n2);
        if (T < t) {
            printf("Not enough tokens.  Total = %d.\n", T);
            continue;
        }
        if ((n1 > n2 && b == 0) || (n1 < n2 && b == 1)) {
            T += t;
            printf("Win %d!  Total = %d.\n", t, T);
        } else {
            T -= t;
            printf("Lose %d.  Total = %d.\n", t, T);
            if (T <= 0) {
                printf("Game Over.\n");
                break;
            }
        }
    }
    return 0;
}