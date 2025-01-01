// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=889
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int main() {
	int n, p, key, pos, hash[N] = {0};
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", &key);
		for (int j = 0; j < p; j++) {
			pos = (key + j) % p;
			if (hash[pos] == 0 || hash[pos] == key) {
				hash[pos] = key;
				break;
			}
		}
		printf("%d", pos);
		if (i != n - 1) printf(" ");
	}
	return 0;
}