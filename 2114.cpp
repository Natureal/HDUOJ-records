////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-22 00:41:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2114
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:308KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	__int64 n,m,i,j,sum;
	while(cin>>n)
	{
		n%=10000; 
		sum=((n*(n+1)/2)*(n*(n+1)/2))%10000;//其中公式可以用差量法得到 
		printf("%04I64d\n",sum);
	}
	return 0;
}