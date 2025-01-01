// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805053695574016
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
stack<int> st;
int bit[N] = {0}, n, k;
int lowbit(int x) { return x & -x; }
void add(int i, int x) {
    for (int j = i; j <= N; j += lowbit(j)) {
        bit[j] += x;
    }
}
int getPrefixSum(int i) {
    int sum = 0;
    for (int j = i; j > 0; j -= lowbit(j)) {
        sum += bit[j];
    }
    return sum;
}
int peekMedian() {
    int left = 1, right = N, x = (st.size() + 1) / 2, mid = 0;
    while (left < right) {
        mid = (right - left) / 2 + left;
        if (x <= getPrefixSum(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
int main() {
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s[1] == 'o') {
            if (st.empty()) {
                cout << "Invalid" << endl;
                continue;
            }
            add(st.top(), -1);
            cout << st.top() << endl;
            st.pop();
        } else if (s[1] == 'u') {
            cin >> k;
            add(k, 1);
            st.push(k);
        } else {
            if (st.empty()) {
                cout << "Invalid" << endl;
                continue;
            }
            cout << peekMedian() << endl;
        }
    }
    return 0;
}

/* @pintia note=start
使用树状数组求解第k大的数问题。

树状数组可以用 $O(logN)$ 的时间复杂度求解前缀和，这里把出现在栈中的数，作为索引将值在树状数组中增加1，那么求这个数，
也就是把这个数当作索引，求其前缀和的值就是所有比这个数大的个数。但是这里是将数作为索引，所以树状数组的大小就受到可能出现
的最大值的限制，并且存在很多的空间浪费。

在二分查找中有时候，可能数值存在多个，比如 $$\[1,2,3,4,4,4,5,6\]$$，如果要查找最左边或者最右边的4时候，要判断一下，当最后left刚好为right-1时，有没有可能进入死循环。
因为 $$(left + right) / 2$$ 是向下取整的，因此是下面这种情况：

```python
while left < right:
    mid = (left + right) / 2;
    if x >= nums[mid]:
        left = mid
    else:
        right = mid - 1
```

那么，最后只剩两个元素时，如 [4,4] 或者 [4,5] 时，循环是不会结束的。应该改成：

```python
while left < right:
    mid = (left + right) / 2;
    if x > nums[mid]:
        left = mid + 1
    else:
        right = mid
```

**而且最终一定要保证，任何情况下，区间都要有缩减。上面的例子中区间在只剩下两个元素时，没有缩减，因此进入了死循环。**
@pintia note=end */
