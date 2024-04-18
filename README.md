# Gurleensaini_UE223029

INDEX
1	SUM OF N NUMBERS			
2	SELECTION SORT			
3	TOWER OF HANOI			
4	PERMUTATION GENERATOR			
5	POWER FUNCTION			
6	HORNERS RULE			
7	FINDING CORRECT POSITION OF A NUMBER			
8	MERGE 2 SORTED LIST TO FORM ONE LIST(SORTED)			
9	QUICK SORT			
10	ITERATIVE QUICK SORT			
11	MERGE SORT			
12	FINDING MAXIMUM MINIMUN NUMBER OF LIST			
13	BINARY SEARCH			
14	KNAPSACK PROBLEM			
15	ACTIVITY SELECTOR			
16	FINDING SINGLE SOURCE SHORTEST PATH			
17	PRIMS ALGORITHM			
18	KRUSKALS ALGORITHM			
19	MATRIX MULTIPLICATION RECURSIVELY			
20.	MATRIX MULTIPLICATION SRASSONS			
21.	MINIMUM COST IN MULTISTAGE GRAPH			
22.	ALL PAIRS SHORTEST PATH			
23.	LONGEST COMMON SUBSEQUENCE			
24.	0/1 KNABSACK (DYNAMIC PROGRAMMING)			
25.	MINIMIZING THE SCALAR MATRIX MULTIPLICATIONS			
26.	HORNERS RULE			
27.	N QUEENS PROBLEM
(BACKTRACKING)			
28.	0/1 KNABSACK USING MERGE PURGE			
29.	SUM OF SUBSETS (BACKTRACKING)			
30.	COLORING NODES(BACKTRACKING)			


PROGRAM 1
AIM: Write a program to calculate sum of N natural numbers provided in the array through iterative and recursive approach.

Algorithm:
•	Iteratively (iterativeSum):
1.	Input: Array arr of integers, and its size n.
2.	Initialize a variable sum to 0.
3.	Loop: Iterate i from 0 to n-1.
Add arr[i] to sum.
4.	Return the value of sum.
•	Recursively (s):
1.	Input: Array arr of integers, and its size n.
2.	Base Case: If n equals last element (i.e., there is only one element in the array):
Return the value of arr[last_element_index].
3.	Recursive Case:
Return the sum of the last element arr[0] and the result of recursively calling s with parameters arr and n+1.
Source Code:
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<map>
using namespace std;

int iterativeSum(int *a, int size) {
    int sum =0;
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
Time Complexity:
•	Theoretically

Iteratively (iterativeSum):
1.	In the iterative approach, each element of the array is visited exactly once in the loop.
2.	Thus, the time complexity of this method is O(n), where n is the size of the array.
3.	Regardless of the value of n, the algorithm iterates through each element in a linear manner, leading to a linear time complexity.

Recursively (s):
1.	In the recursive approach, the function is called recursively for each element of the array until the base case is reached (when n equals last element).
2.	At each step of the recursion, the function makes a single recursive call, increasing the size of the problem by 1.
3.	The recursion continues until the base case is reached, where a constant time operation (accessing the single element of the array) is performed.
4.	The number of recursive calls made by this function is equal to the size of the array
i.e. n.
5.	Therefore, the time complexity of this method is also O(n).

PROGRAM 2
AIM: Write a program to sort n numbers provided in an array using selection sort and discuss it’s time complexity .

Algorithm:
1. Start with an array `a` of length `n`.
2. For each index `i` from 0 to `n-1`:
    a. Set `j` to `i`.
    b. For each index `k` from `i+1` to `n-1`:
        i. If `a[k]` is less than `a[j]`, update `j` to `k`.
    c. Swap the elements at indices `i` and `j`.
3. Repeat step 2 until all elements are sorted.
4. Return the sorted array `a`.

Source Code:
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
Time Complexity:
In short, the time complexity of selection sort is O(n^2), where n is the number of elements in the array. This is because selection sort compares and possibly swaps every element with every other element, resulting in quadratic time complexity.

PROGRAM 3

AIM: Write a program to solve the problem of tower of Hanoi i.e. how to transfer elements or so called disks from source to destination.

Algorithm:
1. Define a function `th` that takes four parameters: 
   - `count`: the number of disks to be moved.
   - `source`: the peg from which disks are initially placed.
   - `destination`: the peg to which disks are to be moved.
   - `sparse`: the spare peg used for intermediate placement.
2. If `count` is 1:
    a. Move the top disk from the source peg to the destination peg.
3. Else:
    a. Recursively move `count-1` disks from the source peg to the spare peg using the destination peg as a spare.
    b. Move the remaining 1 disk from the source peg to the destination peg.
    c. Recursively move the `count-1` disks from the spare peg to the destination peg using the source peg as a spare.
4. Repeat steps 2 and 3 recursively until all disks are moved to the destination peg.

Source Code:
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

Time Complexity:
The Tower of Hanoi is a classic problem in computer science and mathematics that involves moving a stack of disks from one peg to another, while adhering to the rules that only one disk can be moved at a time and no disk can be placed on top of a smaller disk. The problem can be solved recursively with a divide-and-conquer approach.

The time complexity of the Tower of Hanoi problem can be expressed as O(2^n), where n is the number of disks. This complexity arises because the number of moves required to solve the Tower of Hanoi problem for n disks doubles with each additional disk.

Each time a recursive call is made, it divides the problem into three subproblems of size n-1 (moving the top n-1 disks to the spare peg, moving the largest disk to the target peg, and moving the n-1 disks from the spare peg to the target peg). As a result, the number of recursive calls made is exponential, leading to the exponential time complexity of O(2^n).

PROGRAM 4
AIM: Write a program to draw truth table and also discuss it’s time complexity.

Algorithm:
1. Define a function `str` that takes three parameters:
   - `x`: a character array to store the generated string.
   - `n`: the current index indicating the number of 'T's placed so far.
   - `m`: the total length of the string.
2. If `n` equals `m`, the string is complete:
    a. Optionally, print or process the generated string (commented out in the provided code).
3. Else:
    a. Set the character at index `n` in the array `x` to 'T'.
    b. Recursively call `str` with incremented `n`.
    c. Set the character at index `n` in the array `x` to 'F'.
    d. Recursively call `str` with incremented `n`.
4. Repeat steps 2 and 3 recursively until all combinations are generated.
Source Code:
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<map>
using namespace std;
void str(char * x, int n,int m)
{
    if(n==m)
    {
        // for(int i=0;i<m;i++)
        // {
        //     cout<<x[i];
        // }
        // cout<<endl;
        // cout<<"Done"<<endl;
    }
    else
    {
        x[n]='T';
        str(x,n+1,m);
        x[n]='F';
        str(x,n+1,m);
    }
}

int main(){
    float A;
    for(int j=1;j<=100;j++){
        char x[j];
        clock_t t1=clock();
        for(int o=1;o<=10;o++){
            str(x,0,j);
        }
        clock_t t2=clock();
        A=(float)(t2-t1)/10;
        cout<<A<<",";
    }
}

Time Complexity:
Creating a truth table is a method used in logic to enumerate all possible combinations of inputs and their corresponding outputs for a given logical expression. The time complexity of generating a truth table depends on the number of variables involved. Let's break down the process:
Counting Combinations: For a logical expression with n variables, there are 2^n possible combinations of inputs. This is because each variable can take on either a true or false value, resulting in 2 choices for each variable.
Computational Complexity: Enumerating all possible combinations involves evaluating the logical expression for each combination, which requires O(1) time for each combination.
Total Time Complexity: Since there are 2^n combinations, the overall time complexity to generate a truth table is O(2^n).
Example: Suppose you have a logical expression with 3 variables (A, B, C). This would result in 2^3 = 8 possible combinations of inputs. For each combination, you evaluate the logical expression, which takes constant time. Therefore, the time complexity is O(8) = O(1).
Optimization: While generating a truth table is straightforward, it becomes impractical for expressions with many variables due to the exponential growth in the number of combinations. In practice, truth tables are typically used for smaller expressions or as a tool for understanding the behavior of logical expressions rather than for large-scale computation.

In summary, the time complexity of generating a truth table is exponential, O(2^n), where n is the number of variables in the logical expression. While suitable for small expressions, this approach becomes computationally intensive for larger expressions.

PROGRAM 5

AIM: Write a program to solve for power of any number both iteratively and recursively and also discuss it’s time complexity.

Algorithm:
Initialize a variable p to store the result and set it to 1 initially.
While m is not zero:
a. If m is even (m % 2 == 0):
i. Update x to x squared (x * x).
ii. Halve m (m = m / 2).
b. If m is odd:
i. Multiply p by x.
ii. Decrement m by 1 (m = m - 1).
Return the final value of p

Source Code:
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

    for (int j = 10000000; j <= 1000000000; j += 10000000)
    {
        clock_t t1 = clock();
        long long t = 0;

        for (int x = 1; x <= 10; x++)
        {
            t=power(j,100000000);
        }

        clock_t t2 = clock();
        A = (float)(t2 - t1) / 10;
        cout << A<< ",";
    }
}
Time Complexity:
Recursive Version:
The recursive version of the power function calculates x^m recursively. It uses a divide-and-conquer approach where it recursively calls itself with halved values of m until m becomes 0. If m is even, it squares the result of the recursive call; if m is odd, it multiplies the result by x before squaring. This approach also results in a time complexity of O(log m) because the number of recursive calls is proportional to the number of bits in the binary representation of m.
In the iterative approach, the number of iterations directly correlates with the value of m. For each iteration of the loop, m decreases by 1 until it reaches 0. Therefore, the time complexity of the iterative approach is indeed O(m).

PROGRAM 6

AIM: Write a program to implement horner’s rule and also discuss it’s time complexity.

Algorithm:
Initialize a variable sum to store the result and set it to 0 initially.
Iterate through each coefficient a[i] of the polynomial from i = 0 to i = m - 1:
a. For each coefficient a[i], compute a[i] * x^i using pow(x, i) (raising x to the power of i).
b. Add the result to the sum.
Return the final value of sum, which represents the evaluation of the polynomial at x.

Source Code:
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
            int t = horner(a,j,2);
        }
        clock_t t2=clock();
        A=(float)(t2-t1)/10;
        cout<<A<<",";
    }
}
Time Complexity:
Horner's rule, a widely used algorithm for polynomial evaluation, offers an efficient approach with a time complexity of O(n), where n represents the degree of the polynomial. The algorithm capitalizes on the distributive property of polynomials to streamline the evaluation process. It proceeds by iteratively computing the value of the polynomial, starting from the highest degree term and progressively working downwards. At each step, it performs basic arithmetic operations, such as addition and multiplication, on the coefficients of the polynomial. By reducing the computation to a linear number of operations proportional to the degree of the polynomial, Horner's rule provides a significant advantage over naive methods, particularly for polynomials of higher degrees. This makes it a valuable tool for tasks such as polynomial interpolation or evaluating polynomials at specific points, offering both simplicity and efficiency in computational applications.

PROGRAM 7

AIM: Write a program to find exact position of given element in an array and also discuss it’s time complexity.

