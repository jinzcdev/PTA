// https://pintia.cn/problem-sets/13/exam/problems/556
char *str_cat( char *s, char *t ) {
    int slen = strlen(s), tlen = strlen(t);
    for (int i = 0; i < tlen; i++) {
        s[slen++] = t[i];
    }
    s[slen] = '\0';
    return s;
}