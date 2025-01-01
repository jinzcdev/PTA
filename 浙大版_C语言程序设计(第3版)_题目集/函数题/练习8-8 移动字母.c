// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=333
void reverse(char *s, int len) {
    char t;
    for (int i = 0; i < len / 2; i++) {
        t = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = t;
    }
}
void Shift(char s[]) {
    int len = strlen(s);
    reverse(s, 3);
    reverse(s + 3, len - 3 );
    reverse(s, len);
}