Algorithm:
Initialize variables greater and smaller to count the number of elements greater than and smaller than ele respectively.
Iterate through the array a:
Increment smaller if the current element is smaller than ele.
Increment greater if the current element is greater than ele.
Store the index of ele as indexed_position.
Swap the element at indexed_position with the element at index smaller, effectively moving ele to its exact position.
Use a two-pointer approach to further rearrange the elements:
Initialize pointers first and last to the beginning and end of the array respectively.
Iterate through the array from first to smaller to find the first element greater than ele.
Iterate through the array from last to smaller to find the last element smaller than ele.
Swap the elements found by the pointers.
Continue swapping until first is less than last.
The elements are now rearranged as required.

Source Code:
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void exact_position(int * a,int n,int ele)
{
    int greater=0;
    int smaller=0;
    int indexed_position;
    for(int i=0;i<n;i++)
    {
        if(a[i]<ele)
        {
            smaller++;
        }
        else if(a[i]>ele)
        {
            greater++;
        }
        else
        {
            indexed_position=i;
        }
    }

    //swaping
    int t=a[indexed_position];
    a[indexed_position]=a[smaller];
    a[smaller]=t;

    int first=0;
    int last=n-1;
    int i;
    int j;
    while(first<last)
    {
        for(int i=first;i<smaller;i++)
        {
            if(a[i]>ele)
            {
                first=i;
                break;
            }
        }
        first=i;
        for(int j=n-1;j<smaller;j--)
        {
            if(a[j]<ele)
            {
                last=j;
                break;
            }
        }
        last=j;
        if(first<last)
        {
            int t=a[first];
            a[first]=a[last];
            a[last]=t;
        }
    }

    // for(int i=0;i<n;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
}

int main ()
{
    // Simple case for testing function
    // int a[6]={5,1,2,3,6,8};
    // exact_position(a,6,5);

    float A;

    for (int j = 10000; j <= 1000000; j += 10000)
    {
        int a[j];
        for(int k=0;k<j;k++){
            a[k]=rand()%2;
        }
        clock_t t1 = clock();
        long long t = 0;

        for (int x = 1; x <= 10; x++)
        {
            exact_position(a,j,a[10]);
        }

        clock_t t2 = clock();
        A = (float)(t2 - t1) / 10;
        cout << A<< ",";
    }
}
Time Complexity:
The time complexity is O(n), where n is the size of the array.
Here's why:
Looping Through the Array: The primary operation in both versions of the code involves iterating through the entire array once. This loop has a time complexity of O(n) since it scales linearly with the size of the array.
Swapping and Reordering: Within the loop, there are operations that involve swapping elements in the array based on certain conditions. However, these operations are still performed in linear time relative to the size of the array, contributing to the overall O(n) time complexity.
Therefore, regardless of whether it's the iterative or recursive version, the time complexity remains O(n) due to the linear nature of the operations performed on the array

PROGRAM 8
AIM: Write a program to merge two sorted lists into one list which should be sorted and also discuss it’s time complexity.

Algorithm:
Initialize three counters: count1 for list1, count2 for list2, and count3 for list3. Also, initialize an array list3 with size m + n to store the merged list.
While both list1 and list2 have elements remaining (i.e., count1 < n and count2 < m):
Compare the elements at indices count1 and count2.
If the element in list1 is smaller, copy it to list3 and increment count1 and count3.
Otherwise, copy the element in list2 to list3 and increment count2 and count3.
After the loop, if there are remaining elements in list1, copy them to list3.
Similarly, if there are remaining elements in list2, copy them to list3.
The merged list list3 now contains all elements from list1 and list2, sorted in ascending order.

Source Code:
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<random>
using namespace std;

void stl(int * list1,int * list2,int n,int m)
{
    int count1=0;
    int count2=0;
    int count3=0;
    int list3[m+n];

    while(count2<m&&count1<n)
    {
        if(list1[count1]<list2[count2])
        {
            list3[count3]=list1[count1];
            count1++;
            count3++;
        }
        else
        {
            list3[count3]=list2[count2];
            count2++;
            count3++;
        }
    }

    while(count1<n)
    {
        list3[count3]=list1[count1];
        count1++;
        count3++;        
    }

    while(count2<m)
    {
        list3[count3]=list2[count2];
        count2++;
        count3++;        
    }

    // If you want to print the resulting list then uncomment the below code
    // for(int i=0;i<n+n;i++)
    // {
    //     cout<<list3[i]<<" ";
    // }

}

int main()
{

    // Just a simple example for checking the code
    // int a[5]={1,5,7,9,12};
    // int b[5]={4,6,8,10,15};
    // stl(a,b,5,5);

    float A;

    random_device rd;
    mt19937 gen(rd());

    for (int j = 10000; j <= 1000000; j += 10000)
    {
        int *a = new int[j];
        int *b = new int[j/10];

        uniform_int_distribution<int> dist(1, 1000000);

        for (int k = 0; k < j; k++)
        {
            a[k] = dist(gen);
        }
        for (int k = 0; k < j/10; k++)
        {
            b[k] = dist(gen);
        }
        clock_t t1 = clock();
        int t = 0;

        for (int x = 1; x <= 10; x++)
        {
            stl(a,b,j,j/10);
        }

        clock_t t2 = clock();
        A = (float)(t2 - t1) / 10;
        cout << A*100<< ",";

        // free up the memory used
        delete[] a;
        delete[] b;
    }
}
Time Complexity:
The provided code segment merges two lists list1 and list2 into a third list list3 while maintaining ascending order. It iterates through both input lists simultaneously, comparing elements at corresponding positions and appending the smaller element to list3. If one list is exhausted before the other, it appends the remaining elements from the non-empty list to list3.

The time complexity of this code is O(n + m), where n represents the size of list1 and m represents the size of list2. This complexity arises from the linear traversal of both input lists to merge them into list3. The loop terminates once all elements from both lists are processed. Therefore, the efficiency of the algorithm scales linearly with the sizes of the input lists.

Additionally, within the main loop, the code runs the merging process multiple times to compute an average time. However, this repetition does not affect the time complexity; it only affects the constant factor in the time taken for execution. Therefore, the overall time complexity remains O(n + m) regardless of the number of iterations.

PROGRAM 9

AIM: Write a program to sort provided elements in array using quick sort and also discuss it’s time complexity.

Algorithm:
quick_sort:
This function recursively sorts the array a using the Quick Sort algorithm.
It takes an array a, starting index p, and ending index r as input parameters.
If p is less than r, indicating there are elements to be sorted:
It calls the partition function to find the partition index j.
It recursively calls quick_sort to sort the subarray to the left of j (from p to j-1) and the subarray to the right of j (from j+1 to r).

Source Code:
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
Time Complexity:
Worst-case time complexity:
In the worst-case scenario, Quick Sort performs poorly when it consistently selects the smallest or largest element as the pivot. This situation arises when the input array is already sorted (either in ascending or descending order) or when all elements are identical.
In such cases, Quick Sort makes uneven partitions, resulting in one partition containing all elements except the pivot. This leads to a recursive call with a smaller subarray on one side and the original array with one less element on the other side. Consequently, the algorithm ends up performing n-1 comparisons in each recursive call until the array is completely partitioned. This results in a time complexity of O(n^2).
Best-case time complexity:
In the best-case scenario, Quick Sort performs optimally when it consistently selects the median (or close to median) element as the pivot. This situation arises when the input array is randomly shuffled or when the pivot selection algorithm is designed to pick a good pivot.
In the best case, Quick Sort partitions the array into two nearly equal-sized subarrays with each recursive call. This results in a balanced recursion tree where each level divides the array into approximately half. As a result, the time complexity in the best case is O(n log n).
In summary:
Worst-case time complexity: O(n^2)
Best-case time complexity: O (n log n)
Overall, Quick Sort is highly efficient on average and in the best-case scenario, but its worst-case time complexity can be a concern, especially for certain types of input data. However, strategies such as randomized pivot selection and median-of-three pivot selection can mitigate this issue to a large extent.

PROGRAM 10
AIM: Write a program to sort provided elements in array using iterative quick sort using stack and also discuss it’s time complexity.

Algorithm:
Iterative:
This function implements the iterative Quick Sort algorithm using a stack.
It takes a stack s, an array arr, starting index p, and ending index r as input parameters.
If p is less than r, indicating there are elements to be sorted:
It calls the partition function to find the partition index j.
It checks if the left partition (p to j-1) is smaller than the right partition (j+1 to r).
Depending on which partition is smaller, it pushes the corresponding subarray indices onto the stack.
It repeats this process until the stack is empty.
At each iteration, it pops the top two indices from the stack and calls iterative recursively with those indices.
This ensures that the iterative process continues until all subarrays are sorted.

Source Code:
#include<iostream>
#include<stack>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cmath>
using namespace std;
int partition (int *arr, int p, int r)
{
    int x=arr[r];
    int i=p-1;
    for (int j=p;j<=r-1;j++)
    {
        if(arr[j]<x)
        {
            i++;
            int t=arr[j];
            arr[j]=arr[i];
            arr[i]=t;
        }
    }
    i++;
    int t=arr[r];
    arr[r]=arr[i];
    arr[i]=t;
    return i;
}

void iterative(stack<int>&s ,int * arr, int p,int r)
{
    if(p<r)
    {
        int j=partition(arr,p,r);
        if(p+j<r-j)
        {
            s.push(r);
            s.push(j+1);
        }
        else
        {
            s.push(j-1);
            s.push(p);
        }
        if(s.empty())
        {
            return;
        }
        else
        {
            int p=s.top();
            s.pop();
            int r=s.top();
            s.pop();
            iterative(s,arr,p,r);
        }
    }
}
int main()
{
    stack<int>s;
    // int arr[10]={9,5,1,4,2,6,3,7,8,10};
    // iterative(s,arr,0,9);
    // for(int i=0;i<10;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    // for(int j=1000;j<=100000;j=j+1000)
    // {
    //     cout<<j*log(j)/1000<<",";
    // }
    
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
            iterative(s,a,0,j-1);
        }
        clock_t t2=clock();
        A=(float)(t2-t1)/10;
        cout<<A<<",";
    }
}

Time Complexity:
The provided code iteratively implements the Quick Sort algorithm using a stack. It starts by partitioning the array based on a pivot, then pushes the indices of the resulting partitions onto the stack. It continues to partition and push indices onto the stack until the stack is empty. In each iteration, it selects a pivot and divides the array into two subarrays around the pivot.
Let's analyze the time complexity:
Partitioning: The partition function partitions the array into two subarrays. This operation takes linear time proportional to the size of the subarray being partitioned.
Iterative Approach: The iterative function iteratively partitions the array and pushes indices onto the stack until the stack is empty. In each iteration, it performs a constant number of operations and divides the array into smaller subarrays.
Overall, the time complexity of the iterative Quick Sort using a stack is O(n log n) in the average and best-case scenarios, where n is the size of the input array. This is because the partitioning process divides the array into approximately equal-sized subarrays in each iteration, leading to a balanced recursion tree. However, in the worst-case scenario, when the partitioning process creates highly unbalanced partitions, the time complexity can degrade to O(n^2), similar to the recursive version of Quick Sort.

PROGRAM 11
AIM: Write a program to sort provided elements in array using merge sort and also discuss it’s time complexity.

