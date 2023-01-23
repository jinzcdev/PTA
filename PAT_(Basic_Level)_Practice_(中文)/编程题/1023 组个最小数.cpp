// https://pintia.cn/problem-sets/994805260223102976/problems/994805298269634560
#include <cstdio>
int main() {
    int count[10];
    for(int i = 0; i < 10; i++) {
        scanf("%d", &count[i]);
    }
    for(int i = 1; i < 10; i++) {
        if(count[i] > 0) {
            printf("%d", i);
            count[i]--;
            break;
        }
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < count[i]; j++) {
            printf("%d", i);
        }
    }
    return 0;
}