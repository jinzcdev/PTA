// https://pintia.cn/problem-sets/13/exam/problems/466
int CountDigit(int number, int digit) {
    int cnt = 0;
    if (number == 0 && digit == 0) return 1;
    if (number < 0) number = -number;
    while (number != 0) {
        if (number % 10 == digit) cnt++;
        number /= 10;
    }
    return cnt;
}