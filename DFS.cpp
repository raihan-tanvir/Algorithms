#include <bits/stdc++.h>
const int yes=1;

using namespace std;

int vertex, edge=5, j, k, connect[100][100], coun=0;
stack<int> s;

struct node{
    int discovery_time, finishing_time, visit;
}G[100];

void DFS(int v){
    G[v].discovery_time = ++coun;
    G[v].visit = yes;
    for(int i=1; i<=vertex; i++){
        if(connect[v][i] == yes && G[i].visit != yes){
            DFS(i);
        }
    }
    G[v].finishing_time = ++coun;
    s.push(v);
}

int main()
{

    for(int i=0; i<edge; i++){
        cin>> j >> k;
        connect[j][k] = yes;
        connect[k][j] = yes;
    }

    DFS(1);

    while(!s.empty()){
        cout << s.top() << "\t";
        s.pop();
    }

    return 0;
}
