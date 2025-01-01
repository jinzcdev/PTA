// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1111914599412858887
#include<bits/stdc++.h>

using namespace std;              //最后一个测试点有时候会TLE QAQ 

unordered_map<string, int> sex;
unordered_map<string, string> fa;

inline bool check(string & a, string & b) {
	unordered_map<string, int> rcd;
	for(int i = 1; a != ""; ++i, a = fa[a]) rcd[a] = i;	
	for(int i = 1; b != ""; ++i, b = fa[b]) {
		if(rcd[b] && (rcd[b] < 5 || i < 5)) return false;
		if(rcd[b] >= 5) return true;	
	}
	return true;
}
#define len(s) s.length()
int main() {
#ifdef MyTest
	freopen("Sakura.txt", "r", stdin);
#else
	ios::sync_with_stdio(false);
	cin.tie(0);
#endif	
	int n, m;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string a, b;
		cin >> a >> b;	
		string s = a + ' ' + b;
		if(b[len(b) - 1] == 'm') sex[s = s.substr(0, len(s) - 1)] = 1;
		else if(b[len(b) - 1] == 'f') sex[s = s.substr(0, len(s) - 1)] = -1;
		else if(b.substr(len(b) - 4) == "sson") {
			sex[s = s.substr(0, len(s) - 4)] = 1;
			fa[a] = b.substr(0, len(b) - 4);
		}
		else if(b.substr(len(b) - 7) == "sdottir") {
			sex[s = s.substr(0, len(s) - 7)] = -1;
			fa[a] = b.substr(0, len(b) - 7);	
		}
	}
	for(cin >> m; m--;) {
		string a, b, c, d;
		cin >> a >> b >> c >> d;
		string x = a + ' ' + b, y = c + ' ' + d;
		if(sex[x] == 0 || sex[y] == 0) cout << "NA\n";
		else if(sex[x] == sex[y]) cout << "Whatever\n";
		else cout << (check(a, c) ? "Yes\n" : "No\n");
	}
	return 0;
}