Algorithm:
Merge:
This function merges two sorted subarrays of a, one from index low to mid and the other from index mid+1 to high.
It creates a temporary array r to store the merged result.
It uses two pointers, left and right, to iterate through the two subarrays.
While both subarrays have elements remaining:
It compares the elements pointed to by left and right.
It copies the smaller element to the r array and advances the respective pointer.
If any subarray has remaining elements, it copies them to the r array.
Finally, it copies the merged result from r back to the original array a.
Mergesort:
This function recursively sorts the array a using the Merge Sort algorithm.
It takes an array a, starting index low, and ending index high as input parameters.
If low is less than high, indicating there are elements to be sorted:
It calculates the middle index mid.
It recursively calls mergesort to sort the subarray from low to mid.
It recursively calls mergesort to sort the subarray from mid+1 to high.
It calls the merge function to merge the two sorted subarrays.

Source Code:
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

void merge(int * a, int low, int mid, int high)
{
    int r[100];
    int count = low;
    int store = low;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (a[left] < a[right])
        {
            r[count] = a[left];
            left++;
        }
        else
        {
            r[count] = a[right];
            right++;
        }
        count++;
    }

    while (left <= mid)
    {
        r[count] = a[left];
        left++;
        count++;
    }

    while (right <= high)
    {
        r[count] = a[right];
        right++;
        count++;
    }

    for (int i = store; i <= high; i++)
    {
        a[i] = r[i];
    }
}


void mergesort(int * a,int low,int high)
{
    if(low<high)
    {
        int mid=(high+low)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main()
{
    //Sample case for example
    // int a[6]={6,5,4,3,2,1};
    // mergesort(a,0,5);
    // for(int i=0;i<6;i++)
    // {
    //     cout<<a[i]<<" ";
    // }

    for(int j=0;j<=100;j++)
    {
        cout<<j*log(j)<<",";
    }

    float A;
    for(int j=1;j<=100;j=j+1)
    {
        int a[j];
        for(int k=0;k<j;k++)
        {
            a[k]=rand();
        }
        clock_t t1=clock();
        for(int l=0;l<10;l++)
        {
            mergesort(a,0,j-1);
        }
        clock_t t2=clock();
        A=(float)(t2-t1)/10;
        cout<<A<<",";
    }
}
Time Complexity:
The time complexity of the provided iterative Quick Sort algorithm using a stack is O(n log n) in the average and best-case scenarios, where n is the size of the input array. This is because the algorithm efficiently partitions the array into smaller subarrays and sorts them recursively until they're of size 1. Each partitioning step takes linear time proportional to the size of the subarray being partitioned, and the number of recursive calls grows logarithmically with the size of the input array.
This time complexity is comparable to that of Merge Sort, which also has a time complexity of O(n log n). However, Merge Sort has the advantage of being a stable sorting algorithm and has a consistent performance regardless of the input data, while Quick Sort can degrade to O(n^2) in the worst-case scenario if poorly implemented or if the input data is already sorted.
Overall, both algorithms are efficient for sorting large datasets and have the same time complexity in the average and best-case scenarios. However, Merge Sort may be preferred in scenarios where stability or worst-case performance is crucial.

PROGRAM 12
AIM: Write a program to find minimum and maximum element from the provided elements of array both recursively and iteratively and also discuss it’s time complexity.

Algorithm:
Iterative_min_max:
This function iterates through the array a to find the minimum and maximum elements.
It initializes variables min and max with the first element of a.
It iterates through the array, updating min and max if a smaller or larger element is found, respectively.
min_max:
This function recursively finds the minimum and maximum elements in the subarray a[low:high].
If low is equal to high, indicating a single-element subarray, it returns a pair with that element as both the minimum and maximum.
Otherwise, it divides the array into two halves and recursively calls min_max on each half.
It then compares the minimums and maximums of the two halves and returns a pair containing the overall minimum and maximum.

Source Code:
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<map>
using namespace std;
void iterative_min_max(int *a,int n)
{
    int min=a[0];
    int max=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    // cout<<"Minimum = "<<min<<endl;
    // cout<<"Maximum = "<<max<<endl;
}

pair<int,int> min_max(int * a,int low,int high)
{
    if(low==high)
    {
        return make_pair(a[low],a[high]);
    }
    else
    {
        int mid=(low+high)/2;
        pair<int,int> p1 = min_max(a,low,mid);
        pair<int,int> p2 = min_max(a,mid+1,high);
        int mi=p1.first;
        int ma=p1.second;

        if(p1.first>p2.first)
        {
            mi=p2.first;
        }
        if(p1.second<p2.second)
        {
            ma=p2.second;
        }
        return make_pair(mi,ma);
    }
}

int main()
{
    // int a[6]={1,5,5,2,6,3};
    // pair<int,int>p=min_max(a,0,5);
    // cout<<"MINIMUM = "<<p.first<<"\n"<<"MAXIMUM = "<<p.second<<"\n";


    // Recursive calls
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
            pair<int,int>p=min_max(a,0,j-1);
        }
        clock_t t2=clock();
        A=(float)(t2-t1)/10;
        cout<<A<<",";
    }

    cout<<"Done"<<endl;

    //Iterative calss
    float A1;
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
            iterative_min_max(a,j);
        }
        clock_t t2=clock();
        A1=(float)(t2-t1)/10;
        cout<<A1<<",";
    }
}
Time Complexity:
Recursive Approach:
In the recursive version, the function min_max recursively divides the array into halves until reaching base cases, where the array size is 1. At each level of recursion, it computes the minimum and maximum elements of the subarrays and merges them to obtain the minimum and maximum of the entire array. The recursion depth is logarithmic with respect to the size of the input array since the array is divided into halves at each recursive call.
The time complexity of the recursive approach is O(n*logn), where n is the size of the input array. This is because each element of the array is visited only once during the recursive calls, and the number of recursive calls is proportional to the logarithm of the size of the array.
Iterative Approach:
In the iterative version, the function iterative_min_max iterates through the array once to find the minimum and maximum elements. It initializes variables min and max with the first element of the array and updates them as it traverses the array. This approach performs a linear scan of the array, visiting each element once.
The time complexity of the iterative approach is also O(n), where n is the size of the input array. This is because it iterates through the array once, performing a constant number of operations for each element.
In summary, both the recursive and iterative approaches to finding the minimum and maximum elements of an array have a time complexity of O(n), making them equally efficient for this task. However, the recursive approach may have slightly higher overhead due to recursive function calls, while the iterative approach may be more straightforward and easier to understand.

PROGRAM 13
AIM: Write a program to implement binary search and also discuss it’s time complexity.

Algorithm:
Initialize variables first to 0 and last to n-1 to represent the range of indices to search within the array.
Calculate the initial value of mid as the index halfway between first and last.
Enter a loop that continues as long as first is less than last.
Within the loop:
Update the value of mid as (first + last) / 2.
Check if the element at index mid is equal to ele. If it is, return true, indicating that the element is found.
If the element at index mid is less than ele, update first to mid + 1 to search in the right half of the array.
If the element at index mid is greater than ele, update last to mid - 1 to search in the left half of the array.
If the loop exits without finding the element, return false, indicating that the element is not present in the array.

Source Code:
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool bs(int *arr,int n,int ele)
{
    int first=0;
    int last=n-1;
    int mid=(first+last)/2;
    while(first<last)
    {
        mid=(first+last)/2;
        if(arr[mid]==ele)
        {
            return true;
        }
        else if(arr[mid]<ele)
        {
            first=mid+1;
        }
        else if(arr[mid]>ele)
        {
            last=mid-1;
        }
    }
    return false;
}

int main(){

    float A;
    for(int j=1000;j<=100000;j=j+1000){
        int a[j];
        for(int k=0;k<j;k++){
            a[k]=rand()%j;
        }
        clock_t t1=clock();
        for(int x=1;x<=100;x++){
            bool t=bs(a,j,rand());
        }
        clock_t t2=clock();
        A=(float)(t2-t1)/100;
        cout<<A<<",";
        free(a);
    }
}
Time Complexity:
Binary search is a highly efficient searching algorithm that operates on sorted arrays or lists by repeatedly dividing the search interval in half. The time complexity of binary search is O(log n), where 'n' represents the number of elements in the array. This logarithmic time complexity indicates that the algorithm can efficiently locate a target value by halving the search space in each step. As a result, binary search is particularly effective for large datasets, as the number of elements that need to be examined decreases exponentially with each comparison.
The binary search algorithm works by comparing the target value with the middle element of the array. If the target value is equal to the middle element, the search is successful. Otherwise, if the target value is less than the middle element, the search continues in the lower half of the array; if it is greater, the search continues in the upper half. This process repeats until the target value is found or the search interval is empty.
Binary search's efficiency makes it a preferred choice for searching in sorted collections, especially when dealing with large datasets where performance is crucial. However, it's important to note that binary search requires the data to be sorted beforehand, which may incur additional preprocessing time. Despite this requirement, binary search's O(log n) time complexity offers significant advantages over linear search, particularly as the size of the dataset grows.

PROGRAM 14
AIM: Implement knabsack problem and also discuss it’s time complexity.

Algorithm:
knapsackprice:
This function aims to maximize the total price of items selected while ensuring that the total weight does not exceed the maximum weight limit.
It sorts the items by their price in ascending order and then selects items greedily based on their price until either all items are selected or the weight limit is reached.
It returns the total price of the selected items.
knapsackweight:
This function aims to maximize the total weight of items selected while ensuring that the total weight does not exceed the maximum weight limit.
It sorts the items by their weight in ascending order and then selects items greedily based on their weight until either all items are selected or the weight limit is reached.
It returns the total weight of the selected items.
knapsackweightprice:
This function aims to maximize the ratio of price to weight (value density) of items selected while ensuring that the total weight does not exceed the maximum weight limit.
It calculates the value density for each item and sorts the items by their value density in ascending order.
It selects items greedily based on their value density until either all items are selected or the weight limit is reached.
It returns the total price of the selected items.

Source Code:
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
using namespace std;
float knabsackprice(int** mat,int rows,int cols,int maxweight)
{
    int j;
    for(int i=0;i<5;i++)
    {
        j=i;
        for(int k=i+1;k<5;k++)
        {
            if(mat[0][k]<mat[0][j])
            {
                j=k;
            }
        }
        int t=mat[0][i];
        mat[0][i]=mat[0][j];
        mat[0][j]=t;
        int tn=mat[1][i];
        mat[1][i]=mat[1][j];
        mat[1][j]=tn;
    }

    // for(int i=0;i<rows;i++)
    // {
    //     for(int j=0;j<cols;j++)
    //     {
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    float x[5]={0};
    int i;
    for(i=4;i>=0;i--)
    {
        if(mat[1][i]<=maxweight && maxweight>0)
        {
            maxweight-=mat[1][i];
            x[i]=1;
        }
        else
        {
            break;
        }
    }

    if(i>=0)
    {
        x[i] =  float (maxweight)/(mat[1][i]);
    }

    // for(int i=0;i<5;i++)
    // {
    //     cout<<x[i]<<" ";
    // }

    float sum=0.0;

    for(i=0;i<5;i++)
    {
        sum+=mat[0][i]*x[i];
    }

    return sum;
}

