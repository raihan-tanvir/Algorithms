#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
#define pii pair< int, int >

struct comp
{
    bool operator() (const pii &a, const pii &b)
    {
        return a.second > b.second;
    }
};

priority_queue< pii, vector< pii >, comp > Q;
vector< pii > G[MAX];
int DIST[MAX];
bool visited[MAX];

int main()
{
    int i, u, v, w, nodes, edges, source=0;

    scanf("%d %d", &nodes, &edges);
    for(i=0; i<edges; i++)
    {
        cin>>u>>v>>w;
        G[u].push_back(pii(v, w));
    }

    for(i=1; i<=nodes; i++)
        DIST[i] = INT_MAX;
    DIST[source] = 0;
    Q.push(pii(source, 0));

    // dijkstra
    while(!Q.empty())
    {
        u = Q.top().first;
        Q.pop();
        if(!visited[u])
        {
            for(i=0; i<G[u].size(); i++)
            {
                v = G[u][i].first;
                w = G[u][i].second;
                if(!visited[v] && DIST[u]+w < DIST[v])
                {
                    DIST[v] = DIST[u] + w;
                    Q.push(pii(v, DIST[v]));
                }
            }
            visited[u] = 1;
        }
    }

    for(i=0; i<nodes; i++)
        printf("Node %d, Distance From Source = %d\n", i, DIST[i]);
    return 0;
}
