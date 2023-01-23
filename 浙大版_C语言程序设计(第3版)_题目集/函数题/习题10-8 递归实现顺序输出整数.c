// https://pintia.cn/problem-sets/12/problems/358
void printdigits( int n ) {
    if (n < 10) {
        printf("%d\n", n);
        return;
    }
    printdigits(n / 10);
    printf("%d\n", n % 10);
}