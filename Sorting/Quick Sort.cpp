#include<bits/stdc++.h>
using namespace std;

int arr[100000];
void quickSort(int f,int l)
{
    int i,j,pivot;

    if(f<l)
    {
        i=f;
        j=l;
        pivot=(f+l)/2;
        while(arr[i]<arr[pivot])
            i++;

        while(arr[j]>arr[pivot])
            j--;

        if(i<j)
        {
            swap(arr[i],arr[j]);
            //while (arr[i]<arr[f])
                i++;

            //while(arr[j]>arr[f])
                j--;
        }
        swap(arr[j],arr[f]);
        quickSort(f, j-1);
        quickSort(j+1, l);
    }
}
int main()
{
    int n;
    cin>>n;
    srand(rand());
    for(int i=0; i<n; i++)
        arr[i]=rand();

    cout<<"Before Sorting:";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    cout << endl;

    quickSort(0,n-1);

    cout <<"After Sorting : ";
    for(int i=0; i<n; i++)
        cout <<arr[i]<<" ";
}
