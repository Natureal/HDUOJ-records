////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-29 12:56:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1558
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:316KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
typedef struct edge
{
    double x1,y1,x2,y2;
}edge;
edge e[1005];
int father[1005],sum[1005];
bool judge(edge a,edge b)
{
    double t1=b.y1-((a.y2-a.y1)*b.x1+a.y1*a.x2-a.x1*a.y2)/(a.x2-a.x1);
    double t2=b.y2-((a.y2-a.y1)*b.x2+a.y1*a.x2-a.x1*a.y2)/(a.x2-a.x1);
    if(t1*t2<=0)
        return true;
    return false;
}
int find(int x)
{
    if(father[x]!=x) return find(father[x]);
    else return x;
}
void merge(int a,int b)
{
    int x=find(a),y=find(b);
    if(x!=y)
    {
        father[y]=x;
        sum[x]+=sum[y];
    }
}
int main()
{
   //freopen("in","r",stdin);
    int t,n,k,count;
    char s[2];
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            father[i]=i;
            sum[i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s);
            if(s[0]=='P')
            {
                count++;
                scanf("%lf%lf%lf%lf",&e[count].x1,&e[count].y1
                      ,&e[count].x2,&e[count].y2);
                for(int j=1;j<count;j++)
                {
                    if(judge(e[j],e[count])&&judge(e[count],e[j]))
                    {
                        merge(j,count);
                    }
                }
            }
            else
            {
                scanf("%d",&k);
                printf("%d\n",sum[find(k)]);
            }
        }
        if(t) puts("");
    }
    return 0;
}
