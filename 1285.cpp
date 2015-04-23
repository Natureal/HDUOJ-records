////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-20 22:08:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1285
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1256KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int map[505][505],into[505],ans[505];
int n,m,a,b;
void toposort(int map[][505])
{
    memset(into,0,sizeof(into));
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(map[i][j]==1)
                into[j]++;
    into[0]=1;
    for(int i=1;i<=n;i++)
    {
        int j=0;
        while(into[j]!=0)
        {
            j++;
            if(j>n)
                return;
        }
        ans[i]=j;
        into[j]=-1;
        for(int k=1;k<=n;k++)
        {
            if(map[j][k]==1)
            {
                into[k]--;
            }
        }
    }
    printf("%d",ans[1]);
    for(int i=2;i<=n;i++)
    {
        printf(" %d",ans[i]);
    }
    puts("");
    return;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(map,0,sizeof(map));
        while(m--)
        {
            scanf("%d%d",&a,&b);
            map[a][b]=1;
        }
        toposort(map);
    }
    return 0;
}
