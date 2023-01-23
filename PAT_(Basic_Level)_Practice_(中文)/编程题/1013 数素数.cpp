// https://pintia.cn/problem-sets/994805260223102976/problems/994805309963354112
#include <cstdio>

bool isPrime(int n){
	if(n <= 1) return false;
	for(int i = 2;i * i <= n;i++)
		if(n % i == 0) return false;
	return true;
}

int main() {
	int m,n,nums,p = 2,count = 0;
	scanf("%d%d",&m,&n);
	nums = n - m + 1;
	while(true){
	    if(isPrime(p))
	    		if(--m == 0) break;
	    	p++;
	}
	int i = 0,nl = 0;
	while(i < nums){
		if(isPrime(p)){
		    i++;
		    nl++;
		    printf("%d",p);
		    if(nl == 10){
		        printf("\n");
		        nl = 0;
		    }else if(i < nums){
		        printf(" ");
		    }
		}
		p++;
	}
	return 0;
}