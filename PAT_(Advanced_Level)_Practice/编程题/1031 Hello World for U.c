// https://pintia.cn/problem-sets/994805342720868352/problems/994805462535356416
#include<stdio.h>
#include <stdlib.h>
int main(){
  char s[1000],m;
  int i = 0,j,left,right,side,bm;
  while((m=getchar()) != '\n'){
    s[i++]=m;
  }
  if(i%3 == 1){
    side = i/3+1;
    bm = i - side*2;
  }else if(i%3 == 2){
    side = i / 3 + 1;
    bm = i / 3;
  }else{
    side = bm = i/3;
  }
  
  for(left=0,right=i-1;left<side-1;){
    printf("%c",s[left]);
    for(j = 0;j<bm;j++)
      printf(" ");
    printf("%c\n",s[right]);
    left++;
    right--;
  }
  
  while(left<=right){
  	printf("%c",s[left]);
  	left++;
  }
  return 0;

}