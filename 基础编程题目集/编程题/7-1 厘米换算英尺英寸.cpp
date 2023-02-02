// https://pintia.cn/problem-sets/14/exam/problems/781
#include <cstdio>
int main() {
    int cm, foot, inch;
    scanf("%d", &cm);
    foot = cm / 30.48;
    inch = (cm / 30.48 - foot) * 12;
    printf("%d %d", foot, inch);
    return 0;
}