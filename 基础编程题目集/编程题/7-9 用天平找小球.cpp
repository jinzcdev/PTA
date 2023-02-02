// https://pintia.cn/problem-sets/14/exam/problems/789
#include <cstdio>
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == b) printf("C");
    else printf("%c", a == c ? 'B' : 'A');
    return 0;
}