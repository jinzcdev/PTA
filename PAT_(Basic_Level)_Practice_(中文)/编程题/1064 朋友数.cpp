// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805267416334336
#include <cstdio>
#include <cstring>
int main(){
	int T,len,a[40] = {0},sum = 0;
	char str[4];
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		len = strlen(str);
		int pos = 0;
		for(int i = 0;i < len;i++)
			pos += str[i] - '0';
		a[pos]++;
		if(a[pos] == 1)	sum++;
	}
	printf("%d\n",sum);
	int flag = 0;
	for(int i = 0;i < 40;i++){
		if(a[i] > 0){
			if(flag == 1)
				printf(" %d",i);
			else{
				printf("%d",i);
				flag = 1;
			}
		}
	}
	return 0;
}