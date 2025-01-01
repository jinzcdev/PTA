// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805389634158592
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 11111;
bool hashTable[maxn] = {false};

bool isPrime(int x){
    if (x <= 1) return false;
    int sqr = (int)sqrt(x * 1.0);
    for (int i = 2; i <= sqr; i++){
        if (x % i == 0) return false;
    }
    return true;
}

int main(){
    int TSize, n;
    scanf("%d%d", &TSize, &n);
    while (!isPrime(TSize)){
        TSize++;
    }
    int x, key;
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        key = x % TSize;
        if (!hashTable[key]){
            printf("%d", key);
            hashTable[key] = true;
        } else {
            int step;
            for (step = 1; step < TSize; step++){
                key = (x + step * step) % TSize;
                if (!hashTable[key]){
                    printf("%d", key);
                    hashTable[key] = true;
                    break;
                }
            }
            if (step >= TSize){
                printf("-");
            }
        }
        if (i < n - 1) printf(" ");
    }
    return 0;
}