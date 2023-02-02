// https://pintia.cn/problem-sets/14/exam/problems/788
#include <cstdio>
int main() {
    int v;
    scanf("%d", &v);
    printf("Speed: %d - %s", v, v > 60 ? "Speeding" : "OK");
    return 0;
}