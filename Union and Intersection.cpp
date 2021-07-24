#include<iostream>
using namespace std;
#include<cmath>
#include <cstdlib>
#include <ctime>
unsigned long long int U[10000000],Ub[10000000],A[10000000],B[10000000],Ab[10000000],Bb[10000000],n,c=0;
unsigned long long int BwA[10000000],BwB[10000000],AUBb[10000000],AnBb[10000000];

long long int convert(long long int b)
{
    if(b==0)
    {
        return 0;
    }
    else
    {
        return (b % 2+10*convert(b/2));
    }
}
void ab()
{
    for(int j=1; j<=n; j++)
    {
        A[j]=rand()% n + 1;
        Ab[j]=convert(A[j]);
    }


    for(int j=1; j<=n; j++)
    {
        B[j]=rand()% n + 1;
        Bb[j]=convert(B[j]);
    }
    for(int j=1; j<=n; j++)
    {
        BwA[j]=A[j]%2;
        BwB[j]=B[j]%2;
    }
}
void ora()
{
    for(int l=1; l<=n; l++)
    {
        if(BwA[l]==1||BwB[l]==1)
        {
            AUBb[l]=1;
            c=1;
        }
        if(c==0)
        {
            AUBb[l]=0;
        }
    }
}
void anda()
{
    for(int l=1; l<=n; l++)
    {
        if(BwA[l]==1&&BwB[l]==1)
        {
            AnBb[l]=1;
            c=1;
        }
        if(c==0)
        {
            AnBb[l]=0;
        }
        c=0;    }
}
main()
{
    cin>>n;
    int i=1;
    for(int j=1; j<=n; j++)
    {
        U[j]=j;
        Ub[j]=convert(U[j]);
    }
    for(int j=1; j<=n; j++)
    {
        cout<<U[j]<<"\t"<<Ub[j]<<endl;
    }
    double start_s1=clock();
    ab();
    ora();
    double stop_s1=clock();
    double start_s2=clock();
    ab();
    anda();
    double stop_s2=clock();

    cout<<"Bite wise A"<<"\t\t\t"<<"Bite wise B"<<"\t"<<"AUB"<<"\t\t"<<"AnB"<<endl;
    for(int j=1; j<=n; j++)
    {
        cout<<BwA[j]<<"\t\t\t\t"<<BwB[j]<<"\t\t"<<AUBb[j]<<"\t\t"<<AnBb[j]<<endl;
    }
    cout << "AUB time in ns: " << (stop_s1-start_s1)/double(CLOCKS_PER_SEC)*1000000000<< endl;
    cout << "AnB time in ns: " << (stop_s2-start_s2)/double(CLOCKS_PER_SEC)*1000000000<< endl;
    cout<<n;
}

