////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-17 00:22:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2200
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
 __int64 n;
 while(scanf("%I64d",&n)!=EOF)
  printf("%I64d\n",(1LL<<(n-1))*(n-2)+1);
 return 0;
}