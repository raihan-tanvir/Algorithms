#include<bits/stdc++.h>
using namespace std;
#define INF 99999
int main()
{
    int V,E;

    cin>>V;
    cin>>E;
    int  dist[V+1][V+1], i, j, k,u,v,w;

    for (i = 1; i <= V; i++)
    {
        for (j = 1; j <= V; j++)
            dist[i][j] = INF;
    }

    for (i = 1; i <= V; i++)
    {
        for (j = 1; j <= V; j++)
        {
            if(i==j)
            {
                dist[i][j] = 0;
            }
        }
    }
    for (i = 1; i <= E; i++)
    {
        cin>>u>>v>>w;
        dist[u][v]=w;
    }

    for (k = 1; k <= V; k++)
    {
        for (i = 1; i <= V; i++)
        {
            for (j = 1; j <= V; j++)
            {
                 dist[i][j] =min(dist[i][k] + dist[k][j],dist[i][j]);
            }
        }
    }
    cout<<"Shortest Distance:\n";
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (dist[i][j] == INF)
                printf("%s\t", "INF");
            else
                printf ("%d\t", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}


/*
5 9
1 2 3
1 5 -4
1 3 8
2 5 7
2 4 1
3 2 4
4 1 2
5 4 6
4 3 -5
*/
