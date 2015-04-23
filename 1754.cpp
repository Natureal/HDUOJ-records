////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-19 22:09:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1754
////Problem Title: 
////Run result: Accept
////Run time:515MS
////Run memory:2316KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const maxn=222222;
int n,m,MAX[maxn<<2];
void PushUP(int rt)
{
    MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&MAX[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUP(rt);
    return;
}
void update(int p,int sc,int l,int r,int rt)
{
    if(l==r)
    {
        MAX[rt]=sc;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m) update(p,sc,lson);
    else update(p,sc,rson);
    PushUP(rt);
    return;
}
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)//因为往下搜索范围只可能变小，所以从上往下这么判断即可！
    {
        return MAX[rt];
    }
    int m=(l+r)>>1;
    int temp=0;
    if(L<=m) temp=max(temp,query(L,R,lson));
    if(R>m) temp=max(temp,query(L,R,rson));
    return temp;
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        build(1,n,1);
        while(m--)
        {
            char op[2];
            int a,b;
            scanf("%s%d%d",op,&a,&b);
            if(op[0]=='Q')
                printf("%d\n",query(a,b,1,n,1));
            else
                update(a,b,1,n,1);
        }
    }
    return 0;
}
