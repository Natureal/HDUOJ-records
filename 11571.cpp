////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-25 18:59:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1157
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include <stdio.h>
void qsort(int s[],int l,int r)
{
    if(l<r)
    {
        int i=l,j=r,x=s[l];
        while(i<j)
        {
            while(i<j && s[j]>=x) j--;
            if(i<j) s[i]=s[j];
            while(i<j && s[i]<x) i++;
            if(i<j) s[j]=s[i];
        }
        s[i]=x;//»òÕßs[j]=x;
        qsort(s,l,i-1);
        qsort(s,i+1,r);
    }
}
int main()
{
    int i,n,s[10005];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&s[i]);
        }
        qsort(s,1,n);
        printf("%d\n",s[(n+1)/2]);
    }
    return 0;
}