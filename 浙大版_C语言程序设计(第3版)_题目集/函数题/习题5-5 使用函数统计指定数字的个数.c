// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=305
int CountDigit( int number, int digit ) {
    if (number == 0 && digit == 0) return 1;
    if (number < 0) number = -number;
    int cnt = 0;
    while (number != 0) {
        if (number % 10 == digit) cnt++;
        number /= 10;
    }
    return cnt;
}