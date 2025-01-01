// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=310
int factorsum( int number ) {
  int sum = 1;
  for (int i = 2; i < number; i++)
    if (number % i == 0) sum += i;
  return sum;
}
void PrintPN( int m, int n ) {
  int flag = 0;
  for (int i = m; i <= n; i++) {
    if (factorsum(i) == i) {
      flag = 1;
      printf("%d = 1", i);
      for (int j = 2; j < i; j++) {
        if (i % j == 0) printf(" + %d", j);
      }
      printf("\n");
    }
	}
  if (!flag) printf("No perfect number");
}