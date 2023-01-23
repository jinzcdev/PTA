// https://pintia.cn/problem-sets/14/problems/802
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, dis = 0;
    scanf("%d", &n);
    if (n <= 10) {
        printf("^_^ %d", n * 9);
        return 0;
    }
    dis = 90;
    for (int t = 10; t <= n;) {
        if (dis > t * 3)
            t += 30;
        else {
            dis += (n - t) >= 10 ? 90 : (n - t) * 9;
            t += 10;
        }
    }
    if (dis == n * 3) printf("-_- %d", dis);
    else if (dis > n * 3) printf("^_^ %d", dis);
    else printf("@_@ %d", n * 3);
    return 0;
}
/*
因为最开始10分钟内，兔子还没开始回看乌龟，所以10分钟以内的比赛单独确定，超过10分钟的比赛，再用循环。t表示过去t分钟后当前跑的步数
*/
// n = int(input())
// dis_tu, dis_gui = 0, 0
// t_wait, t_run = 0, 0
// relax = False
// for i in range(n):
//     dis_gui += 3
//     if relax:
//         t_wait += 1
//         if t_wait == 30:
//             relax = False
//             t_wait = 0
//     else:
//         dis_tu += 9
//         t_run += 1
//         if t_run % 10 == 0 and dis_tu > dis_gui:
//             relax = True

// if dis_gui > dis_tu:
//     print(f'@_@ {dis_gui}')
// elif dis_gui < dis_tu:
//     print(f'^_^ {dis_tu}')
// else:
//     print('-_-')