// https://pintia.cn/problem-sets/16/problems/962
bool vis[MaxVertexNum] = {false};
void dfs(LGraph Graph, int u) {
    vis[u] = true;
    for (PtrToAdjVNode p = Graph->G[u].FirstEdge; p != NULL; p = p->Next) {
        if (vis[p->AdjV] == false) {
            dfs(Graph, p->AdjV);
        }
    }
}
int CountConnectedComponents(LGraph Graph) {
    int cnt = 0;
    for (int u = 0; u < Graph->Nv; u++) {
        if (vis[u] == false) {
            dfs(Graph, u);
            cnt++;
        }
    }
    return cnt;
}