// https://pintia.cn/problem-sets/15/exam/problems/type/6?problemSetProblemId=730
Stack CreateStack(int MaxSize) {
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(sizeof(ElementType) * MaxSize);
    S->MaxSize = MaxSize;
    S->Top1 = -1;
    S->Top2 = MaxSize;
    return S;
}
bool Push(Stack S, ElementType X, int Tag) {
    if (S->Top1 + 1 == S->Top2) {
        printf("Stack Full\n");
        return false;
    }
    if (Tag == 1)
        S->Data[++S->Top1] = X;
    else
        S->Data[--S->Top2] = X;
    return true;
}
ElementType Pop(Stack S, int Tag) {
    if ((Tag == 1 && S->Top1 == -1) || (Tag == 2 && S->Top2 == S->MaxSize)) {
        printf("Stack %d Empty\n", Tag);
        return ERROR;
    }
    int temp = (Tag == 1 ? S->Data[S->Top1--] : S->Data[S->Top2++]);
    return temp;
}