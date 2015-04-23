////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-27 20:57:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1392
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
#define eps 1e-8
typedef struct point
{
    double x,y;
}point;
point p[105];
int n;
double cross(point a,point b,point p0)
{
    double x1,y1,x2,y2;

    x1=a.x-p0.x;
    y1=a.y-p0.y;
    x2=b.x-p0.x;
    y2=b.y-p0.y;

    return x1*y2-x2*y1;
}
bool cmpx(point a,point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
double cal(point a,point b,point p0)
{
    return (a.x-p0.x)*(b.y-p0.y)-(b.x-p0.x)*(a.y-p0.y);
}
bool cmp(point a,point b)
{
    double k=cal(a,b,p[0]);
    if(fabs(k)<eps)
        return a.x<b.x;
    return k>0;
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
    while(scanf("%d",&n)!=EOF && n)
    {
        int k=-1;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
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
//        for(int i=0;i<n;i++)
//        {
//            printf("sx:%d sy:%d\n",p[i].x,p[i].y);
//        }
        int t=2;
        for(int i=2;i<n;i++)
        {
            while(t>1&&cross(p[t-2],p[t-1],p[i])<eps) t--;
            p[t++]=p[i];
        }
//        for(int i=0;i<=t;i++)
//        {
//           printf("x:%.2lf y:%.2lf\n",p[i].x,p[i].y);
//        }
        double sum=0;
        p[t]=p[0];
        for(int i=0;i<t;i++)
        {
            sum+=dis(p[i],p[i+1]);
           // printf("%.2lf\n",dis(p[i],p[i+1]));
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
