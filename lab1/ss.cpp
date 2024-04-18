#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int * ss(int * a, int n)
{
    int j;
    for(int i=0;i<n;i++)
    {
        j=i;
        for(int k=i+1;k<n;k++)
        {
            if(a[k]<a[j])
            {
                j=k;
            }
        }
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    return a;
}

int main(){
    float A;
    for(int j=1000;j<=100000;j=j+1000){
        int a[j];
        for(int k=0;k<j;k++){
            a[k]=rand()%j;
        }
        clock_t t1=clock();
        for(int x=1;x<=10;x++){
            ss(a,j);
        }
        clock_t t2=clock();
        A=(float)(t2-t1)/10;
        cout<<A<<",";
    }
}