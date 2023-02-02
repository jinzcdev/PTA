// https://pintia.cn/problem-sets/994805046380707840/exam/problems/1111914599412858881
#include <cstdio>
const int len = 100;

int area(int x,int y){
    return len*len/2 - (x*y+(len-x)*(len-y))/2 - (len-x)*y;
}

int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d",area(x,y));
}