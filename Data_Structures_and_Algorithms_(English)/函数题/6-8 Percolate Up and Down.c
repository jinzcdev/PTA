// https://pintia.cn/problem-sets/16/exam/problems/type/6?problemSetProblemId=703
void PercolateUp(int p, PriorityQueue H) {
    int i = p, j = i / 2;
    while (j >= 1) {
        if (H->Elements[j] <= H->Elements[i]) break;
        ElementType temp = H->Elements[j];
        H->Elements[j] = H->Elements[i];
        H->Elements[i] = temp;
        i = j;
        j = i / 2;
    }
}

void PercolateDown(int p, PriorityQueue H) {
    int i = p, j = i * 2;
    while (j <= H->Size) {
        if (j + 1 <= H->Size && H->Elements[j + 1] < H->Elements[j]) j = j + 1;
        if (H->Elements[j] >= H->Elements[i]) break;
        ElementType temp = H->Elements[j];
        H->Elements[j] = H->Elements[i];
        H->Elements[i] = temp;
        i = j;
        j = i * 2;
    }
}