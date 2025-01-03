// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805325918486528
#include <cstdio>
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    while (n != 1) {
        n = (n % 2 == 0 ? n : 3 * n + 1) / 2;
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}

/* @pintia note=start
## 思路

## 复杂度

## 代码

```cpp
#include <cstdio>
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    while (n != 1) {
        n = (n % 2 == 0 ? n : 3 * n + 1) / 2;
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}
```
@pintia note=end */