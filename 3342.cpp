////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-20 22:31:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3342
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n,m,map[105][105],used[105],into[105];
bool toposort(int map[][105])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(map[i][j]==1)
                into[j]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        int j=0;
        while(into[j]!=0)
        {
            j++;
            if(j>n)
            {
                return false;
            }
        }
        into[j]=-1;
        for(int k=0;k<n;k++)
        {
            if(map[j][k]==1)
                into[k]--;
        }
    }
    return true;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF && n)
    {
        memset(map,0,sizeof(map));
        memset(used,0,sizeof(used));
        memset(into,0,sizeof(into));
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            map[a][b]=1;
        }
        if(toposort(map))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
