// https://pintia.cn/problem-sets/13/exam/problems/542
void f(long int x, char *p) {
    if (x == 0) {
        p[0] = '0';
        p[1] = '\0';
        return;
    }
    int pos = 0, t, len = 0;
    char s[MAXN] = "";
    if (x < 0) {
        p[len++] = '-';
        x = -x;
    }
    while (x != 0) {
        t = x % 16;
        if (t < 10) s[pos++] = '0' + t;
        else s[pos++] = (t - 10) + 'A';
        x /= 16;
    }
    for (int i = pos - 1; i >= 0; i--) {
        p[len++] = s[i];
    }
    p[len] = '\0';
}