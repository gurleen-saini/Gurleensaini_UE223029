#include<iostream>
#include<cstdlib>
#include<ctime>
#include<map>
using namespace std;

int iterativeSum(int *a, int size) {
    int sum =1;
    for (int i = 0; i < size; i++) {
        sum += a[i];
    }
    return sum;
}

int s(int *a, int n,int m)
{
    if(n==m)
    {
        return 0;
    }
    else
    {
        return a[n]+s(a,n+1,m);
    }
}

int main()
{

    float A;
    map<float, int> m;

    for (int j = 100000; j <= 10000000; j += 100000)
    {
        int *a = new int[j];
        for (int k = 0; k < j; k++)
        {
            a[k] = rand();
        }
        clock_t t1 = clock();
        int t = 0;

        for (int x = 1; x <= 10; x++)
        {
            // t = s(a,0,j);
            t = iterativeSum(a,j);
        }

        clock_t t2 = clock();
        A = (float)(t2 - t1) / 10;
        cout << A *100<< ",";
        m[A] = j;
    }
}
