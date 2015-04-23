////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-30 15:18:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1231
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:356KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dpsum[10005],s[10005];
int main()
{
    //freopen("in","r",stdin);
    int left,right,n;
    while(scanf("%d",&n)!=EOF && n)
    {
        scanf("%d",&s[1]);
        dpsum[1]=s[1];
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&s[i]);
            if(dpsum[i-1]>=0)
                dpsum[i]=dpsum[i-1]+s[i];
            else
                dpsum[i]=s[i];
        }
        int maxn=-1;
        for(int i=1;i<=n;i++)
        {
            if(maxn<dpsum[i])
            {
                maxn=dpsum[i];
                right=i;
            }
        }
        left=1;
        int tmaxn=maxn;
        for(int i=right;i>=1;i--)
        {
            tmaxn-=s[i];
            if(tmaxn==0)
            {
                left=i;
            }
        }
        if(maxn>=0)
            printf("%d %d %d\n",maxn,s[left],s[right]);
        else
            printf("0 %d %d\n",s[1],s[n]);
    }
    return 0;
}
