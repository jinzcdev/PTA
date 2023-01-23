// https://pintia.cn/problem-sets/12/problems/346
#include <stdio.h>
#include <string.h>
int main() {
    int n;
    double val, maxv = -1, minv = 999999;
    char s[35], maxs[35], mins[35];
    scanf("%d", &n);
    while (n--) {
        getchar();
        fgets(s, 35, stdin);
        int len = strlen(s);
        s[--len] = '\0';
        scanf("%lf", &val);
        if (val > maxv) {
            strcpy(maxs, s);
            maxv = val;
        }
        if (val < minv) {
            strcpy(mins, s);
            minv = val;
        }
    }
    printf("%.2f, %s\n", maxv, maxs);
    printf("%.2f, %s\n", minv, mins);
    return 0;
}