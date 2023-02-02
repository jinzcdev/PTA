// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805266514558976
#include <iostream>
using namespace std;
const int maxn = 510;
int main() {
    int m, n, a, b, v, temp;
    scanf("%d%d%d%d%d", &m, &n, &a, &b, &v);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j != 0) printf(" ");
            scanf("%d", &temp);
            printf("%03d", temp >= a && temp <= b ? v : temp);
        }
        printf("\n");
    }
    return 0;
}