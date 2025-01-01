// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=362
char *str_cat( char *s, char *t ) {
    strncat(s, t, strlen(t));
    return s;
}