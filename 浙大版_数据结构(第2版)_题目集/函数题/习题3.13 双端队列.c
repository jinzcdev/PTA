// https://pintia.cn/problem-sets/434/exam/problems/type/6?problemSetProblemId=6096
bool Push(ElementType X, Deque D) {
    if ((D->Rear + 1) % D->MaxSize == D->Front) {
        return false;
    }
    D->Front = (D->Front - 1 + D->MaxSize) % D->MaxSize;
    D->Data[D->Front] = X;
    return true;
}
ElementType Pop(Deque D) {
    if (D->Front == D->Rear) {
        return ERROR;
    }
    ElementType tmp = D->Data[D->Front];
    D->Front = (D->Front + 1) % D->MaxSize;
    return tmp;
}
bool Inject(ElementType X, Deque D) {
    if ((D->Rear + 1) % D->MaxSize == D->Front) {
        return false;
    }
    D->Data[D->Rear] = X;
    D->Rear = (D->Rear + 1) % D->MaxSize;
    return true;
}
ElementType Eject(Deque D) {
    if (D->Front == D->Rear) {
        return ERROR;
    }
    ElementType tmp = D->Data[(D->Rear - 1 + D->MaxSize) % D->MaxSize];
    D->Rear = (D->Rear - 1 + D->MaxSize) % D->MaxSize;
    return tmp;
}