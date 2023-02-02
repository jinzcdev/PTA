// https://pintia.cn/problem-sets/12/exam/problems/338
void strmcpy( char *t, int m, char *s ) {
    int tlen = strlen(t);
    if (m < 0 && m > tlen) return;
    strncpy(s, t + (m - 1), tlen - m + 1);
}