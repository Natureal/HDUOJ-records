////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-24 22:56:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1027
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:280KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
int fac[]={1,1,2,6,24,120,720,5040,40320,362880,362880};
int main()
{
    int n,m,s[1005];
    int i,j,count,used[1005];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(used,0,sizeof(used));
        memset(s,0,sizeof(used));
        m--;
        int nn=0;
        if(n>8)
        {
            for(i=0;i<n-8;i++)
            {
                s[i]=i+1;
            }
            nn=n-8;
            n=8;
        }
        for(i=0;i<n;i++)
        {
            count=m/fac[n-i-1];
            for(j=1;j<=n;j++)
            {
                if(!used[j])
                {
                    if(count==0)break;
                    count--;
                }
            }
            s[i+nn]=j+nn;
            used[j]=1;
            m%=fac[n-i-1];
        }
        printf("%d",s[0]);
        for(int i=1;;i++)
        {
            if(s[i]==0)
            {
                break;
            }
            printf(" %d",s[i]);
        }
        puts("");
    }
    return 0;
}
