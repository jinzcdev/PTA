// https://pintia.cn/problem-sets/16/exam/problems/706
void ShortestDist(LGraph Graph, int dist[], Vertex S) {
    int INF = 0x7FFFFFFF;
    for (int i = 0; i < Graph->Nv; i++) dist[i] = INF;
    bool vis[MaxVertexNum] = {false};
    dist[S] = 0;
    while (S != -1) {
        vis[S] = true;
        PtrToAdjVNode p = Graph->G[S].FirstEdge;
        while (p != NULL) {
            if (vis[p->AdjV] == false && dist[p->AdjV] > dist[S] + 1) {
                dist[p->AdjV] = dist[S] + 1;
            }
            p = p->Next;
        }
        S = -1;
        int MIN = INF;
        for (Vertex v = 0; v < Graph->Nv; v++) {
            if (vis[v] == false && dist[v] < MIN) {
                S = v;
                MIN = dist[v];
            }
        }
    }
    for (Vertex v = 0; v < Graph->Nv; v++)
        if (dist[v] == 0x7FFFFFFF) dist[v] = -1;
}