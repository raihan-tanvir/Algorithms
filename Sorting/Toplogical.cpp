#include <bits/stdc++.h>
#define MAX 101
using namespace std;

vector <int> adj [MAX];
vector <int> LIST [MAX];
bool visited[MAX];
stack<int> Stack;

int INDEG[MAX], vertex, edge;

void DFS(int v)
{
    visited[v] = true;

    vector<int>::iterator i;
    for (i = LIST[v].begin(); i != LIST[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
    Stack.push(v);
}
void topologicalSortDFS()
{
    for (int i = 1; i <=vertex; i++)
        visited[i] = false;

    for (int i=1; i<=vertex; i++)
    {
        if (visited[i]==false)
            DFS(i);
    }
    while (!(Stack.empty()))
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}
void TOPOLOGICAL_SORT(vector <int> adjList [MAX])
{
    queue<int> Q;

    for(int i=1; i<=vertex; i++)
    {
        if(INDEG[i] == 0)
            Q.push(i);
    }

    vector <int> ::iterator i;
    while(!Q.empty())
    {
        int s = Q.front();
        Q.pop();
        printf("%d ",s);

        for (i = adjList[s].begin(); i != adjList[s].end(); ++i)
        {
            INDEG[*i]--;
            if(INDEG[*i] == 0)
            {
                Q.push(*i);
            }
        }
    }

}

int main(void)
{
    cin >> vertex >> edge;

    for(int i=0; i<MAX; i++)
        INDEG[i] = 0;

    int u, v;
    for(int e=1; e<=edge; e++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        INDEG[v]++;
    }
    TOPOLOGICAL_SORT(adj);
    cout<<endl;
    //topologicalSortDFS();
    return 0;
}
