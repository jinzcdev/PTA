// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805260990660608
#include <cmath>
#include <iostream>
using namespace std;
int main() {
    double max = -1, min = 99;
    int n, id, x, y, winner, loser;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d", &id, &x, &y);
        double dis = sqrt(x * x + y * y);
        if (dis > max) {
            max = dis;
            loser = id;
        }
        if (dis < min) {
            min = dis;
            winner = id;
        }
    }
    printf("%04d %04d", winner, loser);
    return 0;
}