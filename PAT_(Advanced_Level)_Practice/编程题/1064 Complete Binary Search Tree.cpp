// https://pintia.cn/problem-sets/994805342720868352/problems/994805407749357568
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1010;
int number[maxn],CBT[maxn],N,index = 0;

void InOrderBST(int root){
	if(root > N ) return;
	InOrderBST(root * 2);
	CBT[root] = number[index++];
	InOrderBST(root * 2 + 1);
}

int main(){
	scanf("%d",&N);
	for (int i = 0; i < N ; i++){
		scanf("%d",&number[i]);
	}
	sort(number,number+N);
	InOrderBST(1);
	for (int i = 1; i <= N; i++){
		printf("%d",CBT[i]);
		if(i < N) printf(" ");
	}
	return 0;
}