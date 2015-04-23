////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-05-06 23:04:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1525
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a == 0 && b == 0)
            break;
        if(a > b)
            swap(a,b);
        bool stan = true;
        while(1)
        {
            if(a == 0 || b == 0 || b%a == 0 || b/a >= 2)
                break;
            b -= a;
            if(a > b)
                swap(a,b);
            stan = !stan;
        }
        if(stan)
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
    return 0;
}
