#include<iostream>
#include<ctime>
using namespace std;

void th(int count,char source,char destination,char sparse)
{
    if(count==1)
    {
        // cout<<"move from "<<source<<" to "<<destination<<endl;
    }
    else
    {
        th(count-1,source ,sparse,destination);
        th(1,source,destination,sparse);
        th(count-1,sparse,destination,source);
    }
}

int main()
{
    float A;
    for(int j=1;j<=100;j++)
    {
        clock_t t1=clock();
        for(int i=0;i<10;i++)
        {
            th(j,'A','B','C');
        }
        clock_t t2=clock();
        A=(float)(t2-t1)/10;
        cout<<A<<",";
    }
}