float knabsackweight(int** mat,int rows,int cols,int maxweight)
{
    int j;
    for(int i=0;i<5;i++)
    {
        j=i;
        for(int k=i+1;k<5;k++)
        {
            if(mat[1][k]<mat[1][j])
            {
                j=k;
            }
        }
        int t=mat[1][i];
        mat[1][i]=mat[1][j];
        mat[1][j]=t;
        int tn=mat[0][i];
        mat[0][i]=mat[0][j];
        mat[0][j]=tn;
    }

    // for(int i=0;i<rows;i++)
    // {
    //     for(int j=0;j<cols;j++)
    //     {
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    float x[5]={0};
    int i;
    for(i=0;i<5;i++)
    {
        if(mat[1][i]<=maxweight && maxweight>0)
        {
            maxweight-=mat[1][i];
            x[i]=1;
        }
        else
        {
            break;
        }
    }

    if(i<5)
    {
        x[i] =  maxweight/float(mat[1][i]);
    }

    // for(int i=0;i<5;i++)
    // {
    //     cout<<x[i]<<" ";
    // }

    float sum=0.0;

    for(i=0;i<5;i++)
    {
        sum+=float (mat[0][i])*float(x[i]);
    }

    return sum;
}

float knabsackweightprice(int** mat,int rows,int cols,int maxweight)
{
    float h[5];
    for(int p=0;p<5;p++)
    {
        h[p]=float (mat[0][p])/mat[1][p];
    }

    // for(int i=0;i<5;i++)
    // {
    //     cout<<h[i]<<" ";
    // }
    // cout<<endl;

    int j;
    for(int i=0;i<5;i++)
    {
        j=i;
        for(int k=i+1;k<5;k++)
        {
            if(h[k]<h[j])
            {
                j=k;
            }
        }
        int t=h[i];
        h[i]=h[j];
        h[j]=t;
        int tn=mat[1][i];
        mat[1][i]=mat[1][j];
        mat[1][j]=tn;
        int tnn=mat[0][i];
        mat[0][i]=mat[0][j];
        mat[0][j]=tnn;
    }

    // for(int i=0;i<rows;i++)
    // {
    //     for(int j=0;j<cols;j++)
    //     {
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    float x[5]={0};
    int i;
    for(i=4;i>=0;i--)
    {
        if(mat[1][i]<=maxweight && maxweight>0)
        {
            maxweight-=mat[1][i];
            x[i]=1;
        }
        else
        {
            break;
        }
    }

    if(i>=0)
    {
        x[i] =  float (maxweight)/(mat[1][i]);
    }

    // for(int i=0;i<5;i++)
    // {
    //     cout<<x[i]<<" ";
    // }

    float sum=0.0;

    for(i=0;i<5;i++)
    {
        sum+=mat[0][i]*x[i];
    }

    return sum;

}

int main()
{
    // int i=0;
    // int maxweight=10;

    // while(i<3)
    // {
    //     int mat[2][5]={{5,8,10,6,7},{2,3,4,3,2}};
    //     if(i==0)
    //     {
    //         float pp = knabsackprice(mat,2,5,10);
    //         cout<<endl<<"Profit = "<<pp<<endl;
    //     }
    //     if(i==1)
    //     {
    //         float wp = knabsackweight(mat,2,5,10);
    //         cout<<endl<<"Weight = "<<wp<<endl;
    //     }
    //     if(i==2)
    //     {
    //         float wpp = knabsackweightprice(mat,2,5,10);
    //         cout<<endl<<"Profit by weight = "<<wpp<<endl;
    //     }
    //     i++;
    // }

    
    float A;
    for(int j=1000;j<=100000;j=j+1000)
    {
        int** a = new int*[2];
        int** mat = new int*[2];

        for(int i = 0; i < 2; i++) {
            a[i] = new int[j];
            mat[i] = new int[j];
        }

        for(int k=0;k<j;k++)
        {
            a[0][k]=rand();
            a[1][k]=rand();
        }
        clock_t t1=clock();
        for(int l=0;l<10;l++)
        {
            
            int i=0;
            int maxweight=10;

            while(i<3)
            {
                for(int i = 0; i < 2; i++) {
                    for(int m = 0; m < j; m++) {
                        mat[i][m] = a[i][m];
                    }
                }

                if(i==0)
                {
                    float pp = knabsackprice(mat,2,j,maxweight);
                    // cout<<endl<<"Profit = "<<pp<<endl;
                }
                if(i==1)
                {
                    float wp = knabsackweight(mat,2,j,maxweight);
                    // cout<<endl<<"Weight = "<<wp<<endl;
                }
                if(i==2)
                {
                    float wpp = knabsackweightprice(mat,2,j,maxweight);
                    // cout<<endl<<"Profit by weight = "<<wpp<<endl;
                }
                i++;
            }

        }
        clock_t t2=clock();
        A=(float)(t2-t1)/10;
        cout<<A<<",";

        for(int i = 0; i < 2; i++) {
            delete[] a[i];
            delete[] mat[i];
        }
        delete[] a;
        delete[] mat;
    }
}

Time Complexity:
In the dynamic programming approach for the knapsack problem, the time complexity depends on the number of items ('n') and the capacity of the knapsack ('W'). This approach involves filling up a 2D array to store the maximum value that can be achieved for various subproblems.
The time complexity of the dynamic programming approach for the 0/1 knapsack problem can be expressed as O(nW), where 'n' is the number of items and 'W' is the capacity of the knapsack.
Here's a brief explanation of how this time complexity is derived:

The algorithm considers all possible combinations of items and capacities. For each item 'i' (from 1 to 'n') and each possible capacity 'w' (from 0 to 'W'), it computes the maximum value that can be achieved considering only the first 'i' items and a knapsack capacity of 'w'. This involves filling up a 2D array with the maximum values.
The dimensions of this 2D array are 'n+1' (for the items) and 'W+1' (for the capacities). Therefore, the total number of elements in the table is (n+1) * (W+1), leading to O(nW) time complexity.
For each cell of the table, the algorithm requires constant time to compute the maximum value based on the values stored in previously computed cells.
Therefore, the overall time complexity is proportional to the number of cells in the table, which is O(nW).
In practical terms, the dynamic programming approach for the knapsack problem is highly efficient compared to brute-force methods, especially when the number of items and the capacity of the knapsack are not too large. However, the time complexity can become significant for very large instances of the problem, especially if the capacity of the knapsack is large. Nevertheless, dynamic programming provides an optimal solution to the knapsack problem with a manageable time complexity for most real-world instances.

PROGRAM 15
AIM: Write a program to implement activity status problem and also discuss it’s time complexity.

Algorithm:
endtime function:
This function takes a 2D array mat, representing job start and end times, as well as start and end floats representing the start and end times of the interval, as input parameters.
It initializes a variable jobs to count the number of jobs that fall within the given time interval.
It iterates through the columns of the mat array, where each column represents a job.
For each job, it checks if the start time (mat[0][j]) is greater than or equal to the given start time and if the end time (mat[1][j]) is less than or equal to the given end time.
If both conditions are met, it increments the jobs counter.
Finally, it returns the total number of jobs that fall within the given time interval.

Source Code:
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

int endtime(float **mat, int rows, int cols, float start, float end) {
    int jobs = 0;
    for (int j = 0; j < cols; j++) {
        if (mat[0][j] >= start && mat[1][j] <= end) {
            jobs++;
        }
    }
    return jobs;
}

int main() {
    float start = 9.0;
    float end = 17.0;

    float A;
    for (int j = 1000; j <= 100000; j += 1000) {
        float** a = new float*[2];
        for (int i = 0; i < 2; i++) {
            a[i] = new float[j];
            for (int k = 0; k < j; k++) {
                // Generate random floating-point numbers between start and end
                a[i][k] = start + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(end-start)));
            }
        }

        clock_t t1 = clock();
        for (int l = 0; l < 10; l++) {
            endtime(a, 2, j, start, end);
        }
        clock_t t2 = clock();
        A = (float)(t2 - t1) / 10;
        cout << A << ",";
        
        // Free dynamically allocated memory
        for (int i = 0; i < 2; i++) {
            delete[] a[i];
        }
        delete[] a;
    }
}

Time Complexity:
The time complexity of this code mainly revolves around two aspects: memory allocation and the execution of the endtime function.
Memory Allocation: Inside the main loop, memory is dynamically allocated for a 2D array a to represent job start and end times. The allocation occurs for each size of the input matrix, scaling with the total number of elements in the matrix. Therefore, the time complexity of memory allocation is proportional to the total number of elements, which is O(n), where 'n' represents the size of the input matrix.
Execution of endtime Function: The endtime function iterates through each job in the input matrix to check if it falls within the specified time frame. Since it iterates through each column of the input matrix, the time complexity of this function is linear with respect to the number of columns in the matrix. Therefore, it has a time complexity of O(cols), where 'cols' is the number of columns in the input matrix.
Combining these complexities, the overall time complexity of the provided code is primarily determined by the memory allocation step, which is O(n) due to dynamically allocating memory for the input matrices. Other operations such as random number generation and time measurement, while present in the code, have constant or negligible impact on the overall time complexity compared to memory allocation.

PROGRAM 16
AIM: To implement single source shortest path algo and also discuss it’s time complexity.

Algorithm:
addedge:
This function adds an edge between two vertices u and v in the graph and initializes the weight for the edge by taking user input.
printadjlist:
This function prints the adjacency list representation of the graph.
printresultlist:
This function prints the result list representation of the graph. It seems like it's intended to print some intermediate result, but the purpose is not clearly defined in the provided code.
printweightmatrix:
This function prints the weight matrix of the graph.
dijkstraalgo:
This function implements Dijkstra's algorithm to find the shortest paths from a given source vertex to all other vertices in the graph.
It initializes data structures for maintaining visited vertices, distances, and results.
It iteratively selects the vertex with the minimum distance from the source, updates distances, and marks vertices as visited until all vertices are visited.
However, there are some issues and potential improvements in the provided code:
The addedge function takes input for the weight of the edge from the user, which might not be appropriate within the class definition. It's generally better to provide weights directly as function parameters or through another method.
The printresultlist function seems to print some intermediate results, but its purpose is not clear. It should be documented or removed if not needed.
The dijkstraalgo function uses a fixed size for initialization and processing, which might not be appropriate for graphs of varying sizes.
There's an inconsistency in the size of the weight matrix (arr) and the size of the adjacency list (adj).
The termination condition in the dijkstraalgo function is based on counting unvisited vertices, which could potentially lead to an infinite loop if there's a disconnect in the graph.

Source Code:
#include<iostream>
#include<map>
#include<list>
#include<stack>
using namespace std;
class graph
{
    public:
    map<int,list<int>>adj;
    map<int,list<int>>result;
    int arr[6][6]={0};


    void addedge(int u,int v)
    {
        adj[u].push_back(v);
        int w;
        cin>>w;
        arr[u][v]=w;
    }

    void printadjlist()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

