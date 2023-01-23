// https://pintia.cn/problem-sets/434/problems/966247795744329728
List Delete(List L, ElementType minD, ElementType maxD) {
    Position Len = 0;
    for (int i = 0; i <= L->Last; i++) {
        if (L->Data[i] <= minD || L->Data[i] >= maxD) {
            L->Data[Len++] = L->Data[i];
        }
    }
    L->Last = Len - 1;
    return L;
}