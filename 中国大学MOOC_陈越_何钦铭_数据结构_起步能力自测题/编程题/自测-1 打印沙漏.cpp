// https://pintia.cn/problem-sets/17/exam/problems/260
#include <cmath>
#include <cstdio>
int main() {
    int sum;
    char ch;
    scanf("%d %c", &sum, &ch);
    int n = (int)sqrt((sum + 1) / 2);
    int div = sum - (2 * n * n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) printf(" ");
        for (int j = 1 + (n - i - 1) * 2; j > 0; j--) printf("%c", ch);
        printf("\n");
    }
    for (int i = 1; i < n; i++) {
        for (int j = n - i - 1; j > 0; j--) printf(" ");
        for (int j = 1 + i * 2; j > 0; j--) printf("%c", ch);
        printf("\n");
    }
    printf("%d", div);
}