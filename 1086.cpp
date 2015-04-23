////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-25 22:29:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1086
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:292KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef struct edge
{
    double x1,x2,y1,y2;
}Edge;
Edge edges[105];

bool judge(edge a,edge b)
{
    //y=kx+b;
    double x=b.y1-((a.y1-a.y2)*b.x1+(a.x1*a.y2-a.x2*a.y1))/(a.x1-a.x2);
    double y=b.y2-((a.y1-a.y2)*b.x2+(a.x1*a.y2-a.x2*a.y1))/(a.x1-a.x2);
    if(x*y<=0)
        return true;
    return false;
}
int main()
{
    //freopen("in","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        memset(edges,0,sizeof(edges));
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf%lf",&edges[i].x1,&edges[i].y1,&edges[i].x2,&edges[i].y2);
        }
        int count=0;
        for(int i=1;i<=n-1;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(judge(edges[i],edges[j])&&judge(edges[j],edges[i]))
                {
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
