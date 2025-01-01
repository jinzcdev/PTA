// https://pintia.cn/problem-sets/16/exam/problems/type/6?problemSetProblemId=707
void ShortestDist(MGraph Graph, int dist[], Vertex S) {
    for (int i = 0; i < Graph->Nv; i++) dist[i] = INFINITY;
    dist[S] = 0;
    bool vis[MaxVertexNum] = {false};
    while (1) {
        int u = -1, MIN = INFINITY;
        for (Vertex v = 0; v < Graph->Nv; v++) {
            if (vis[v] == false && dist[v] < MIN) {
                u = v;
                MIN = dist[v];
            }
        }
        if (u == -1) break;
        vis[u] = true;
        for (Vertex v = 0; v < Graph->Nv; v++) {
            if (vis[v] == false && Graph->G[u][v] != INFINITY) {
                if (dist[u] + Graph->G[u][v] < dist[v]) {
                    dist[v] = dist[u] + Graph->G[u][v];
                }
            }
        }
    }
    for (Vertex v = 0; v < Graph->Nv; v++) {
        if (dist[v] == INFINITY) dist[v] = -1;
    }
}