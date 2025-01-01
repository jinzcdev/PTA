// https://pintia.cn/problem-sets/434/exam/problems/type/6?problemSetProblemId=6472
void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) )
{
    Visited[V]=true;
    Visit(V);
    for(int i=0;i<Graph->Nv;i++)
    {
        if(Graph->G[V][i]<INFINITY&&!Visited[i]){
            DFS(Graph,i,Visit);
        }
    }
}