// https://pintia.cn/problem-sets/15/exam/problems/type/6?problemSetProblemId=925
void PreorderPrintLeaves( BinTree BT ) {
    if (BT == NULL) return;
    if (BT->Left == NULL && BT->Right == NULL) printf(" %c", BT->Data);
    PreorderPrintLeaves(BT->Left);
    PreorderPrintLeaves(BT->Right);
}