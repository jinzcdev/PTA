// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805323154440192
#include <cstdio>
#include <cstring>
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        char str[110];
        scanf("%s", str);
        int len = strlen(str);
        int num_p = 0, num_t = 0, other = 0;
        int loc_p = -1, loc_t = -1;
        for(int i = 0; i < len; i++) {
            if(str[i] == 'P') {
                num_p++;
                loc_p = i;
            }else if(str[i] == 'T') {
                num_t++;
                loc_t = i;
            }else if(str[i] != 'A') other++;
        }
        if((num_p != 1) || (num_t != 1) || (other != 0) || (loc_t - loc_p <= 1)) {
            printf("NO\n");
            continue;
        }
        int x = loc_p, y = loc_t - loc_p - 1, z = len - loc_t - 1;
        if(z - x * (y - 1) == x) {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}