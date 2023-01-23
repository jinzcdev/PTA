// https://pintia.cn/problem-sets/994805046380707840/problems/994805082313310208
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int main() {
	int ra, ca, rb, cb, a[N][N], b[N][N], c[N][N];
	cin >> ra >> ca;
	for (int i = 0; i < ra; i++)
		for (int j = 0; j < ca; j++)
			cin >> a[i][j];
	cin >> rb >> cb;
	for (int i = 0; i < rb; i++)
		for (int j = 0; j < cb; j++)
			cin >> b[i][j];
	if (ca != rb) {
		printf("Error: %d != %d\n", ca, rb);
		return 0;
	}
	for (int i = 0; i < ra; i++) {
		for (int j = 0; j < cb; j++) {
			int sum = 0;
			for (int k = 0; k < ca; k++) {
				sum += a[i][k] * b[k][j];
			}
			c[i][j] = sum;
		}
	}
	printf("%d %d\n", ra, cb);
	for (int i = 0; i < ra; i++) {
		for (int j = 0; j < cb; j++) {
			if (j != 0) printf(" ");
			printf("%d", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}