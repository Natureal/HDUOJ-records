////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-15 16:21:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2116
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
int main()
{
    int k;
    long long int m,n,p,q;
    while (~scanf("%d",&k))
    {          
      p=-pow(2,k-1); q=pow(2,k-1)-1;
      scanf("%I64d%I64d",&m,&n);
      if (m>0&&n>0)
      {
      if (n>q-m) printf("Yes\n");
      else printf("WaHaHa\n");
      }
      else if (m<0&&n<0)
      {
      if (n<p-m) printf("Yes\n");
      else printf("WaHaHa\n");            
      }
      else printf("WaHaHa\n");
    }
    return(0);
}
