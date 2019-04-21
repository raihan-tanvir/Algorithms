#include <bits/stdc++.h>
struct node
{
    int u,w;
};

bool graph[mx+10][mx+10];
bool visit[mx+10];

int BFS(int source,int destination)
{
    queue <node> Q;
    node obj;
    obj.u=source;
    obj.w=0;

    Q.push(obj);
    visit[source]=true;

    while(Q.size()!=0)
    {
        obj = Q.front();
        Q.pop();
        int u = obj.u , w = obj.w;
        if(u==destination) return w;

        for(int i=0;i<=mx;i++)
        {
            if(graph[u][i]==true&&visit[i]==false)
            {
                visit[i]=true;
                obj.u=i;obj.w=w+1;
                Q.push(obj);
            }
        }
    }

    return -1;
}
int main()
{
    int N,M;

    scanf("%d%d",&N,&M);
    for(int i=0;i<=mx;i++) for(int j=0;j<=mx;j++) graph[i][j] = false ;

    while(M--)
    {
        int u , v ;
        scanf("%d%d",&u,&v);
        graph[u][v]= graph[v][u] = true;
    }

    int x , y ;
    scanf("%d%d",&x,&y);

    printf("%d\n",BFS(x,y));

    return 0;
}
