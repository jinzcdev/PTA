// https://pintia.cn/problem-sets/13/exam/problems/469
int gcd( int x, int y ) {
    return y == 0 ? x : gcd(y, x % y);
}