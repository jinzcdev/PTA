// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805347145859072
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int number = stoi(s), a = stoi(s.substr(0, s.length() / 2)), b = stoi(s.substr(s.length() / 2));
		if (a * b != 0 && number % (a * b) == 0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}