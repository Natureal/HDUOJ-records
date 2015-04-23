////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-25 23:45:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1147
////Problem Title: 
////Run result: Accept
////Run time:406MS
////Run memory:3420KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef struct edge
{
    double x1,x2,y1,y2;
}EDGE;
EDGE s[100005];
bool judge(EDGE a,EDGE b)
{
    double n=b.y1-((a.y1-a.y2)*b.x1+(a.x1*a.y2-a.x2*a.y1))/(a.x1-a.x2);
    double m=b.y2-((a.y1-a.y2)*b.x2+(a.x1*a.y2-a.x2*a.y1))/(a.x1-a.x2);
    if(n*m<=0)
        return true;
    return false;
}
int main()
{
    //freopen("in","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
//        scanf("%lf%lf%lf%lf",&s[1].x1,&s[1].y1,&s[1].x2,&s[1].y2);
//        int count=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf%lf",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
//            for(int j=1;j<i;j++)
//            {
//                if(judge(s[i],s[j])&&judge(s[j],s[i]))
//                {
//                    if(!count) printf("Top sticks: %d",i);
//                    else
//                    {
//                        printf(", %d",i);
//                    }
//                    count++;
//                    break;
//                }
//            }
        }
        int count=0;
        for(int i=1;i<=n;i++)
        {
            int flag1=1;
            for(int j=i+1;j<=n;j++)
            {
                if(judge(s[i],s[j])&&judge(s[j],s[i]))
                {
                    flag1=0;
                    break;
                }
            }
            if(flag1)
            {
                if(!count) printf("Top sticks: %d",i);
                else printf(", %d",i);
                count++;
            }
        }
        printf(".\n");
    }
    return 0;
}
