// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805276438282240
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 110;
char a[maxn], b[maxn], ans[maxn] = {0};

int main(){
	scanf("%s %s", a, b);
	int lenA = strlen(a),lenB = strlen(b);
	int len = max(lenA,lenB);
	reverse(a, a + lenA);
	reverse(b, b + lenB);

	int i;
	for (i = 0; i < len; i++){
		int numA = i < lenA ? a[i] - '0' : 0;
		int numB = i < lenB ? b[i] - '0' : 0;
		// 索引为偶数,序号为奇数
		if(i % 2 == 0){
			int temp = (numA + numB) % 13;
			if(temp == 10) ans[i] = 'J';
			else if(temp == 11) ans[i] = 'Q';
			else if(temp == 12) ans[i] = 'K';
			else ans[i] = temp + '0';
		}else{
			int temp = numB - numA;
			if(temp >= 0) ans[i] = temp + '0';
			else ans[i] = (temp + 10) + '0';
		}
	}

	reverse(ans,ans + len);
	printf("%s",ans);
	return 0;
}