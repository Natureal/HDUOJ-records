////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-14 11:53:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2065
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int pow(int a,__int64 b)
{
    int r=1,base=a;
    while(b!=0)
    {
        if(b&1)
        {
            r=(r*base)%100;
        }
        base=(base*base)%100;
        b>>=1;
    }
    return r;
}
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF&&t)
    {
        __int64 n;
        for(int i=1;i<=t;i++)
        {
            scanf("%I64d",&n);
            printf("Case %d: %d\n",i,(pow(4,n-1)+pow(2,n-1))%100);
        }
        puts("");
    }
    return 0;
}
