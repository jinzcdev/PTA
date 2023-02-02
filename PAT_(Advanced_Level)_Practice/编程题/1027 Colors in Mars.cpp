// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805470349344768
#include <cstdio>
char change(int x){
    if (x > 9){
        return x - 10 + 'A';
    } else {
        return x + '0';
    }
}

int main(){
    int n;
    printf("#");
    for (int i = 0; i < 3; i++){
        scanf("%d", &n);
        printf("%c", change(n / 13));
        printf("%c", change(n % 13));
    }
    return 0;
}