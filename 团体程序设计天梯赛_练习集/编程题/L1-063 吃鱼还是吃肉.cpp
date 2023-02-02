// https://pintia.cn/problem-sets/994805046380707840/exam/problems/1111914599412858884
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, s, h, w;
    cin >> n;
    while (n--) {
        scanf("%d%d%d", &s, &h, &w);
        if (s == 1) {
            if (h < 130) printf("duo chi yu! ");
            else if (h > 130) printf("ni li hai! ");
            else printf("wan mei! ");
            if (w < 27) printf("duo chi rou!\n");
            else if (w > 27) printf("shao chi rou!\n");
            else printf("wan mei!\n");
        } else {
            if (h < 129) printf("duo chi yu! ");
            else if (h > 129) printf("ni li hai! ");
            else printf("wan mei! ");
            if (w < 25) printf("duo chi rou!\n");
            else if (w > 25) printf("shao chi rou!\n");
            else printf("wan mei!\n");
        }
    }
    return 0;
}