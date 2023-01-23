// https://pintia.cn/problem-sets/434/problems/6085
bool AddQ(Queue Q, ElementType X) {
    if (Q->Count == Q->MaxSize) {
        printf("Queue Full\n");
        return false;
    }
    Q->Data[(Q->Front + Q->Count++) % Q->MaxSize] = X;
    return true;
}
ElementType DeleteQ(Queue Q) {
    if (Q->Count == 0) {
        printf("Queue Empty\n");
        return ERROR;
    }
    ElementType tmp = Q->Data[Q->Front];
    Q->Front = (Q->Front + 1) % Q->MaxSize;
    Q->Count--;
    return tmp;
}