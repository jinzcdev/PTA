// https://pintia.cn/problem-sets/12/problems/362
char *str_cat( char *s, char *t ) {
    strncat(s, t, strlen(t));
    return s;
}