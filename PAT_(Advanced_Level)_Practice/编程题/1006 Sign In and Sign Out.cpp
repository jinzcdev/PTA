// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805516654460928
#include<cstdio>
int main(){
	int N, h, m, s, h1, m1, s1;
	int time1, time2, ftime=10000000, ltime=0, index1, index2;
	scanf("%d",&N);
	char id[N][16];
	for(int i=0; i<N; i++){
		scanf("%s %d:%d:%d %d:%d:%d",id[i], &h, &m, &s, &h1, &m1, &s1);
		time1=h*10000+m*100+s;
		time2=h1*10000+m1*100+s1;
		if(ftime>=time1){index1=i; ftime=time1;}
		if(ltime<=time2){index2=i; ltime=time2;}
	} 
	printf("%s %s",id[index1], id[index2]);
	return 0;
}	 
