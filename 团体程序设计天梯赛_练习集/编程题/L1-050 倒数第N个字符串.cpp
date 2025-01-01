// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805080346181632
#include <bits/stdc++.h>
using namespace std;
int main() {
	int l, n;
	scanf("%d%d", &l, &n);
	vector<char> v(l);
    n--;
	for (int i = 0; i < l; i++)
		v[i] = 'z' - (n / (int)pow(26, i) % 26);
	for (int i = l - 1; i >=0; i--)
		printf("%c", v[i]);
	return 0;
}