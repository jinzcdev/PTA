// https://pintia.cn/problem-sets/12/problems/306
int narcissistic( int number ) {
    int len = 0, temp = number, sum = 0, d[10];
    for ( ; temp != 0; temp /= 10) d[len++] = temp % 10;
    for (int i = 0; i < len; i++) sum += pow(d[i], len);
    return number == sum;
}
void PrintN( int m, int n ) {
    for (int i = m + 1; i < n; i++)
        if (narcissistic(i)) printf("%d\n", i);
}