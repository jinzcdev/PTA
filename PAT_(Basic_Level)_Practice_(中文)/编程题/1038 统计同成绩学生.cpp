// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805284092887040
#include<cstdio>
int main(){
  int a[10010],n,pos;
  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    scanf("%d",&pos);
    a[pos]++;
  }
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&pos);
    printf("%d",a[pos]);
    if(T > 0)
      printf(" ");
  }
  
  return 0;
}