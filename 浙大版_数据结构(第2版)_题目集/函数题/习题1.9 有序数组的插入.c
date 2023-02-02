// https://pintia.cn/problem-sets/434/exam/problems/965573204499779584
bool Insert(List L, ElementType X) {
    int i = 0;
    while (i <= L->Last && L->Data[i] > X) i++;
    if (i == MAXSIZE) return false;
    if (i != -1 && L->Data[i] == X) return false;
    for (int j = L->Last; j >= i; j--) {
        L->Data[j + 1] = L->Data[j];
    }
    L->Data[i] = X;
    L->Last++;
    return true;
}