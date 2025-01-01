// https://pintia.cn/problem-sets/434/exam/problems/type/6?problemSetProblemId=6475
void BFS(LGraph Graph, Vertex S, void (*Visit)(Vertex)) {
    Vertex Queue[MaxVertexNum];
    int front = 0, back = 0;
    Queue[back++] = S;
    Visited[S] = true;
    while (front != back) {
        Vertex now = Queue[front++];
        Visit(now);
        PtrToAdjVNode p = Graph->G[now].FirstEdge;
        while (p != NULL) {
            if (!Visited[p->AdjV]) {
                Queue[back++] = p->AdjV;
                Visited[p->AdjV] = true;
            }
            p = p->Next;
        }
    }
}