// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805504927186944
#include <cstdio>
int main(){
    double w, t, l, max = 1.0;
    for (int i = 0; i < 3; i++){
        scanf("%lf%lf%lf", &w, &t, &l);
        if (w > t && w > l){
            printf("W ");
            max *= w; 
        } else if (t > w && t > l){
            printf("T ");
            max *= t;
        } else if (l > w && l > t){
            printf("L ");
            max *= l;
        }
    }
    printf("%.2f", (max * 65 / 100 - 1) * 2);
    return 0;
}