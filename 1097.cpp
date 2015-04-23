////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-31 22:16:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1097
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
//#include <stdio.h>
//int pow(int a,int b)
//{
//	int r=1,base=a;
//	while(b!=0)
//	{
//		if(b & 1)
//		{
//			r*=base;
//			r%=10;
//		}
//		base*=base;
//		base%=10;
//		b>>=1;
//	}
//	return r;
//}
//
//int main()
//{
//	int a,b,re;
//    while(scanf("%d %d",&a,&b)>0)
//	{
//		re=pow(a,b);
//		printf("%d\n",re);
//	}
//	return 0;
//}

#include<stdio.h>
int qmod(int a,int n,int c)
{
    a%=c;
    int ans=1;
    while(n)
    {
        if(n%2)
        {
            ans=(ans*a)%c;
        }
        n/=2;
        a=(a*a)%c;
    }
    return ans;
}
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)>0)
    {
        int ans=qmod(a,b,10);
        printf("%d\n",ans);
    }
}