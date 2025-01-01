// https://pintia.cn/problem-sets/13/exam/problems/type/6?problemSetProblemId=411
int is( int number ) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum == 5;
}
void count_sum( int a, int b ) {
    int cnt = 0, sum = 0;
    for (int i = a; i <= b; i++) {
        if (is(i)) {
            cnt++;
            sum += i;
        }
    }
    printf("count = %d, sum = %d\n", cnt, sum);
}