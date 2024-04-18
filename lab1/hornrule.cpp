#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

// int horner(int *a,int n,int m,int x)
// {
//     if(n==m-1)
//     {
//         return a[n];
//     }
//     else
//     {
//         return (a[n]+x*horner(a,n+1,m,x));
//     }
// }

int horner(int *a,int m,int x)
{
    int sum=0;
    for(int i=0;i<m;i++)
    {
        sum+=a[i]*(pow(x,i));
    }
    return sum;
}

int main(){
    // int a[4]={1,2,3,4};
    // cout<<"hi"<<endl;
    // cout<<horner(a,0,4,2);
    float A;
    for(int j=10000;j<=1000000;j=j+10000)
    {
        int a[j];
        for(int k=0;k<j;k++)
        {
            a[k]=rand();
        }
        clock_t t1=clock();
        for(int l=0;l<10;l++)
        {
            int t = horner(a,j,2);
        }
        clock_t t2=clock();
        A=(float)(t2-t1)/10;
        cout<<A<<",";
    }
}
