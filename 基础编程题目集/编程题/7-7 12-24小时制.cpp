// https://pintia.cn/problem-sets/14/problems/787
#include <cstdio>
int main() {
    int h, m;
    scanf("%d:%d", &h, &m);
    if (h > 12) printf("%d:%d ", h - 12, m);
    else printf("%d:%d ", h, m);
    if (h < 12) printf("AM");
    else printf("PM");
    return 0;
}
