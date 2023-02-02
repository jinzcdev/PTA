// https://pintia.cn/problem-sets/13/exam/problems/476
int factorsum(int number) {
    int sqr = 1, sum = 0;
    while (sqr * sqr < number) sqr++;
    for (int j = 1; j < sqr; j++) {
        if (number % j == 0) {
            sum += j;
            if (number != j * j && j != 1) sum += (number / j);
        }
    }
    return sum;
}

void PrintPN(int m, int n) {
    int flag = 0;
    for (int i = m; i <= n; i++) {
        if (factorsum(i) == i) {
            flag = 1;
            printf("%d = ", i);
            for (int j = 1; j < i; j++) {
                if (i % j == 0) {
                    if (j != 1) printf(" + ");
                    printf("%d", j);
                }
            }
            printf("\n");
        }
    }
    if (!flag) printf("No perfect number");
}