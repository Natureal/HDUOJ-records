////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-29 17:22:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1864
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:12036KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[3000050],val[35];
int main()
{
   // freopen("in","r",stdin);
    double tq,v;
    int n,m,count,q,vt[4];
    char s,tt;
    while(scanf("%lf %d",&tq,&n)!=EOF)
    {
        if(n==0) break;
        q=(int)(tq*100);
        memset(dp,0,sizeof(dp));
        count=0;//The available number of bills
        for(int i=1;i<=n;i++)//The number of bills.
        {
            memset(vt,0,sizeof(vt));
            scanf("%d",&m);
            getchar();
            for(int j=1;j<=m;j++)//The number of terms.
            {
                scanf("%c%c%lf",&s,&tt,&v);
                getchar();
                if(s-'A'>=0 && s-'A'<=2)
                {
                    vt[s-'A'+1]+=(int)(v*100);
                }
                else vt[1]+=100001;
            }
            int tsum=vt[1]+vt[2]+vt[3];
            if(tsum<=100000 && vt[1]<=60000 && vt[2]<=60000 && vt[3]<=60000)
            {
                count++;
                val[count]=tsum;
            }
        }
//        printf("sum:%.2lf\n",q);
//        for(int i=1;i<=count;i++)
//        {
//            printf("val[%d]:%d\n",i,val[i]);
//        }
        //dp
        for(int i=1;i<=count;i++)//consider every bills
        {
            for(int j=q;j>=val[i];j--)//没张支票报报销或者不报销
            {
                dp[j]=max(dp[j],dp[j-val[i]]+val[i]);
            }
        }
        printf("%.2lf\n",dp[q]/100.0);
    }
    return 0;
}
