// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805285812551680
#include <cstdio>
int main() {
    int row, col;
    char c;
    scanf("%d %c", &col, &c);
    if (col % 2 != 0) row = col / 2 + 1;
    else row = col / 2;
    for (int i = 0; i < col; i++) printf("%c", c);
    printf("\n");
    int space = col - 2;
    for (int i = 0; i < row - 2; i++) {
        printf("%c", c);
        for (int j = 0; j < space; j++) printf(" ");
        printf("%c\n", c);
    }
    for (int i = 0; i < col; i++) printf("%c", c);
    return 0;
}

/*
#include <cstdio>
int main() {
    int n, row;
    char ch;
    scanf("%d %c", &n, &ch);
    row = n / 2 + n % 2;
    for (int i = 0; i < n; i++) printf("%c", ch);
    printf("\n");
    for (int i = 0; i < row - 2; i++) {
        printf("%c", ch);
        for (int j = 0; j < n - 2; j++) printf(" ");
        printf("%c\n", ch);
    }
    for (int i = 0; i < n; i++) printf("%c", ch);
    return 0;
}
*/