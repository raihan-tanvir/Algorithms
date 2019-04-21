#include <bits/stdc++.h>
using namespace std;
#define max 100

float fractionalKnapSack(int n,int weight[],int value[],int limit)
{
    float valuePerWeight[n];

    for(int i=0; i<n; i++)
    {
        valuePerWeight[i]=((float)value[i]/weight[i]);
    }
    float vpw1,vpw2;
    for(int i=0;i<n;i++){
        if(valuePerWeight[i]<valuePerWeight[i+1]){
            swap(value[i],value[i+1]);
            swap(weight[i],weight[i+1]);
            swap(valuePerWeight[i],valuePerWeight[i+1]);

        }
    }

    int currentWeight=0;
    float totalProfit=0.0;

    for(int i=0; i<n; i++)
    {
        if(currentWeight+weight[i]<=limit)
        {
            currentWeight+=weight[i];
            totalProfit+=value[i];
        }
        else
        {
            int remainingWeight=limit-currentWeight;
            currentWeight+=remainingWeight;
            totalProfit+=remainingWeight*valuePerWeight[i];
            break;
        }
    }

    return totalProfit;
}
int main ()
{
    int n;
    cin>>n;

    int w[n],v[n];

    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>w[i];
    }

    int l;
    cin>>l;

    cout<<setprecision(4)<<fractionalKnapSack(n,w,v,l)<<endl;

    return 0;
}
