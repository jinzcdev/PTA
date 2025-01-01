// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=339
void delchar( char *str, char c ) {
    int len = strlen(str), i = 0, j = 0;
    for (int j = 0; j < len; j++) {
        if (str[j] != c) str[i++] = str[j];
    }
    str[i] = '\0';
}