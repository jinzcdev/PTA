// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1697150941050929155
/* @pintia note=start
1. 题意抽象：
题目要求我们计算出一排大熊猫（胖达）在排队吃盆盆奶时，至少需要准备多少毫升的奶。每只胖达至少要吃200毫升的奶，而且它们能够感觉到另一份盆盆奶是否比自己的多出至少100毫升。如果感觉到不公平，它们会抢旁边小伙伴的奶。因此，我们需要确保每只胖达得到的奶量是“公平”的。

2. 解题思路：
- 首先，我们定义两个数组`left`和`right`，分别记录每只胖达向左和向右看时能看到的最大连续非递增序列的长度。
- 对于每只胖达，我们计算它向左和向右看时能看到的最大连续非递增序列的长度，并取两者中的较大值。
- 根据题目要求，每只胖达至少要吃200毫升的奶，而且如果它感觉到旁边的小伙伴的奶比自己的多出至少100毫升，它就会觉得不公平。因此，对于每只胖达，我们需要准备的基础奶量是200毫升，再加上它向左和向右看时能看到的最大连续非递增序列的长度乘以100毫升。
- 最后，我们将所有胖达的基础奶量累加起来，就得到了至少需要准备的奶量。
@pintia note=end */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> v(n + 1), left(n + 1), right(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n && v[j] >= v[j + 1]; j++) {
            if (v[j] > v[j + 1]) ++right[i];
        }
    }
    for (int i = n; i > 1; i--) {
        for (int j = i; j > 1 && v[j] >= v[j - 1]; j--) {
            if (v[j] > v[j - 1]) ++left[i];
        }
    }
    for (int i = 1; i <= n; i++) ans += max(left[i], right[i]) * 100 + 200;
    cout << ans;
    return 0;
}