////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-24 16:56:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1425
////Problem Title: 
////Run result: Accept
////Run time:453MS
////Run memory:2240KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
using namespace std;
int arr[1000005];
void quick_sort(int s[],int l,int r)
{
    if(l<r)
    {
        int i=l,j=r,x=s[l];
        while(i<j)
        {
            while(i<j&&s[j]>x) j--;
            if(i<j)s[i++]=s[j];

            while(i<j&&s[i]<=x) i++;
            if(i<j)s[j--]=s[i];
        }
        s[i]=x;
        quick_sort(s,l,i-1);
        quick_sort(s,i+1,r);
    }
    return;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        quick_sort(arr,1,n);
        printf("%d",arr[n]);
        for(int i=n-1;i>=n-m+1;i--)
        {
            printf(" %d",arr[i]);
        }
        puts("");
    }
    return 0;
}
