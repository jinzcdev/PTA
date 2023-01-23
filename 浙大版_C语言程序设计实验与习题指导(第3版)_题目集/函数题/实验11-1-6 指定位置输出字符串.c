// https://pintia.cn/problem-sets/13/problems/592
char *match(char *s, char ch1, char ch2) {
    int pos1 = 0, pos2 = 0, len = 0;
    while (s[len] != '\0') len++;
    while (pos1 < len && s[pos1] != ch1) pos1++;
    while (pos2 < len && s[pos2] != ch2) pos2++;
    if (pos1 < len && pos2 == len) pos2 = len - 1;
    if (pos1 <= pos2) {
        for (int i = pos1; i <= pos2; i++) printf("%c", s[i]);
    }
    printf("\n");
    return s + pos1;
}