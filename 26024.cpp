////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-02 02:49:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2602
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1100KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int dp[1001],va[1001],vo[1001];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int i,j,n,N,V;
    scanf("%d",&n);
    while(n--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&N,&V);
        for(i=1;i<=N;i++)
        {
            scanf("%d",&va[i]);
        }
        for(i=1;i<=N;i++)
        {
            scanf("%d",&vo[i]);
        }
        for(i=1;i<=N;i++)
        {
            for(j=V-vo[i];j>=0;j--)
            {
                dp[j+vo[i]]=max(dp[j+vo[i]],dp[j]+va[i]);
            }
        }
        printf("%d\n",dp[V]);
    }
    return 0;
}