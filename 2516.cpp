////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-05-08 21:28:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2516
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
using namespace std;
int fib[50];
int main()
{
    fib[1] = 1;
    fib[2] = 1;
    for(int i = 3; i <= 46; i ++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        int i;
        for(i = 3 ;i <= 46; i++)
            if(fib[i] == n)
            {
                printf("Second win\n");
                break;
            }
        if(i >= 47)
        {
            printf("First win\n");
        }
    }
    return 0;
}
