// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805269312159744
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
bool cmp(int a, int b) {
    return a > b;
}
int num[maxn];
int main(){
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }
    sort(num, num + n, cmp);
    for (int i = 0; i < n; i++){
        if (i + 1 < num[i]) {
            ans = i + 1;
        }
    }
    cout << ans;
    return 0;
}