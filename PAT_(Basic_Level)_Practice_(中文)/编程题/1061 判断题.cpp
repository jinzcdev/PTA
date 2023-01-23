// https://pintia.cn/problem-sets/994805260223102976/problems/994805268817231872
#include<cstdio>
int main(){
  int a[110][110]={0};
  int stu,judge;
  scanf("%d%d",&stu,&judge);
  for(int i = 0 ;i < judge;i++){
    scanf("%d",&a[0][i]);
  }
  for(int i = 0 ;i < judge;i++){
    scanf("%d",&a[1][i]);
  }
  for(int i =0;i<stu;i++)
    for(int j =0;j<judge;j++)
      scanf("%d",&a[i+2][j]);
  int sum;
  for(int i = 0;i<stu;i++){
    sum = 0;
    for(int j =0;j<judge;j++){
      sum += a[0][j]*(!(a[1][j]^a[i+2][j]));
    }
    printf("%d",sum);
    if(i<stu-1) printf("\n");
  }
}