////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-10 21:42:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1894
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:3388KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1894.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月10日 星期一 20时45分20秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s[100010];
int main()
{
	int t,n,count;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
		}
		sort(s,s+n);
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(s[i].size()>=s[j].size()) break;
				if(s[i].compare(0,s[i].size(),s[j],0,s[i].size())==0)
					count++;
				else
					break;
			}
		}
		if(count>11519) count%=11519;
		printf("%d\n",count);
	}
	return 0;
}