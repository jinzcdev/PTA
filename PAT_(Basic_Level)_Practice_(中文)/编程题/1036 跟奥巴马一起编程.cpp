// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805285812551680
#include <cstdio>
#include <cmath>
int main(){
	int row,col;
	char ch;
	scanf("%d %c",&col,&ch);
	row = (int)round((double)col/2);
	for(int i = 0;i < col;i++)
		printf("%c",ch);
	printf("\n");

	row = row - 2;
	while(row--){
		printf("%c",ch);
		for(int i = 0;i < col - 2;i++)
			printf(" ");
		printf("%c\n",ch);
	}

	for(int i = 0;i < col;i++)
		printf("%c",ch);
	return 0;
}