// https://pintia.cn/problem-sets/16/problems/1085
int known[MaxVertexNum];

void ShortestDist(MGraph Graph, int dist[], int count[], Vertex S) {
    for (int i = 0; i < Graph->Nv; i++) dist[i] = INFINITY, count[i] = 0;
    dist[S] = 0, count[S] = 1;

    while (S != -1) {
        known[S] = 1;
        for (int i = 0; i < Graph->Nv; i++) {
            if (!known[i]) {
                if (dist[i] > Graph->G[S][i] + dist[S])
                    dist[i] = Graph->G[S][i] + dist[S], count[i] = count[S];
                else if (dist[i] == Graph->G[S][i] + dist[S])
                    count[i] += count[S];
            }
        }

        S = -1;
        for (int i = 0, v_min = INFINITY; i < Graph->Nv; i++)
            if (!known[i] && v_min > dist[i])
                v_min = dist[i], S = i;
    }

    for (int i = 0; i < Graph->Nv; i++) {
        if (dist[i] == INFINITY) count[i] = 0, dist[i] = -1;
    }
}