    void printresultlist()
    {
        for(auto i:result)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

    void printweightmatrix()
    {
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    void dijkstraalgo(int source)
    {
        map<int,bool>visited;
        for(auto i:adj)
        {
            visited[i.first]=false;
        }
        visited[source]=true;
        result[source].push_back(0);


        
        map<int,int>dist;

        for(auto i:adj)
        {
            dist[i.first]=1000;
        }

        for(auto i:adj)
        {
            if(i.first==source)
            {
                for(auto j:i.second)
                {
                    if(visited[j]==false)
                    {
                        dist[j]=arr[i.first][j];
                    }
                }
            }
        }


        while(true)
        {

            int count=0;
            for(auto j:visited)
            {
                if(visited[j.first]==false)
                {
                    count++;
                }
            }
            if(count==0)
            {
                return;
            }

            int mini=100;
            int j;
            for(auto k:dist)
            {
                if(visited[k.first]==false)
                {
                    if(mini>dist[k.first])
                    {
                        mini=dist[k.first];
                        j=k.first;
                    }
                }
            }

            visited[j]=true;
            result[j].push_back(dist[j]);
            source=j;

            for(auto i:adj)
            {
                if(i.first==source)
                {
                    for(auto j:i.second)
                    {
                        if(j==-1)
                        {
                            continue;
                        }
                        if(dist[j]>dist[i.first]+arr[i.first][j])
                        {
                            dist[j]=dist[i.first]+arr[i.first][j];
                        }
                    }
                }
            }

        }

    }

};
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;

    graph g;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        g.addedge(u,v);
    }
    g.printadjlist();
    g.printweightmatrix();
    g.dijkstraalgo(0);
    cout<<"Result matrix is:\n";
    g.printresultlist();
}
Time Complexity:
Dijkstra's algorithm is a graph search algorithm used to find the shortest path from a source vertex to all other vertices in a weighted graph with non-negative edge weights. The time complexity of Dijkstra's algorithm depends on the data structure used to implement it and the specific implementation details. However, the most commonly used implementation of Dijkstra's algorithm uses a priority queue (usually implemented with a binary heap or Fibonacci heap) to efficiently select the vertex with the minimum distance.
The overall time complexity of Dijkstra's algorithm using a binary heap priority queue can be expressed as O((V + E) log V), where 'V' is the number of vertices and 'E' is the number of edges in the graph.
Here's a breakdown of the time complexity:
Initialization: Initializing the data structures such as the priority queue and distance array for each vertex takes O(V) time.
Main Loop: The main loop of Dijkstra's algorithm runs once for each vertex in the graph. In each iteration, it extracts the vertex with the minimum distance from the priority queue (which takes O(log V) time), relaxes all outgoing edges from this vertex (which takes O(E) time in total), and updates the distances of adjacent vertices accordingly. Since this loop runs once for each vertex and involves updating distances for all adjacent vertices, its total time complexity is O((V + E) log V).

Total Complexity: Combining the initialization step with the main loop, the overall time complexity of Dijkstra's algorithm using a binary heap priority queue is O((V + E) log V).
It's important to note that the time complexity can vary depending on the specific implementation details and the data structures used. For example, using a Fibonacci heap as the priority queue can potentially improve the time complexity to O(V log V + E). However, in practice, binary heaps are more commonly used due to their simpler implementation and better constant factors for most scenarios.

PROGRAM 17

AIM: Write a program to implement prims algorithm and also discuss it’s time complexity.

Algorithm:
Prim(graph, source):
    Initialize a priority queue pq.
    Add source vertex to the priority queue with weight 0.
    Initialize an empty set visited to keep track of visited vertices.
    Initialize an empty list mst to store the edges of the minimum spanning tree.

    while pq is not empty:
        u, w = extract_min(pq)  // Extract vertex with minimum weight
        if u is not in visited:
            Add u to visited.
            Add edge (u, w) to mst.
            for each vertex v adjacent to u:
                if v is not in visited:
                    Add edge (u, v) with weight w to pq.

    return mst

Source Code:
//prim
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};


struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second > b.second;
    }
};

// Prim's algorithm
vector<Edge> prim(vector<vector<Edge>>& graph, int source, int& total_weight) {
    int n = graph.size();
    vector<Edge> mst; 
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    visited[source] = true;
    for (const Edge& e : graph[source])
        pq.push({e.to, e.weight});

    
    while (!pq.empty()) {
        int u = pq.top().first;
        int w = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        mst.push_back(Edge(u, w));
        total_weight += w;

        for (const Edge& e : graph[u]) {
            if (!visited[e.to])
                pq.push({e.to, e.weight});
        }
    }

    return mst;
}

int main() {
    vector<vector<Edge>> graph(6);

    // Adding edges to the graph
    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 5));
    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));
    graph[1].push_back(Edge(4, 6));
    graph[2].push_back(Edge(4, 3));
    graph[3].push_back(Edge(5, 9));
    graph[4].push_back(Edge(5, 4));

    int source = 0; 
    int total_weight = 0;

    
    vector<Edge> minimum_spanning_tree = prim(graph, source, total_weight);

    cout << "Edges of the minimum spanning tree:\n";
    for (const Edge& e : minimum_spanning_tree)
        cout << source << " - " << e.to << " (weight " << e.weight << ")\n";

 
    cout << "Total weight of the minimum spanning tree: " << total_weight << endl;

    return 0;
}
Time Complexity:
Prim's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a weighted undirected graph. Its time complexity depends on the data structures used to implement it. In this implementation, a priority queue is utilized to efficiently select the next edge with the minimum weight.

The time complexity of Prim's algorithm with a priority queue is typically O((V + E) log V), where V is the number of vertices and E is the number of edges in the graph. This complexity arises from the fact that each vertex is added to the priority queue once, and each edge is potentially processed once during the execution of the algorithm. The priority queue operations, such as insertion and extraction of the minimum element, take O(log V) time, and they are performed for each vertex and edge.

However, in the worst-case scenario where the graph is dense (i.e., E = Θ(V^2)), the time complexity can be simplified to O(V^2 log V). This occurs because, in such graphs, the number of edges dominates the number of vertices, and hence the overall time complexity becomes quadratic in terms of the number of vertices.

Overall, Prim's algorithm is efficient for finding the minimum spanning tree, especially when implemented with a priority queue, providing a reasonable time complexity even for large graphs.

PROGRAM 18

AIM: Write a program to implement kruskal’s algorithm and also discuss it’s time complexity.

Algorithm:
Kruskal(graph):
    Sort all edges of graph G in non-decreasing order of weight.
    Initialize an empty set mst to store the edges of the minimum spanning tree.
    Initialize a disjoint-set data structure.

    for each edge (u, v) in the sorted edges:
        if adding edge (u, v) to mst does not form a cycle:
            Add edge (u, v) to mst.
            Merge the sets containing u and v in the disjoint-set data structure.

        if size of mst equals V - 1:  // V is the number of vertices
            break

    return mst

Source Code:
//kruskal algo
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

struct DisjointSets {
    vector<int> parent;
    DisjointSets(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int u, int v) {
        parent[find(u)] = find(v);
    }
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Kruskal's algorithm
vector<Edge> kruskal(vector<Edge>& edges, int n, int& total_weight) {
    vector<Edge> mst; 
    DisjointSets ds(n);
    total_weight = 0;

    sort(edges.begin(), edges.end(), compareEdges);

    Edge min_edge(-1, -1, numeric_limits<int>::max());

    
    for (const Edge& e : edges) {
       
        if (ds.find(e.from) == ds.find(e.to))
            continue;

        mst.push_back(e);
        ds.merge(e.from, e.to);
        total_weight += e.weight;

      
        if (e.weight < min_edge.weight)
            min_edge = e;
    }

    cout << "Minimum weight edge in the MST: " << min_edge.from << " - " << min_edge.to << " (weight " << min_edge.weight << ")\n";

    return mst;
}

int main() {
    
    int n = 6; 
    vector<Edge> edges = {
        Edge(0, 1, 2),
        Edge(0, 2, 5),
        Edge(1, 2, 1),
        Edge(1, 3, 7),
        Edge(1, 4, 6),
        Edge(2, 4, 3),
        Edge(3, 5, 9),
        Edge(4, 5, 4)
    };

    int total_weight;
    vector<Edge> minimum_spanning_tree = kruskal(edges, n, total_weight);

    cout << "Edges of the minimum spanning tree:\n";
    for (const Edge& e : minimum_spanning_tree)
        cout << e.from << " - " << e.to << " (weight " << e.weight << ")\n";

    cout << "Total weight of the minimum spanning tree: " << total_weight << endl;

    return 0;
}
Time Complexity:
The time complexity of Kruskal's algorithm depends on the sorting of edges and the disjoint-set data structure operations:

Sorting Edges: Sorting all the edges initially takes O(E log E) time, where E is the number of edges.

Disjoint-Set Operations:

The algorithm performs up to O(E) find and union operations on the disjoint-set data structure.
Using a union-find data structure, the time complexity of these operations can be amortized to nearly O(1) with appropriate optimizations.
Overall, the time complexity of Kruskal's algorithm is dominated by the sorting step, making it O(E log E). However, for sparse graphs where E is significantly smaller than V^2, this can be simplified to O(E log V). Kruskal's algorithm is efficient and suitable for a wide range of graph sizes and densities.

PROGRAM 19

AIM: Write a program to implement matrix multiplication recursively and also discuss it’s time complexity.
Algorithm:
WriteDataToFile:
This function writes data to a file named "data.txt" in the format "i, avgTime" where i is an integer and avgTime is a double.
WriteToFile:
Similar to WriteDataToFile, this function writes data to a file named "data1.txt" in the format "i, avgTime".
add_matrices:
This function takes two matrices A and B as input and returns their sum as a new matrix.
combine_matrices:
This function takes four submatrices C11, C12, C21, and C22 as input and combines them into a larger matrix.
matrix_multiply:
This function implements the Strassen's algorithm for matrix multiplication. It recursively divides the matrices into smaller submatrices until they reach a base case, and then combines the results using the Strassen's algorithm.
print_matrix:
This function prints a matrix to the console.
initialize_random_matrix:
This function initializes a matrix with random values.
complexity:
This function is used to generate complexity data. It iterates over a range of values for i (from 2 to 200, doubling i at each iteration), calculates the corresponding complexity n (i^3), and writes i and n to a file using WriteToFile.

Source Code:
#include<iostream>
#include<fstream>
#include<time.h>
#include<vector>
using namespace std;

void WriteDataToFile(int i, double avgTime){
    ofstream fout("data.txt", ios::app);
    if(fout.is_open()){
        fout<<i<<","<<avgTime<<endl;
        fout.close();
    }
    else{
        cout<<"Unable to open file for writing data. "<<endl;
    }
}

void WriteToFile(int i, double avgTime){
    ofstream fout("data1.txt", ios::app);
    if(fout.is_open()){
        fout<<i<<","<<avgTime<<endl;
        fout.close();
    }
    else{
        cout<<"Unable to open file for writing data. "<<endl;
    }
}

typedef vector<vector<int>> Matrix;

Matrix add_matrices(const Matrix& A, const Matrix& B){
    int n = A.size();
    int m = A[0].size();
    Matrix result(n, vector<int>(m,0));

    for(int i=0;i<n;++i){
        for(int j=0;j<m;j++){
            result[i][j]=A[i][j]+B[i][j];
        }
    }
    return result;
}

Matrix combine_matrices(const Matrix& C11, const Matrix& C12, const Matrix& C21, const Matrix& C22){
    int n = C11.size();
    int m = C11[0].size();
    Matrix result(2*n,vector<int>(2*m,0));

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            result[i][j]=C11[i][j];
            result[i][j+m]=C12[i][j];
            result[i+n][j]=C21[i][j];
            result[i+n][j+m]=C22[i][j];
        }
    } 
    return result;
}

