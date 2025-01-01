// https://pintia.cn/problem-sets/16/exam/problems/type/6?problemSetProblemId=702
int Isomorphic(Tree T1, Tree T2) {
    if (T1 == NULL && T2 == NULL) return 1;
    if ((T1 == NULL && T2 != NULL) || (T2 == NULL && T1 != NULL)) return 0;
    if (T1->Element != T2->Element) return 0;
    int left = 0, right = 0;
    if (T1->Left == NULL && T2->Left == NULL) return Isomorphic(T1->Right, T1->Right);
    else if (T1->Right == NULL && T2->Right == NULL) return Isomorphic(T1->Left, T2->Left);
    else return Isomorphic(T1->Left, T2->Right) && Isomorphic(T1->Right, T2->Left);
}