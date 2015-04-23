////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-30 15:44:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2571
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:440KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int map[25][1005],dp[25][1005];
int main()
{
    //freopen("in","r",stdin);
    int c,n,m;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i ++)
        {
            for(int j = 1;j <= m;j ++)
            {
                scanf("%d",& map[i][j]);
            }
        }
        dp[1][1]=map[1][1];
        for(int i = 1;i <= n;i ++)
        {
            for(int j = 1;j <= m;j ++)
            {
                if(i==1&&j==1)
                    continue;
                else if(i==1)
                    dp[i][j]=dp[i][j-1]+map[i][j];
                else if(j==1)
                    dp[i][j]=dp[i-1][j]+map[i][j];
                else
                    dp[i][j]=max(dp[i-1][j]+map[i][j],dp[i][j-1]+map[i][j]);
                for(int k=1;k<j;k++)
                {
                    if(j%k==0)
                    {
                        dp[i][j]=max(dp[i][j],dp[i][k]+map[i][j]);
                    }
                }
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
