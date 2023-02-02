// https://pintia.cn/problem-sets/12/exam/problems/364
char *search( char *s, char *t ) {
    int slen = strlen(s), tlen = strlen(t);
    for (int i = 0; i <= slen - tlen; i++) {
        if (s[i] == t[0]) {
            int flag = 1;
            // if (tlen % 2 == 1 && s[i + tlen / 2] != t[tlen / 2]) break;
            for (int j = 0; j < tlen / 2; j++) {
                if (s[i + j] != t[j] || s[i + tlen - 1 - j] != t[tlen - j - 1]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) return s + i;
        }
    }
    return NULL;
}