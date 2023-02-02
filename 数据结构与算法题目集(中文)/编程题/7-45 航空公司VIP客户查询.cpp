// https://pintia.cn/problem-sets/15/exam/problems/892
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	int n, m, k, dis;
	char id[20];
	unordered_map<string, int> mileage;
	scanf("%d%d", &n, &k);
	while (n--) {
		scanf("%s%d", id, &dis);
		if (dis < k) dis = k;
		mileage[string(id)] += dis;
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%s", id);
		string s = string(id);
		if (mileage[s] != 0) printf("%d\n", mileage[s]);
		else printf("No Info\n");
	}
	return 0;
}