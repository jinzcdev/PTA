// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805280074743808
#include <cstdio>
#include <cstring>

void print(int pos){
	switch(pos){
		case 0 : printf("P");break;
		case 1 : printf("A");break;
		case 2 : printf("T");break;
		case 3 : printf("e");break;
		case 4 : printf("s");break;
		case 5 : printf("t");break;
	}
}

int hashTable(char ch){
	int pos;
	switch(ch){
		case 'P': pos = 0;break;
		case 'A': pos = 1;break;
		case 'T': pos = 2;break;
		case 'e': pos = 3;break;
		case 's': pos = 4;break;
		case 't': pos = 5;break;
		default: pos = -1;
	}
	return pos;
}

int main()
{
	int a[6] = {0};
	char str[10010];
	scanf("%s",str);
	int len = strlen(str);
	for(int i = 0;i < len;i++){
		int pos = hashTable(str[i]);
		if(pos != -1)
		a[pos]++;
	}
	int max = a[0];
	for(int i = 1;i < 6;i++){
		if(a[i] > max)
			max = a[i];
	}
	while(max--){
		for(int i = 0;i < 6;i++){
			if(a[i] > 0){
				a[i]--;
				print(i);
			}
		}
	}

	return 0;
}