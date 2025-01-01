// https://pintia.cn/problem-sets/16/exam/problems/type/6?problemSetProblemId=1086
void ShortestDist(MGraph Graph, int dist[], int path[], Vertex S) {
    for (int i = 0; i < Graph->Nv; i++) dist[i] = INFINITY;
    dist[S] = 0;
    path[S] = -1;
    bool vis[MaxVertexNum] = {false};
    while (S != -1) {
        vis[S] = true;
        for (Vertex v = 0; v < Graph->Nv; v++) {
            if (vis[v] == false && Graph->G[S][v] != INFINITY) {
                if (dist[S] + Graph->G[S][v] < dist[v]) {
                    dist[v] = dist[S] + Graph->G[S][v];
                    path[v] = S;
                }
            }
        }
        S = -1;
        for (Vertex v = 0, MIN = INFINITY; v < Graph->Nv; v++) {
            if (vis[v] == false && dist[v] < MIN) {
                S = v;
                MIN = dist[v];
            }
        }
    }
    for (Vertex v = 0; v < Graph->Nv; v++) {
        if (dist[v] == INFINITY) {
            dist[v] = path[v] = -1;
        }
    }
}