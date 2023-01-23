// https://pintia.cn/problem-sets/16/problems/1046
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void sort(ElementType *arr, int start, int end) {
    if (start >= end) return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right) left++;
        while (arr[right] >= mid && left < right) right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else {
        left++;
        swap(&arr[left], &arr[end]);
    }
    if (left) sort(arr, start, left - 1);
    sort(arr, left + 1, end);
}

void merge_pass(ElementType list[], ElementType sorted[], int N, int length) {
    for (int i = 0; i < N; i++) sorted[i] = list[i];
    length *= 2;
    int i = 0;
    for (; i + length < N; i += length) {
        sort(sorted, i, i + length - 1);
    }
    if (i <= N) {
        sort(sorted, i, N - 1);
    }
}