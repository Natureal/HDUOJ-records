////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-19 21:25:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1236
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
struct node
{
    int gra;
    char num[25];
};
typedef struct node NODE;
bool cmp(NODE a,NODE b)
{
    if(a.gra>b.gra)
    {
        return true;
    }
    else if(a.gra==b.gra && strcmp(a.num,b.num)<0)
    {
        return true;
    }
    return false;
}
int main()
{
  //  freopen("in.txt","r",stdin);
    NODE stu[1005];
    int i,n,M,m,k,count,g,val[15];
    while(scanf("%d",&n)!=EOF && n)
    {
        count=0;
        scanf("%d%d",&M,&g);
        for(i=0;i<M;i++) scanf("%d",&val[i]);
        for(i=0;i<n;i++)
        {
            scanf("%s %d",stu[i].num,&m);
            stu[i].gra=0;
            while(m--)
            {
                scanf("%d",&k);
                stu[i].gra+=val[k-1];
            }
        }
//        for(i=0;i<n;i++)
//        {
//            printf("ll:%s %d\n",stu[i].num,stu[i].gra);
//        }
        sort(stu,stu+n,cmp);
//        for(i=0;i<n;i++)
//        {
//            printf("%s %d\n",stu[i].num,stu[i].gra);
//        }
        for(i=0;i<n;i++)
        {
            if(stu[i].gra>=g)
                count++;
        }
        printf("%d\n",count);
        for(i=0;i<count;i++)
        {
            printf("%s %d\n",stu[i].num,stu[i].gra);
        }
    }
    return 0;
}
