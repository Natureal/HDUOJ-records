////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-16 13:16:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1394
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:320KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
typedef struct Node
{
    int left,right,sum;
}Node;
Node node[10005];
int n,val[10005];
void build(int s,int t,int n)
{
    int mid=(s+t)/2;
    node[n].left=s;
    node[n].right=t;
    node[n].sum=0;
    if(s==t)
        return;
    build(s,mid,2*n);
    build(mid+1,t,2*n+1);
}
void Insert(int s,int t,int step)
{
    node[step].sum++;
    if(node[step].left==node[step].right)
        return;
    int mid=(node[step].left+node[step].right)/2;
    if(mid>=t)
        Insert(s,t,step*2);
    if(mid<s)
        Insert(s,t,step*2+1);
}
int count(int s,int t,int step)
{
   if(s>t)
   {
       return 0;
   }
   if(node[step].left==s&&node[step].right==t)
   {
       return node[step].sum;
   }
   int m=(node[step].left+node[step].right)/2;
   if(m>=t)
   {
       return count(s,t,step*2);
   }
   else if(m<s)
   {
       return count(s,t,step*2+1);
   }
   else
   {
       return count(s,m,step*2)+count(m+1,t,step*2+1);
   }
}
int main()
{
  //  freopen("in.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        int sumn=0,ans;
        build(0,n-1,1);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&val[i]);
            sumn+=count(val[i],n-1,1);
            Insert(val[i],val[i],1);
        }
        ans=sumn;
        for(int i=1;i<=n;i++)
        {
            sumn=sumn+(n-val[i]-1)-val[i];
            ans=sumn<ans?sumn:ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}
