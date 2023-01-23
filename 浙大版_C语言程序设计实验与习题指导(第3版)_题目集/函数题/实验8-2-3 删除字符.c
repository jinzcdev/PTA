// https://pintia.cn/problem-sets/13/problems/553
void delchar( char *str, char c ) {
    int len = strlen(str), i = 0, j = 0;
    for ( ; i < len; i++) {
        if (str[i] != c) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}