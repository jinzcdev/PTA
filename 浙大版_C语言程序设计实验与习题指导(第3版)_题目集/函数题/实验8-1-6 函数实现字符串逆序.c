// https://pintia.cn/problem-sets/13/problems/541
void f(char *p) {
    int len = 0, j = 0;
    while (p[j++] != '\0') len++;
    for (int i = 0; i < len / 2; i++) {
        char t = p[i];
        p[i] = p[len - i - 1];
        p[len - i - 1] = t;
    }
}