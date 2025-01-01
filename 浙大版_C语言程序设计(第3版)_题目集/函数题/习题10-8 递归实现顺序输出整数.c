// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=358
void printdigits( int n ) {
    if (n < 10) {
        printf("%d\n", n);
        return;
    }
    printdigits(n / 10);
    printf("%d\n", n % 10);
}