////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-25 00:53:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1729
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <math.h>
#include <stdio.h>
int SG(int s,int c)
{
     int k = sqrt((double)s);
    while(k >= 0)
     {
         if(k * (k+1) < s && (k+1) * (k+2) >= s)
         {
             break;
         }
         k --;
     }
     if(k < c) return s - c;
     else
         return SG(k,c);
}
int main()
{
    int n,s,c,Case = 1,ans;
    while(scanf("%d",&n)!=EOF && n)
    {
        ans = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d",&s,&c);
            ans ^= SG(s,c);
        }
        printf("Case %d:\n",Case++);
        if(ans == 0)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
    return 0;
}
