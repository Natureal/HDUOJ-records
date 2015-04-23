////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-26 01:01:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4764
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        if(n == 0 && k == 0 )
            break;
        if((n - 1) % (k+1) == 0 || n <= 1)
            printf("Jiang\n");
         else
            printf("Tang\n");
    }
    return 0;
}
