#include<bits/stdc++.h>
using namespace std;
#define MX 100
int vertex,edge;
struct NODE
{
    int startingNode,endingNode,dis;
} nodes[MX];

struct values
{
    int dis;
    int parent;
};

map <int,values>itemList;
int iter=0;

bool relax(int u, int v, int dis)
{
    values uTemp = itemList[u];
    values vTemp = itemList[v];
    if(vTemp.dis > uTemp.dis + dis)
    {
        vTemp.dis = uTemp.dis + dis;
        vTemp.parent = u;
        itemList[v] = vTemp;
        //cout << "Update " << v << "\t" << vTemp.dis << "\t" << vTemp.parent << endl;
        return false;
    }
    return true;
}

void setAllVertex(int startingNode)
{
    values valuesTemp;
    valuesTemp.dis=0;
    valuesTemp.parent=startingNode;
    //cout << startingNode << "\t\t" << valuesTemp.dis << "\t\t" << valuesTemp.parent << endl;
    itemList[startingNode]=valuesTemp;
    for(int i=0;i<vertex;i++)
    {
        if(i!=startingNode)
        {
            valuesTemp.dis=INT_MAX;
            valuesTemp.parent=-1;
            itemList[i]=valuesTemp;
            //cout << i << "\t\t" << valuesTemp.dis << "\t\t" << valuesTemp.parent << endl;
        }
    }
}
bool bellmanFord(int startingNode)
{
    setAllVertex(startingNode);
    bool check=true;
    //Vertex - 1 times iterations
    for(int i=0;i<vertex-1;i++)
    {
        check=true;
        bool flag=true;
        for(int i=0;i<edge;i++)
        {
            check=relax(nodes[i].startingNode,nodes[i].endingNode,nodes[i].dis);
            if(!check)
                flag=false;
        }
        if(flag)
            return flag;

        /*      iter++;
                cout << "Vertex" << "\t\t" << "Distance" << "\t" << "Parent" << endl;
                for(int i = 0 ; i < vertex ; i++)
                {
                    values temp = itemList[i];
                    cout << i << "\t\t" << temp.dis << "\t\t" << temp.parent << endl;
                }
                */
    }
    check=true;
    //Last Iteration
    for(int i=0;i<edge;i++)
    {
        check=relax(nodes[i].startingNode, nodes[i].endingNode, nodes[i].dis);
        if(!check)
            return check;
        //iter++;
    }
    iter++;
    return check;
}
int main()
{
    cin>>vertex>>edge;
    int startingNode,endingNode,disTemp;
    for(int i=0;i<edge;i++)
    {
        cin>>startingNode>>endingNode>>disTemp;
        nodes[i].startingNode=startingNode;
        nodes[i].endingNode=endingNode;
        nodes[i].dis=disTemp;
    }

    startingNode=0;
    if(bellmanFord(startingNode))
    {
        // cout <<"There is no negative cycle in the graph"<<endl;
        cout <<"From\t\tTo\t\tDistance\t\n";
        //Parent"<<endl;
        for(int i=0;i<vertex;i++)
        {
            values temp=itemList[i];
            cout<<startingNode<<"\t\t"<<i<<"\t\t"<<temp.dis<<"\t\t\n";
            //<<temp.parent<<endl;
        }
    }
    else
    {
        cout <<"There is a negative cycle in the graph"<<endl;
        return 0;
    }
    //  cout << "Iteration " << iter << endl;
}

/* input
10 18
0 1 3
0 2 5
0 4 4
1 4 1
2 4 2
2 3 2
3 4 -1
1 7 4
4 7 -2
4 6 3
3 5 3
5 6 2
7 6 2
7 9 5
6 9 2
6 8 5
5 8 4
8 9 5
*/
/*
5 10
0 1 6
0 3 7
1 3 8
1 2 5
1 4 -4
3 2 -3
3 4 9
2 1 -2
4 0 2
4 2 7

0
2

7

4

-2

*/
