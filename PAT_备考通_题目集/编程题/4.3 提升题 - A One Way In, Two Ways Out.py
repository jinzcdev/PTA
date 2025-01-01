# https://pintia.cn/problem-sets/1526027869896364032/exam/problems/type/7?problemSetProblemId=1526203395629957120
n, m = map(int, input().split())
idx = dict()
lst_insert = list(map(int, input().split()))
for i in range(n):
    idx[lst_insert[i]] = i

for _ in range(m):
    output = list(map(int, input().split()))
    inserted = dict()
    q = [0] * 1010
    left, right = 0, 0
    flag = True
    for i in range(n):
        x = output[i]
        for j in range(idx[x] + 1):
            if not inserted.get(j, False):
                q[right] = lst_insert[j]
                inserted[j] = True
                right += 1
        if left == right or (q[left] != x and q[right - 1] != x):
            flag = False
            continue
        if q[left] == x:
            left += 1
        else:
            right -= 1
    print(f"{'yes' if flag else 'no'}")

""" @pintia note=start
假设当前输出的数是x, 则在x之前的数必然已经被输入到队列 q 中, 然后依次判断此时队首或者队尾是不是和x相等即可
@pintia note=end """

"""c++
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> idx;
    vector<int> lst_insert(n);
    for (int i = 0; i < n; i++) {
        cin >> lst_insert[i];
        idx[lst_insert[i]] = i;
    }

    while (m--) {
        vector<int> output(n);
        for (int i = 0; i < n; i++) {
            cin >> output[i];
        }

        unordered_map<int, bool> inserted;
        vector<int> q(1010);
        int left = 0, right = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int x = output[i];
            for (int j = 0; j <= idx[x]; j++) {
                if (!inserted[j]) {
                    q[right++] = lst_insert[j];
                    inserted[j] = true;
                }
            }
            if (left == right || (q[left] != x && q[right - 1] != x)) {
                flag = false;
                continue;
            }
            if (q[left] == x) {
                left++;
            } else {
                right--;
            }
        }
        cout << (flag ? "yes" : "no") << endl;
    }
    return 0;
}
"""