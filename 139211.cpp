////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-28 11:08:56
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
#include <algorithm>
#include <math.h>
using namespace std;
//凸包初想最终版本
typedef struct point//建立点的结构体
{
    int x,y;
}point;
point p[105];
int n;
bool cmpx(point a,point b)//在找最左下点时用的比较函数
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int cross(point p1,point p2,point p0)//计算叉积，两个向量为P0P1和P0P2
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
bool cmp(point a,point b)//sort函数的cmp函数，用来点排序
{
    int k=cross(a,b,p[0]);
    if(k==0)             //如果角一样，则取x坐标小的那个点
        return a.x<b.x;
    return k>0;          //判断前一个点的角是否比后面的点小
}
double dis(point a,point b)//计算两点的距离
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
        if(n==1)//题目需要，特别判断，下同
        {
            printf("0.00\n");
            continue;
        }
        if(n==2)
        {
            printf("%.2lf\n",dis(p[0],p[1]));
            continue;
        }
        swap(p[0],p[k]);//将最小的点与P【0】换个位置
        sort(p+1,p+n,cmp);//按照角进行排序
        int t=2;          //不妨记这种Graham
        for(int i=2;i<n;i++)//i的初值要和t一致
        {
            while(t>1&&cross(p[t-2],p[t-1],p[i])<=0) t--;//不构成左转则退栈
            p[t++]=p[i];//直到能够左转
        }
        //这种Graham出来，t-1代表最后一个元素
        double sum=0;
        p[t]=p[0];//技巧
        for(int i=0;i<t;i++)//计算凸包周长
        {
            sum+=dis(p[i],p[i+1]);
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
