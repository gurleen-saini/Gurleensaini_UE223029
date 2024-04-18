#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

// here m:power and x:number

// iteratively finding power conplexity=O(m)
// long long power(int m, int x) {
//     long long p = 1;
//     for (int i = 0; i < m; i++) {
//         p *= x;
//     }
//     return p;
// }


// here complexity=O(log m base 2)
long long power(int m,int x)
{
    long long p=1;
    while(m!=0)
    {
        if(m%2==0)
        {
            x=x*x;
            m=m/2;
        }
        else
        {
            p=p*x;
            m=m-1;
        }
    }
    return p;
}

int main()
{
    // Simple case for testing function
    // cout<<power(5,2);

    float A;

    for (int j = 1; j <= 30; j++)
    {
        clock_t t1 = clock();
        long long t = 0;

        for (int x = 1; x <= 10; x++)
        {
            t=power(j,2);
            // cout<<t<<" ";
        }

        clock_t t2 = clock();
        A = (float)(t2 - t1) / 10;
        cout << A<< ",";
    }
}
