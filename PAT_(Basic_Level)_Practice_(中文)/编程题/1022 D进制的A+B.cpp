// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805299301433344
#include<cstdio>
int main() {
	int a, b, d, sum;
	scanf("%d%d%d", &a, &b, &d);
	sum = a + b;
	int ans[31], num = 0;
	do
	{
		ans[num++] = sum % d;
		sum /= d;
	} while (sum != 0);
	for (int i = num - 1; i >= 0; i--)
	{
		printf("%d", ans[i]);
	}

	return 0;
}