////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-28 00:16:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1348
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define PI 3.1415927
#define eps 1e-8
typedef struct point
{
    int x,y;
}point;
point p[1005];
int t,n,l;
int cross(point p1,point p2,point p0)
{
    int x1=p1.x-p0.x;
    int x2=p2.x-p0.x;
    int y1=p1.y-p0.y;
    int y2=p2.y-p0.y;
    return x1*y2-x2*y1;
}
bool cmpx(point a,point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
bool cmp(point a,point b)
{
    int k=cross(a,b,p[0]);
    if(k==0)
       return a.x<b.x;
    return k>0;
}
void Graham()
{
    t=2;
    for(int i=2;i<n;i++)
    {
        while(t>1&&cross(p[t-2],p[t-1],p[i])<eps)
        {
            t--;
        }
        p[t++]=p[i];
    }
    return;
}
double dis(point a,point b)
{
    double tx=1.0*b.x-a.x;
    double ty=1.0*b.y-a.y;
    return sqrt(tx*tx+ty*ty);
}
int main()
{
    //freopen("in","r",stdin);
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&l);
            int k=-1;
            for(int i=0;i<n;i++)
            {
                scanf("%d %d",&p[i].x,&p[i].y);
                if(k==-1||cmpx(p[i],p[k]))
                {
                    k=i;
                }
            }
            swap(p[0],p[k]);
            sort(p+1,p+n,cmp);
            Graham();
            double sum=0;
            p[t]=p[0];
            for(int i=0;i<t;i++)
            {
                sum+=dis(p[i],p[i+1]);
            }
            sum+=2.0*PI*l;
            printf("%.0lf\n",sum);
            if(cas)puts("");
    }
    return 0;
}
