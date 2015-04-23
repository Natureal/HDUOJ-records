////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-21 16:20:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2067
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:316KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
   __int64 a[36];
   int i,j;
   a[1]=1;
   
   for(i=2;i<=35;i++)
   a[i]=a[i-1]*1.0/(i+1)*(4*i-2);
   int n;
   int tt=0;
   while(scanf("%d",&n)&&n>0)
   {
   printf("%d %d %I64d\n",++tt,n,2*a[n]);
   }
   return 0;
}