Matrix strassen_multiply(const Matrix& A,const Matrix& B){
    int n = A.size();
    if(n == 1){
        return {{A[0][0]*B[0][0]}};
    }

    int newSize = n / 2;

    Matrix A11(newSize, vector<int>(newSize));
    Matrix A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize));
    Matrix A22(newSize, vector<int>(newSize));

    Matrix B11(newSize, vector<int>(newSize));
    Matrix B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize));
    Matrix B22(newSize, vector<int>(newSize));

    // Partitioning input matrices into submatrices
    for(int i = 0; i < newSize; ++i){
        for(int j = 0; j < newSize; ++j){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Strassen's matrix multiplication steps
    Matrix P1 = strassen_multiply(add_matrices(A11, A22), add_matrices(B11, B22));
    Matrix P2 = strassen_multiply(add_matrices(A21, A22), B11);
    Matrix P3 = strassen_multiply(A11, add_matrices(B12, B22));
    Matrix P4 = strassen_multiply(A22, add_matrices(B21, B11));
    Matrix P5 = strassen_multiply(add_matrices(A11, A12), B22);
    Matrix P6 = strassen_multiply(add_matrices(A21, A11), add_matrices(B11, B12));
    Matrix P7 = strassen_multiply(add_matrices(A12, A22), add_matrices(B21, B22));

    // Calculating submatrices of the result
    Matrix C11 = add_matrices(add_matrices(P1, P4), add_matrices(P7, P5));
    Matrix C12 = add_matrices(P3, P5);
    Matrix C21 = add_matrices(P2, P4);
    Matrix C22 = add_matrices(add_matrices(P1, P3), add_matrices(P6, P2));

    // Combining submatrices to get the result
    return combine_matrices(C11, C12, C21, C22);
}

void print_matrix(const Matrix& mat) {
    for (size_t i = 0; i < mat.size(); ++i) {
        for (size_t j = 0; j < mat[i].size(); ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void initialize_random_matrix(Matrix& c,int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            c[i][j]=rand();
        }
    }
}

void complexity(){
    for(int i=2;i<200;i=2*i){
        int n=i*i*i;
        WriteToFile(i,n);
    }
}

int main(){
    double avgtime,time1,time2;
    for(int i=2;i<200;i=2*i){
        Matrix A(i,vector<int>(i,0));
        Matrix B(i,vector<int>(i,0));

        initialize_random_matrix(A,i);
        initialize_random_matrix(B,i);
        time1=(double)clock();
        for(int j=0;j<10;j++){
            Matrix result = strassen_multiply(A,B);
            // print_matrix(result);
        }
        time2=(double)clock();
        avgtime=(double)(time2-time1)/10;
        cout<<avgtime<<" ";
        WriteDataToFile(i,avgtime*500);
    }
    complexity();
    return 0;
}

Time Complexity:
Matrix Multiplication (Lines 70-85):
The matrix_multiply function recursively multiplies two matrices A and B of size n x n.
At each level of recursion, the matrices are divided into smaller submatrices, resulting in a total of log₂(n) levels of recursion.
Within each recursive call, there are a total of 8 recursive calls, each operating on matrices of size n/2 x n/2.
Therefore, the time complexity of this recursive matrix multiplication can be expressed as T(n) = 8T(n/2) + O(n²), where O(n²) represents the work done in combining submatrices and base cases.
Initialization (Lines 89-94):

Two matrices A and B of size i x i are initialized with random values. This initialization process has a time complexity of O(i^2).
Average Time Measurement (Lines 95-106):

The code measures the average time taken for 10 iterations of matrix multiplication for each value of i in the range [2, 198] (doubling i at each iteration).
The measured time is divided by 10 to obtain the average time per iteration.
Writing Data to Files (Lines 8-31):

The code writes the data (values of i and corresponding average times) to two files, 'data.txt' and 'data1.txt', for further analysis.
Complexity Function (Lines 107-119):

This function writes data to a file for complexity analysis.
The recursive algorithm follows the Master Theorem, where the time complexity is O(n^log₂(8)) = O(n³) since the number of subproblems is 8 and the work done on each subproblem is O(n²).

PROGRAM 20
AIM: Write a program to implement strasson’s algorithm and also discuss it’s time complexity.

Algorithm:
function Strassen(A, B):
    if A and B are small matrices:
        return standard matrix multiplication of A and B
    
    Divide matrices A and B into submatrices A11, A12, A21, A22 and B11, B12, B21, B22
    
    Calculate seven auxiliary matrices P1, P2, ..., P7 using the formulas mentioned above
    
    Recursively compute submatrices C11, C12, C21, C22 using the formulas for combining P1, ..., P7
    
    Combine submatrices C11, C12, C21, C22 into the resulting matrix C
    
    return C

Source Code:
#include<iostream>
#include<fstream>
#include<time.h>
#include<vector>
using namespace std;

void WriteDataToFile(int i, double avgTime){
    ofstream fout("data.txt", ios::app);
    if(fout.is_open()){
        fout<<i<<","<<avgTime<<endl;
        fout.close();
    }
    else{
        cout<<"Unable to open file for writing data. "<<endl;
    }
}

void WriteToFile(int i, double avgTime){
    ofstream fout("data1.txt", ios::app);
    if(fout.is_open()){
        fout<<i<<","<<avgTime<<endl;
        fout.close();
    }
    else{
        cout<<"Unable to open file for writing data. "<<endl;
    }
}

typedef vector<vector<int>> Matrix;

Matrix add_matrices(const Matrix& A, const Matrix& B){
    int n = A.size();
    int m = A[0].size();
    Matrix result(n, vector<int>(m,0));

    for(int i=0;i<n;++i){
        for(int j=0;j<m;j++){
            result[i][j]=A[i][j]+B[i][j];
        }
    }
    return result;
}

Matrix combine_matrices(const Matrix& C11, const Matrix& C12, const Matrix& C21, const Matrix& C22){
    int n = C11.size();
    int m = C11[0].size();
    Matrix result(2*n,vector<int>(2*m,0));

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            result[i][j]=C11[i][j];
            result[i][j+m]=C12[i][j];
            result[i+n][j]=C21[i][j];
            result[i+n][j+m]=C22[i][j];
        }
    } 
    return result;
}

Matrix strassen_multiply(const Matrix& A,const Matrix& B){
    int n = A.size();
    if(n == 1){
        return {{A[0][0]*B[0][0]}};
    }

    int newSize = n / 2;

    Matrix A11(newSize, vector<int>(newSize));
    Matrix A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize));
    Matrix A22(newSize, vector<int>(newSize));

    Matrix B11(newSize, vector<int>(newSize));
    Matrix B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize));
    Matrix B22(newSize, vector<int>(newSize));

    // Partitioning input matrices into submatrices
    for(int i = 0; i < newSize; ++i){
        for(int j = 0; j < newSize; ++j){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Strassen's matrix multiplication steps
    Matrix P1 = strassen_multiply(add_matrices(A11, A22), add_matrices(B11, B22));
    Matrix P2 = strassen_multiply(add_matrices(A21, A22), B11);
    Matrix P3 = strassen_multiply(A11, add_matrices(B12, B22));
    Matrix P4 = strassen_multiply(A22, add_matrices(B21, B11));
    Matrix P5 = strassen_multiply(add_matrices(A11, A12), B22);
    Matrix P6 = strassen_multiply(add_matrices(A21, A11), add_matrices(B11, B12));
    Matrix P7 = strassen_multiply(add_matrices(A12, A22), add_matrices(B21, B22));

    // Calculating submatrices of the result
    Matrix C11 = add_matrices(add_matrices(P1, P4), add_matrices(P7, P5));
    Matrix C12 = add_matrices(P3, P5);
    Matrix C21 = add_matrices(P2, P4);
    Matrix C22 = add_matrices(add_matrices(P1, P3), add_matrices(P6, P2));

    // Combining submatrices to get the result
    return combine_matrices(C11, C12, C21, C22);
}

void print_matrix(const Matrix& mat) {
    for (size_t i = 0; i < mat.size(); ++i) {
        for (size_t j = 0; j < mat[i].size(); ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void initialize_random_matrix(Matrix& c,int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            c[i][j]=rand();
        }
    }
}

void complexity(){
    for(int i=2;i<200;i=2*i){
        int n=i*i*i;
        WriteToFile(i,n);
    }
}

int main(){
    double avgtime,time1,time2;
    for(int i=2;i<200;i=2*i){
        Matrix A(i,vector<int>(i,0));
        Matrix B(i,vector<int>(i,0));

        initialize_random_matrix(A,i);
        initialize_random_matrix(B,i);
        time1=(double)clock();
        for(int j=0;j<10;j++){
            Matrix result = strassen_multiply(A,B);
            // print_matrix(result);
        }
        time2=(double)clock();
        avgtime=(double)(time2-time1)/10;
        cout<<avgtime<<" ";
        WriteDataToFile(i,avgtime*500);
    }
    complexity();
    return 0;
}
Time Complexity:
Strassen's algorithm is a divide-and-conquer algorithm used for the multiplication of large matrices. Traditional matrix multiplication algorithms have a time complexity of O(n^3), where n is the size of the matrices. Strassen's algorithm improves upon this by reducing the number of multiplications needed for large matrices through a recursive approach.
In Strassen's algorithm, the matrix multiplication process is divided into smaller subproblems, and these subproblems are solved recursively. At each level of recursion, the matrices are divided into smaller blocks, and several matrix operations are performed to compute the result efficiently. The key insight of Strassen's algorithm is to reduce the number of multiplications by reusing intermediate results through clever combinations of additions and subtractions.
The time complexity of Strassen's algorithm can be expressed using the master theorem. The master theorem states that if a problem can be divided into a subproblem of size n/b, and there are a subproblems, each taking a/b times the work of the original problem, plus some additional work, then the time complexity of the algorithm is given by:
T(n) = aT(n/b) + f(n)
In Strassen's algorithm, the matrices are divided into submatrices of size n/2, and there are a total of 7 recursive multiplications (a = 7) along with additional matrix additions and subtractions (f(n)). The time complexity of Strassen's algorithm can be expressed as O(n^log2(7)), which is approximately O(n^2.81).
While Strassen's algorithm has a lower theoretical time complexity compared to traditional matrix multiplication, it's often not the most practical choice for small matrices due to the overhead associated with the additional additions and subtractions. However, for very large matrices where the reduction in the number of multiplications outweighs the overhead, Strassen's algorithm can offer significant speedup. Additionally, variations and optimizations of Strassen's algorithm have been proposed to further improve its practical performance.

PROGRAM 21
AIM: Minimum cost in multistage graph.

Algorithm:
stage() function: This function recursively determines the number of stages required to reach the destination node. It starts from the source node and counts the number of steps until it reaches the destination node.
find_fun() function: This function finds the node with the minimum cost to reach the destination node from a given node j. It considers the costs of edges from node j to other nodes and returns the node with the minimum total cost.
fcost() function: This function calculates the minimum cost from each node to the destination node using dynamic programming. It iteratively calculates the minimum cost for each node by considering the costs of outgoing edges and the minimum cost of adjacent nodes. It also stores the predecessor nodes in the path.
main() function: In the main() function, the graph is defined, and the stage() function is called to determine the number of stages from the source to the destination. Then, the fcost() function is called to find the minimum cost path with a given parameter k representing the number of intermediate nodes in the path.
Source Code:
#include <iostream>
#include <climits>
using namespace std;

const int V = 7;

int stage(int graph[V][V], int n, int i, int count) {
    count++;
    if (i == n - 1) {
        return count;
    }
    for (int j = 0; j < n; j++) {
        if (graph[i][j] != 0) {
            return stage(graph, n, j, count);
        }
    }
}

int find_fun(int j, int graph[V][V], int fcost[], int n) {
    int m;
    int min = INT_MAX;
    for (int i = j + 1; i < n; i++) {
        if (graph[j][i] != 0) {
            if (graph[j][i] + fcost[i] < min) {
                m = i;
                min = graph[j][i] + fcost[i];
            }
        }
    }
    return m;
}

void fcost(int graph[V][V], int n, int k) {
    int d[100000];
    int fcost[1000000];
    fcost[n - 1] = 0;
    for (int j = n - 2; j >= 0; j--) {
        int r = find_fun(j, graph, fcost, n);
        fcost[j] = graph[j][r] + fcost[r];
        d[j] = r;
    }
    int p[100000];
    p[0] = 0;
    p[k] = n;
    for (int j = 1; j < k; j++) {
        p[j] = d[p[j - 1]];
    }

    cout << "Min Cost: " << fcost[0] << endl;
    cout << "Path: ";
    for (int j = 0; j < k; j++) {
        cout << p[j] << " ";
    }
    cout << endl;
}

int main() {
    int graph[V][V] = {{0, 2, 3, 4, 0, 0},
                       {0, 0, 0, 0, 8, 0},
                       {0, 0, 0, 0, 5, 7},
                       {0, 0, 0, 0, 0, 6},
                       {0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0},};

    int number = stage(graph, V, 0, 0);
    cout << "number of stages :" << number << endl;

    int k = 4;
    fcost(graph, 7, k);

    return 0;
}
Time Complexity:
Overall time complexity: Considering the time complexities of the individual functions:
•	stage() function: O(V)
•	find_fun() function: O(V)
•	fcost() function: O(V^2)
Since these functions are called sequentially in the main() function, the overall time complexity of the algorithm is dominated by the fcost() function, which is O(V^2).

PROGRAM 22
AIM: All pairs shortest path

Algorithm:
Initialization: The algorithm initializes two matrices: dist[][] to store the shortest distances between pairs of vertices, and pred[][] to store predecessor information for constructing shortest paths. It initializes dist[][] with the given graph's edge weights and sets the predecessors to -1 for vertices without outgoing edges.
Main Algorithm: It iterates through all vertices as intermediate points (k).
For each pair of vertices (i and j), it checks if going through vertex k improves the shortest path from i to j. If so, it updates the shortest distance and predecessor information.
Printing Paths: After computing the shortest distances and predecessors, the algorithm prints the shortest distance and the corresponding path between every pair of vertices.
Source Code:
#include <iostream>
using namespace std;

#define V 4
#define INF 99999

void printPath(int pred[][V], int start, int end) {
    if (start == end) {
        cout << start;
        return;
    }
    if (pred[start][end] == -1) {
        cout << "No path exists from " << start << " to " << end;
        return;
    }
    printPath(pred, start, pred[start][end]);
    cout << " -> " << end;
}

void APSP(int graph[V][V]) {
    int dist[V][V];
    int pred[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INF && i != j)
                pred[i][j] = i;
            else
                pred[i][j] = -1;
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }

    cout << "Shortest distances and paths between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j) {
                cout << "Shortest distance from " << i << " to " << j << ": " << dist[i][j] << ", Path: ";
                printPath(pred, i, j);
                cout << endl;
            }
        }
    }
}

