// https://pintia.cn/problem-sets/434/exam/problems/type/6?problemSetProblemId=6098
bool Push(Stack S, ElementType X) {
    if (S->Top == S->MaxSize) {
        printf("Stack Full\n");
        return false;
    }
    S->Data[S->Top++] = X;
    return true;
}
ElementType Pop(Stack S) {
    if (S->Top == 0) {
        printf("Stack Empty\n");
        return ERROR;
    }
    return S->Data[--S->Top];
}