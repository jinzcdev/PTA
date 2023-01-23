// https://pintia.cn/problem-sets/12/problems/313
int reverse( int number ) {
    int isneg = 0;
    if (number < 0) {
        isneg = 1;
        number = -number;
    }
    int sum = 0;
    while (number != 0) {
        sum = sum * 10 + number % 10;
        number /= 10;
    }
    return isneg ? -sum : sum;
}