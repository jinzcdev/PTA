// https://pintia.cn/problem-sets/16/exam/problems/type/6?problemSetProblemId=708
bool TopSort(LGraph Graph, Vertex TopOrder[]) {
    int front = 0, tail = 0, cnt = 0, indegree[MaxVertexNum] = {0};
    for (int i = 0; i < Graph->Nv; i++) {
        PtrToAdjVNode p = Graph->G[i].FirstEdge;
        while (p != NULL) {
            indegree[p->AdjV]++;
            p = p->Next;
        }
    }
    for (int i = 0; i < Graph->Nv; i++) {
        if (indegree[i] == 0) {
            TopOrder[tail++] = i;
        }
    }
    while (front < tail) {
        PtrToAdjVNode p = Graph->G[TopOrder[front++]].FirstEdge;
        while (p != NULL) {
            if (--indegree[p->AdjV] == 0) {
                TopOrder[tail++] = p->AdjV;
            }
            p = p->Next;
        }
        cnt++;
    }
    return Graph->Nv == cnt ? true : false;
}
