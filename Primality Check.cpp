#include<bits/stdc++.h>
using namespace std;
int case1=0,case2=0,case3=0;

int binaryExponentiation(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return binaryExponentiation(x*x,n/2);
    else
        return x*binaryExponentiation(x*x,(n-1)/2);
}

bool isPrimeByFermat(int n,int k)
{
    if(n<2)
        return false;
    else if(n==2)
        return true;
    else
        for(int i=0; i<=k; i++)
        {
            int a=1+rand()%(n-2);
            if (binaryExponentiation(a, n-1)%n ==1)
                return true;
            else return false;
        }
}
bool isPrimeByBasic(int n)
{
    if(n<2)
        return false;
    else if(n==2)
        return true;
    else
        for(int i=2; i*i<=n; i++)
        {
            if(n%i==0)
                return false;
        }
}
int main()
{
    srand(time(NULL));
    int arr[1000];

    for(int i=0; i<1000
            ; i++)
    {
        arr[i]=rand()%1000;
    }

    for(int i=0; i<1000; i++)
    {
        /*  if(isPrimeByBasic(arr[i])==true)
              cout<<arr[i]<<" is Prime By Basic       ";
          else
              cout<<arr[i]<<" is not Prime By Basic       ";
          if(isPrimeByFermat(arr[i],50)==true)
              cout<<arr[i]<<" is Prime By Fermat"<<endl;
          else
              cout<<arr[i]<<" is not Prime By Fermat"<<endl;
              */
        if(isPrimeByBasic(arr[i]) && isPrimeByFermat(arr[i],50) )
        {
            cout<<arr[i]<<" is Prime By Both\n";
            case1++;
        }
        if(isPrimeByBasic(arr[i]) && isPrimeByFermat(arr[i],50)==false )
        {
            cout<<arr[i]<<" is Prime By Basic But not Fermat\n";
            case2++;
        }
        if(isPrimeByBasic(arr[i])==false && isPrimeByFermat(arr[i],50) )
        {
            cout<<arr[i]<<" is not Prime By Basic But Fermat\n";
            case3++;
        }
    }
    cout<<"\nPrime BY Both :"<<case1;
    cout<<"\nPrime BY Basic not Fermat :"<<case2;
    cout<<"\nnot Prime BY Basic But Fermat :"<<case3;
    cout<<"\nnot Prime BY Both :"<<1000-case1-case2-case3;

}
