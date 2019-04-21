#include<bits/stdc++.h>
using namespace std;
int n;
void selectionSort(int a[])
{
    for(int j=n-1 ; j>=1 ; j--)
    {
        int t=0;
        for(int k=1; k<=j; k++)
        {
            if(a[t]<a[k])
                t=k;
        }
        swap (a[j],a[t]);
    }
}
int main()
{
    cin>>n;
    int arr[n];
    srand(rand());
    for(int i=0; i<n; i++)
        arr[i]=rand()%1000;

    cout<<"Before Sorting:";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    cout<<endl;

    selectionSort(arr);
    cout <<"After Sorting : ";
    for(int i=0 ; i<n ; i++)
        cout<<arr[i]<<" ";
}
