////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-28 11:01:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1392
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
typedef struct point
{
    int x,y;
}point;
point p[105];
int n;
bool cmpx(point a,point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int cal(point a,point b,point p0)
{
    return (a.x-p0.x)*(b.y-p0.y)-(b.x-p0.x)*(a.y-p0.y);
}
bool cmp(point a,point b)
{
    int k=cal(a,b,p[0]);
    if(k==0)
        return a.x<b.x;
    return k>0;
}
double dis(point a,point b)
{
    double  tx=1.0*b.x-a.x;
    double  ty=1.0*b.y-a.y;
    return sqrt(tx*tx+ty*ty);
}
int main()
{
    //freopen("in","r",stdin);
    while(scanf("%d",&n)!=EOF && n)
    {
        int k=-1;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            if(k==-1||cmpx(p[i],p[k]))
            {
                k=i;
            }
        }
        if(n==1)
        {
            printf("0.00\n");
            continue;
        }
        if(n==2)
        {
            printf("%.2lf\n",dis(p[0],p[1]));
            continue;
        }
        swap(p[0],p[k]);
        sort(p+1,p+n,cmp);
        int t=2;
        for(int i=2;i<n;i++)
        {
            while(t>1&&cal(p[t-2],p[t-1],p[i])<=0) t--;
            p[t++]=p[i];
        }
        double sum=0;
        p[t]=p[0];
        for(int i=0;i<t;i++)
        {
            sum+=dis(p[i],p[i+1]);
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
