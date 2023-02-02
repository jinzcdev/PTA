// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805368847187968
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;
int n, origin[maxn], temp[maxn], changed[maxn];

bool isSame(int *a, int *b) {
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void printArray(int *a) {
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", a[i]);
    }
}

void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while (j <= high) {
        if (j + 1 <= high && temp[j + 1] > temp[j]) {
            j = j + 1;
        }
        if (temp[j] > temp[i]) {
            swap(temp[j], temp[i]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

bool insertSort() {
    bool flag = false;
    for (int i = 2; i <= n; i++) {
        if (i != 2 && isSame(temp, changed)) {
            flag = true;
        }
        sort(temp, temp + i + 1);
        if (flag) {
            return true;
        }
    }
    return false;
}

void heapSort() {
    bool flag = false;
    for (int i = n / 2; i >= 1; i--) {
        downAdjust(i, n);
    }
    for (int i = n; i > 1; i--) {
        if (i != n && isSame(temp, changed)) {
            flag = true;
        }
        swap(temp[i], temp[1]);
        downAdjust(1, i - 1);
        if (flag == true) {
            printArray(temp);
            return;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", origin + i);
        temp[i] = origin[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", changed + i);
    }
    if (insertSort()) {
        printf("Insertion Sort\n");
        printArray(temp);
    } else {
        printf("Heap Sort\n");
        for (int i = 1; i <= n; i++) {
            temp[i] = origin[i];
        }
        heapSort();
    }
    return 0;
} 