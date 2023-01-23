// https://pintia.cn/problem-sets/994805260223102976/problems/994805275146436608
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// const int maxn;
bool cmp(int a, int b) { return a > b; }
int main() {
    int N, matrix[10000][100];
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    int m, n;
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            m = N / i;
            n = i;
        }
    }
    sort(v.begin(), v.end(), cmp);
    int e[] = {n - 1, m - 1, 0, 1};
    int x = 0, y = -1, cnt = 0, d = 0;
    matrix[x][y] = v[0];
    for (int i = 0; i < N; i++) {
        if (d == 0 && ++y == e[0]) {
            d = 1;
            e[0]--;
        } else if (d == 1 && ++x == e[1]) {
            d = 2;
            e[1]--;
        } else if (d == 2 && --y == e[2]) {
            d = 3;
            e[2]++;
        } else if (d == 3 && --x == e[3]) {
            d = 0;
            e[3]++;
        }
        matrix[x][y] = v[i];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j != 0) printf(" ");
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}