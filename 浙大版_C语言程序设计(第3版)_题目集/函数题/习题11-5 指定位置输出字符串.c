// https://pintia.cn/problem-sets/12/problems/363
char *match(char *s, char ch1, char ch2) {
    char *p = s;
    while (*p != '\0' && *p != ch1) p++;
    char *r = p;
    while (*r != '\0' && *r != ch2) printf("%c", *(r++));
    if (*r != '\0') printf("%c", *r);
    printf("\n");
    return p;
}