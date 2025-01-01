// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1071785055080476672
#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    bool flag = false;
    for (int i = 0; i <= (int)s.size() - k; i++) {
        if (isprime(stoi(s.substr(i, k)))) {
            cout << s.substr(i, k);
            flag = true;
            break;
        }
    }
    if (!flag) cout << "404";
    return 0;
}
/* @pintia note=start
这是笔记

# h1
## h2
### h3

- item1
- item2

```python
print("hello world")
```

> this is a quote

**emphasis** 
@pintia note=end */