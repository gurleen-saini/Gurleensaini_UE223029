#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cmath>
using namespace std;

int partition(int *a,int p,int r)
{
    int x=a[r];
    int i=p-1;
    for(int j=p;j<r;j++)
    {
        if(a[j]<=x)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quick_sort(int *a,int p,int r)
{
    if(p<r)
    {
        int j=partition(a,p,r);
        quick_sort(a,p,j-1);
        quick_sort(a,j+1,r);
    }
}

int main()
{
    // int a[6]={1,6,5,4,3,2};
    // quick_sort(a,0,5);
    // for(int i=0;i<6;i++)
    // {
    //     cout<<a[i]<<" ";
    // }

    // for average case:

    for(int j=1000;j<=100000;j=j+1000)
    {
        cout<<j*log(j)/1000<<",";
    }
    
    float A;
    for(int j=1000;j<=100000;j=j+1000)
    {
        int a[j];
        for(int k=0;k<j;k++)
        {
            a[k]=rand();
        }
        clock_t t1=clock();
        for(int l=0;l<10;l++)
        {
            quick_sort(a,0,j-1);
        }
        clock_t t2=clock();
        A=(float)(t2-t1)/10;
        cout<<A<<",";
    }

    //for worst case
    
    // for(int j=1000;j<=100000;j=j+1000)
    // {
    //     cout<<j*j<<",";
    // }

    // float A;
    // for(int j=1000;j<=100000;j=j+1000)
    // {
    //     int a[j];
    //     for(int k=0;k<j;k++)
    //     {
    //         a[k]=rand();
    //     }
    //     sort(a,a+j);
    //     clock_t t1=clock();
    //     for(int l=0;l<10;l++)
    //     {
    //         quick_sort(a,0,j-1);
    //     }
    //     clock_t t2=clock();
    //     A=(float)(t2-t1)/10;
    //     cout<<A<<",";
    // }

}