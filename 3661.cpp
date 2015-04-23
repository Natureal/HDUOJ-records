////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-26 21:38:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3661
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:284KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
int a1[1005],a2[1005],n,t;
void quick_sort1(int s[],int l,int r)
{
    if(l<r)
    {
        int i=l,j=r,x=s[l];
        while(i<j)
        {
            while(i<j && s[j]>x) j--;
            if(i<j) s[i++]=s[j];

            while(i<j && s[i]<=x) i++;
            if(i<j) s[j--]=s[i];
        }
        s[i]=x;
        quick_sort1(s,l,i-1);
        quick_sort1(s,i+1,r);
    }
    return;
}
void quick_sort2(int s[],int l,int r)
{
    if(l<r)
    {
        int i=l,j=r,x=s[l];
        while(i<j)
        {
            while(i<j && s[j]<x) j--;
            if(i<j) s[i++]=s[j];

            while(i<j && s[i]>=x) i++;
            if(i<j) s[j--]=s[i];
        }
        s[i]=x;
        quick_sort2(s,l,i-1);
        quick_sort2(s,i+1,r);
    }
    return;
}
int main()
{
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a1[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a2[i]);
        }
        quick_sort1(a1,1,n);
        quick_sort2(a2,1,n);
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(a1[i]+a2[i]>t)
            {
                sum+=(a1[i]+a2[i]-t);
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
