// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805373582557184
#include <cstdio>
using namespace std;
const int MOD=1e9+7;
int main() {
    char ch;
    int p=0,a=0,cnt=0;
    while((ch=getchar())!='\n') {
        if(ch=='P') {
            p++;
        } else if(ch=='A') {
            a+=p;
        } else {
            cnt=(cnt+a)%MOD;
        }
    }
    printf("%d",cnt);
    return 0;
}