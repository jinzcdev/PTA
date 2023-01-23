// https://pintia.cn/problem-sets/988034414048743424/problems/988039902048034816
void InorderTraversal( BinTree BT ) {
    if (BT == NULL) return;
    InorderTraversal(BT->Left);
    printf(" %c", BT->Data);
    InorderTraversal(BT->Right);
}
void PreorderTraversal( BinTree BT ) {
    if (BT == NULL) return;
    printf(" %c", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}
void PostorderTraversal( BinTree BT ) {
    if (BT == NULL) return;
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf(" %c", BT->Data);
}