int main() {
    int graph[V][V] = { {0, 5, INF, 10},
                        {INF, 0, 3, INF},
                        {INF, INF, 0, 1},
                        {INF, INF, INF, 0} };

    APSP(graph);
    return 0;
}
Time Complexity:
The initialization step takes O(V^2) time, where V is the number of vertices in the graph.
The main algorithm consists of three nested loops, each running from 0 to V, resulting in a time complexity of O(V^3).
Therefore, the overall time complexity of the Floyd-Warshall algorithm is O(V^3).

PROGRAM 23
AIM: Assembly line.

Algorithm:
Initialization: The entry times for the first and second assembly lines are set to e1 and e2, respectively. The exit times for the first and second assembly lines are set to x1 and x2, respectively. Initial completion times and line choices are calculated for the first station.
Dynamic Programming:
For each station from 1 to n - 1, calculate the completion times (f1[] and f2[]) and line choices (l1[] and l2[]) based on the minimum completion times of the previous station and the transfer times between lines.
Final Minimum Time:
Choose the minimum completion time from the last station plus the exit times for both assembly lines. Update fstar with this minimum time and lstar with the line choice corresponding to the minimum time.
Printing Path:
Backtrack from the last station to the first station to determine the assembly line taken at each station, based on the line choices stored in l1[] and l2[].
Source Code:
#include<iostream>
using namespace std;

int assembly_time(int a[2][4], int t[2][4], int e1, int e2, int x1, int x2, int n, int f1[], int f2[], int l1[], int l2[], int& fstar, int& lstar) {
    f1[0] = e1 + a[0][0];
    f2[0] = e2 + a[1][0];

    for (int j = 1; j < n; j++) {
        if (f1[j - 1] + a[0][j] < f2[j - 1] + t[1][j - 1] + a[0][j]) {
            f1[j] = f1[j - 1] + a[0][j];
            l1[j] = 1;
        }
        else {
            f1[j] = f2[j - 1] + t[1][j - 1] + a[0][j];
            l1[j] = 2;
        }
        if (f2[j - 1] + a[1][j] < f1[j - 1] + t[0][j] + a[1][j]) {
            f2[j] = f2[j - 1] + a[1][j];
            l2[j] = 2;
        }
        else {
            f2[j] = f1[j - 1] + t[0][j] + a[1][j];
            l2[j] = 1;
        }
    }


    if (f1[n - 1] + x1 < f2[n - 1] + x2) {
        fstar = f1[n - 1] + x1;
        lstar = 1;
    }
    else {
        fstar = f2[n - 1] + x2;
        lstar = 2;
    }

    return fstar;
}

int main() {
    int n = 4;
    int a[2][4] = {{4, 6, 8, 2}, {2, 15, 16, 4}};
    int t[2][4] = {{0, 9, 4, 5}, {0, 13, 4, 8}};
    int e1 = 10;
    int e2 = 12;
    int x1 = 18;
    int x2 = 7;
    int f1[4], f2[4], l1[4], l2[4], fstar, lstar;

    int result = assembly_time(a, t, e1, e2, x1, x2, n, f1, f2, l1, l2, fstar, lstar);

    cout << "Minimum time: " << result << endl;

    cout << "Path: ";
    int line = lstar;
    for (int i = n - 1; i >= 0; i--) {
        cout << line << " ";
        if (line == 1)
            line = l1[i];
        else
            line = l2[i];
    }
    cout << endl;

    return 0;
}
Time Complexity:
The main loop iterates through all stations once, resulting in a time complexity of O(n).
Within each iteration, simple arithmetic operations and comparisons are performed, which have constant time complexity.
Therefore, the overall time complexity of the algorithm is O(n).

PROGRAM 24
AIM: Longest common sequence.

Algorithm:
Initialization: Create a 2D array L[][] to store the lengths of LCS for all possible substrings of the input strings X and Y.
Initialize the first row and first column of L[][] with zeros.
Dynamic Programming:
Traverse the strings X and Y character by character.
If the characters match, increment the length of LCS by 1 and store it in L[i][j].
If the characters do not match, take the maximum LCS length from the previous characters.
Backtracking:
After filling the L[][] array, backtrack from the bottom-right corner to reconstruct the LCS string.
Start from the end of both strings and move diagonally in the L[][] array:
If the characters match, include the character in the LCS string and move diagonally up and left.
If the characters do not match, move in the direction of the larger LCS value.
Printing the LCS: Print the LCS string along with arrows (<- or ^|) indicating the direction of movement in the L[][] array.

Source Code:
#include <iostream>
using namespace std;

void printLCSWithArrows(string X, string Y, int m, int n, int L[][100]) {
    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "Longest Common Subsequence: ";
    int k = 0;
    i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            cout << lcs[k];
            k++;
            i--;
            j--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            cout << "<- ";
            i--;
        } else {
            cout << "^|";
            j--;
        }
    }
    cout << endl;
}

int lcs(string X, string Y) {
    int m = X.size();
    int n = Y.size();

    int L[m + 1][100];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    printLCSWithArrows(X, Y, m, n, L);

    return L[m][n];
}

int main() {
    string S1 = "BCDAACD";
    string S2 = "ACDBAC";

    cout << "Length of LCS is " << lcs(S1, S2);

    return 0;
}
Time Complexity:
The algorithm iterates through each character of both strings once, resulting in a time complexity of O(m * n), where m and n are the lengths of the input strings X and Y, respectively.
Backtracking and printing the LCS also take O(m + n) time.

PROGRAM 25
AIM: 0/1 Knabsack (Dynamic Programming)

Algorithm:
Initialization: Create a 2D array K[][] to store the maximum value that can be obtained for all subproblems. Initialize the base cases: when there are no items (i = 0) or the knapsack capacity is zero (w = 0), the maximum value is zero.
Dynamic Programming:
Iterate through all items (i) and knapsack capacities (w).
For each item, decide whether to include it in the knapsack:
If the weight of the current item is less than or equal to the current knapsack capacity (wt[i - 1] <= w), we have two choices: include the item or exclude it. Choose the option that maximizes the total value.
If the weight of the current item exceeds the current knapsack capacity, we cannot include it, so the maximum value remains the same as the value obtained by excluding the item.
Update the K[][] array with the maximum value that can be obtained for each subproblem.
Backtracking:
After filling the K[][] array, backtrack to find the items selected in the knapsack that contribute to the maximum value.
Start from the bottom-right corner of the K[][] array and move upwards:
If the value at K[i][w] is greater than K[i - 1][w], it means item i is included in the knapsack. Subtract its weight from w and move to the next row (i - 1).
If the value at K[i][w] is equal to K[i - 1][w], it means item i is not included in the knapsack, so move to the next row without changing w.
Printing Solution:
Print the indices of the selected items in the knapsack.

Source Code:
#include <iostream>
#include <vector>
using namespace std;
void printsol(vector<vector<int>>& K, vector<int>& wt, int n, int W) {
    cout << "Selected items: ";
    int w = 
    for (int i = n; i > 0 && w > 0; i--) {
        if (K[i][w] != K[i - 1][w]) {
            cout << i << " ";
            w -= wt[i - 1];
        }
    }
    cout << endl;
}
int knapsackDP(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    printsol(K, wt, n, W);
    return K[n][W];
}
int main() {
    vector<int> val = {10,40,30,50,20};
    vector<int> wt = {5,4,6,3,8};
    int W = 15;
    int n = val.size();
    cout << "Maximum value that can be obtained: " << knapsackDP(W, wt, val, n) << endl;
    return 0;
}
Time Complexity:
The algorithm iterates through all items and knapsack capacities once, resulting in a time complexity of O(n * W), where n is the number of items and W is the maximum knapsack capacity.
Backtracking and printing the solution also take O(n + W) time.
In summary, the algorithm efficiently solves the 0-1 knapsack problem using dynamic programming, with a time complexity of O(n * W).

PROGRAM 26
AIM: Minimize the scalar vector multiplications.

Algorithm:
Initialization:
Create a 2D array m[][] to store the minimum number of scalar multiplications required to multiply matrices of different dimensions.
Create a 2D array brac[][] to store the indices of the optimal positions to place parentheses for each subproblem.
Dynamic Programming:
Iterate through all possible chain lengths (L), starting from 2 (multiplying two matrices) up to n (number of matrices).
For each chain length, iterate through all possible starting positions (i) and calculate the minimum number of scalar multiplications required to multiply matrices in the chain.
Use the recurrence relation: m[i][j] = min(m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]), where p[] represents the dimensions of the matrices.
Backtracking:
After filling the m[][] array, backtrack to find the optimal positions to place parentheses for the optimal solution.
Recursively print the optimal parenthesization by following the positions stored in the brac[][] array.

