#include <bits/stdc++.h>

using namespace std;

struct node
{
    char label;
    int value;

};

bool operator < ( node a,  node b)
{
    return a.value > b.value;
}

priority_queue< node> pq2;

 void priority()
 {
     int i= 0,v;
     char l;
     node temp;
    while ( i <3) {
     cin>> l >>v;
    temp.label = l;
    temp.value = v;
    pq2.push(temp);
    i++;
    }
node top = pq2.top();
cout<<" weight node " << "\t" <<top.label << "  "  <<top.value ;
 }

int main()

{

  priority_queue< pair< int, int > > pq;

  pq.push(make_pair(1, 1));
  pq.push(make_pair(-2, 2));
  pq.push(make_pair(3, 3));

  cout<< "vertex "<< pq.top().second  <<" value : " <<pq.top().first;

}
