// https://pintia.cn/problem-sets/91827364500/exam/problems/91827370501
#include <cstdio>
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    while (!(n % 7 == 0 && n % 4 != 0)) n++;
    printf("%d\n", n);
  }
  return 0;
}