Source Code:
#include <iostream>
#include <climits>
using namespace std;
void printParenthesis(int i, int j, int brac[][5], char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesis(i, brac[i][j], brac, name);
    printParenthesis(brac[i][j] + 1, j, brac, name);
    cout << ")";
}

void MatrixChainOrder(int p[], int n) {
    int m[n][n];
    int brac[5][5];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    brac[i][j] = k;
                }
            }
        }
    }
    cout << "Minimum number of multiplications: " << m[1][n - 1] << endl;
    char name = 'D';
    cout << "Optimal Parenthesization: ";
    printParenthesis(1, n - 1, brac, name);
    cout << endl;
}
int main() {
    int arr[] = {1, 2, 3, 4, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    MatrixChainOrder(arr, N);
    return 0;
}
Time Complexity:
The algorithm iterates through all possible chain lengths (L) and all possible starting positions (i), resulting in a time complexity of O(n^3), where n is the number of matrices.
Backtracking and printing the optimal parenthesization also take O(n) time.
In summary, the algorithm efficiently solves the Matrix Chain Multiplication problem using dynamic programming, with a time complexity of O(n^3).

PROGRAM 27
AIM: N Queens Problem (Backtracking)

Algorithm:
Initialization:
Initialize a 2D array m[][] to store the minimum number of scalar multiplications required for each subchain of matrices.
Initialize a 2D array brac[][] to keep track of the positions of parentheses corresponding to the optimal solution.
Dynamic Programming:
Iterate over all possible chain lengths L (number of matrices in the chain).
For each chain length, iterate over all possible starting matrix positions i.
Calculate the minimum number of scalar multiplications needed to compute the product of matrices from position i to j by trying all possible split positions k between i and j.
Update the m[][] array with the minimum scalar multiplications and store the optimal split position in the brac[][] array.
Backtracking:
Using the information stored in the brac[][] array, recursively print the optimal parenthesization of matrices.

Source Code:
#include <iostream>
#include <climits>
using namespace std;
void printParenthesis(int i, int j, int brac[][5], char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesis(i, brac[i][j], brac, name);
    printParenthesis(brac[i][j] + 1, j, brac, name);
    cout << ")";
}

void MatrixChainOrder(int p[], int n) {
    int m[n][n];
    int brac[5][5];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    brac[i][j] = k;
                }
            }
        }
    }
    cout << "Minimum number of multiplications: " << m[1][n - 1] << endl;
    char name = 'D';
    cout << "Optimal Parenthesization: ";
    printParenthesis(1, n - 1, brac, name);
    cout << endl;
}
int main() {
    int arr[] = {1, 2, 3, 4, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    MatrixChainOrder(arr, N);
    return 0;
}
Time Complexity:
The algorithm iterates over all possible chain lengths and all possible starting positions, resulting in a time complexity of O(n^3), where n is the number of matrices.
Backtracking to print the optimal parenthesization takes linear time.
In summary, the algorithm efficiently solves the Matrix Chain Multiplication problem using dynamic programming, with a time complexity of O(n^3), where n is the number of matrices in the sequence.

PROGRAM 28
AIM: 0/1 Knabsack Using Merge Purge

Algorithm:
Initialization:
Initialize an empty set s1 with a single element {0, 0} representing zero value and zero weight.
Iterative Process:
For each item in the input, iterate over the elements in the set s1.
For each element (value, weight) in s1, generate a new set s2 by adding the value and weight of the current item to each element in s1.
Merge and purge the sets s1 and s2 to obtain a new set s1 containing the combinations of items that satisfy the weight constraint.
Repeat this process for all items.
Merge-Purge Function:
The merge_purge function merges two sets while purging redundant combinations that violate the weight constraint.
Finding Maximum Value:
After obtaining the final set s1, find the maximum value among its elements.
Finding Selected Items:
Identify the items contributing to the maximum value by tracing back through the sets and determining the selected items.

Source Code:
#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
void print(set<pair<int, int>> s)
{
    for (auto i : s)
    {
        cout << "{" << i.first << "," << i.second << "}"
             << " , ";
    }
    cout << endl;
}
int find_max_value(set<pair<int, int>> &s)
{
    int max_value = INT_MIN;
    for (auto i : s)
    {
        max_value = max(max_value, i.first);
    }
    return max_value;
}
vector<int> find_max_path(set<pair<int, int>> &s, int max_value, vector<int> &p, vector<int> &w)
{
    vector<int> path;
    for (auto i : s)
    {
        if (i.first == max_value)
        {
            int remaining_weight = i.second;
            for (int j = p.size() - 1; j >= 0; j--)
            {
                if (i.second - w[j] >= 0)
                {
                    path.push_back(j);
                    remaining_weight -= w[j];
                    i.second -= w[j];
                }
                if (remaining_weight == 0)
                    break;
            }
            break;
        }
    }
    reverse(path.begin(), path.end());
    return path;
}
set<pair<int, int>> merge_purge(set<pair<int, int>> &s1, set<pair<int, int>> &s2, int W)
{
    set<pair<int, int>> s3;
    for (auto i : s1)
    {
        for (auto j : s2)
        {
            if (i.second <= W && j.second <= W)
            {
                if (i.first < j.first && i.second > j.second)
                {
                    continue;
                }
                s3.insert(i);
                s3.insert(j);
            }
        }
    }
    return s3;
}
void knapsackMP(int n, vector<int> &p, vector<int> &w, int W)
{
    set<pair<int, int>> s1 = {{0, 0}};
    for (int i = 0; i < n; i++)
    {
        set<pair<int, int>> s2;
        for (auto j : s1)
        {
            s2.insert({j.first + p[i], j.second + w[i]});
        }
        s1 = merge_purge(s1, s2, W);
    }
    print(s1);
    int max_value = find_max_value(s1);
    cout << "Maximum value: " << max_value << endl;

    vector<int> path = find_max_path(s1, max_value, p, w);
    cout << "Selected items for maximum value: ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n = 5;
    vector<int> p = {10, 40, 30, 50, 80};
    vector<int> w = {5, 4, 6, 3, 9};
    int W = 15;
    knapsackMP(n, p, w, W);
    return 0;
}
Time Complexity:
The algorithm iterates through each item and each element in the set s1 for each item, resulting in a time complexity of O(n * 2^W), where n is the number of items and W is the knapsack capacity.
Merging and purging the sets also contribute to the time complexity, but they are dominated by the exponential nature of the algorithm.
In summary, the Merge-Purge Algorithm provides an approach to solve the 0-1 Knapsack problem efficiently using dynamic programming principles, with a time complexity exponential in the knapsack capacity.

PROGRAM 29
AIM: Sum of subsets backtracking.

Algorithm:
Initialization:
Initialize an array x[] to represent whether an element is included in the subset (x[i] = 1) or not (x[i] = 0).
Recursive Function:
Define a recursive function sumofsubsets that explores all possible subsets by including or excluding each element of the set.
For each element w[k], include it in the subset (x[k] = 1) and check if the current subset sum equals the target sum. If so, print the subset.
If the sum with the current element (s + w[k]) is less than or equal to the target sum, recursively call sumofsubsets with the next element and the updated sum.
If excluding the current element (x[k] = 0) still allows achieving the target sum, recursively call sumofsubsets with the next element and the same sum.
Main Function:
Input the size of the array, the target sum, and the array elements.
Call sumofsubsets with initial parameters to start the recursion.

Source Code:
#include<iostream>
using namespace std;
int w[100];
int x[100];
int m;
int n;
int r;
void sumofsubsets(int s, int k, int sum) {
    x[k] = 1;
    if (s + w[k] == m) {
        for (int i = 0; i < n; i++) {
            if (x[i] == 1)
                cout << w[i] << " ";
        }
        cout << endl;
    }
    else if (s + w[k] + w[k + 1] <= m) {
        sumofsubsets(s + w[k], k + 1, sum - w[k]);
    }
    x[k] = 0;
    if (s + sum - w[k] >= m && s + w[k + 1] <= m) {
        sumofsubsets(s, k + 1, sum - w[k]);
    }
}
int main() {
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the target sum: ";
    cin >> m;
    r = 0;
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        r += w[i];
    }
    sumofsubsets(0, 0, r);
    return 0;
}
Time Complexity:
The algorithm explores all possible subsets by recursively branching at each element.
Since each element can either be included or excluded, there are 2^n possible subsets for a set of size n.
Therefore, the time complexity of the algorithm is exponential, O(2^n), where n is the size of the set.
In summary, the Recursive Sum of Subsets algorithm efficiently finds all subsets whose elements sum up to a specified target value by recursively exploring all possible combinations. However, its time complexity grows exponentially with the size of the input set.

PROGRAM 30
AIM: Coloring Nodes backtracking.

Algorithm:
Initialization:
Initialize an array x[] to represent the color assigned to each vertex. Initially, all vertices are uncolored (x[i] = 0).
mcoloring Function:
The mcoloring function implements the backtracking algorithm.
It starts with the first vertex (k = 0) and attempts to color it with each of the M colors.
If a color is assigned to the current vertex (x[k] != 0), it recursively moves to the next vertex (k + 1) and repeats the process.
If the coloring of the current vertex violates the coloring constraints (i.e., adjacent vertices have the same color), it backtracks and tries the next color.
If all vertices are colored without violation, a valid coloring solution is found, and it is printed.
nextval Function:
The nextval function is used to generate the next color to try for a vertex.
It increments the color for the current vertex (x[k]) and checks if it satisfies the coloring constraints.
Main Function:
The main function initializes the graph's adjacency matrix G, the number of vertices n, and the number of colors m.
It calls the mcoloring function to find all possible colorings of the graph.

Source Code:
#include <iostream>
using namespace std;
const int infinity = 99999;
int x[100];
void nextval(int k, int n, int m, int G[][100]);
void mcoloring(int k, int G[][100], int n, int m) {
    do {
        nextval(k, n, m, G);

        if (x[k] == 0) {
              return;
        } else {
            if (k == n) {
                for (int i = 0; i < n; i++) {
                    cout << x[i] << " ";
                }
                cout << endl;
                return;
            } else {
                mcoloring(k + 1, G, n, m);
            }
        }
    } while (true);
}
void nextval(int k, int n, int m, int G[][100]) {
    int i;
    do {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0) {
            return;
        }
        for (i = 0; i < n; i++) {
            if (G[k][i] != 0 && x[i] == x[k]) {
                break;
            }
        }
        if (i == n) {
            return;
        }
    } while (true);
}
int main() {
    int n, m;
    int G[100][100] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };
    n = 4;
    m = 3;
    mcoloring(0, G, n, m);
    return 0;
}
Time Complexity:
The backtracking algorithm explores all possible colorings of the graph by recursively branching at each vertex.
The time complexity of the algorithm depends on the number of vertices n and the number of colors m, but it typically has an exponential time complexity.
In the worst case, where all color combinations are explored, the time complexity is O(m^n).
In summary, the Backtracking M-Coloring algorithm efficiently finds all possible colorings of a graph with at most M colors by recursively exploring the search space. However, its time complexity grows exponentially with the number of vertices and colors, making it impractical for large graphs or large numbers of colors.
