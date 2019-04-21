#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int p);
int main()
{
    int n;
    clock_t start, end;
    start=clock();

    cin>>n;
    bubbleSort(n);

    end=clock();
    int time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("%d ms\n", 1000*time);
}
void bubbleSort(int p)
{
    int arr[p];

    for(int i=0; i<p; i++)
    {
        arr[i]=rand()%100;
    }

    cout<<"Before Sorting:"<<" ";
    for(int i=0; i<p; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int k=p;
    int compNum=0;
    int swapNum=0;

    while(k!=0)
    {
        int t=0;
        for(int j=0; j<=k-1; j++)
        {
            compNum++;
            if(arr[j]>arr[j+1])
            {
                swapNum++;
                swap(arr[j], arr[j+1]);
                t = j;
            }
        }
        k=t;
    }

    cout<<"After Sorting:"<<" ";
    for(int i=0; i<p; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Data Compared:"<<compNum<<endl;
    cout<<"Data Swapped:"<<swapNum<<endl;
}
