// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=364
char *search( char *s, char *t ) {
    int slen = strlen(s), tlen = strlen(t);
    for (int i = 0; i <= slen - tlen; i++) {
        if (s[i] == t[0]) {
            int flag = 1;
            for (int j = 0; j < tlen; j++) {
                if (s[i + j] != t[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) return s + i;
        }
    }
    return NULL;
}