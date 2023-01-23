// https://pintia.cn/problem-sets/12/problems/312
int prime( int p ) {
  if (p <= 1) return 0;
  for (int i = 2; i * i <= p; i++)
    if (p % i == 0) return 0;
 	return 1;
}
void Goldbach( int n ) {
  for (int i = 2; i <= n / 2; i++) {
    if (prime(i) && prime(n - i)) {
      printf("%d=%d+%d", n, i, n - i);
     	break;
    }
  }
}