#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

void mergeArray(int arr[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1],R[n2+1];

    for(int i=0; i<n1; i++)
        L[i]=arr[p+i];

    for(int j=0; j<n2; j++)
        R[j]=arr[q+1+j];

    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    for(int i=0,j=0,k=p; k<=r; k++)
    {
        if(L[i]<=R[j])
            arr[k]=L[i++];

        else
            arr[k]=R[j++];
    }
}

void mergeSort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q =((p+r)/2);
        mergeSort(arr,p,q);
        mergeSort(arr,q+1,r);
        mergeArray(arr,p,q,r);
    }
}

int main()
{
    srand(time(0));
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        arr[i]=rand()%1000;

    cout <<"Before : ";
    for(int i=0; i<n; i++)
        cout <<arr[i]<<" ";

    cout<<endl;

    mergeSort(arr,0,n-1);

    cout <<"After : ";
    for(int i=0; i<n; i++)
        cout <<arr[i]<< " ";
}
