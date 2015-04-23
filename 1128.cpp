////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-20 23:13:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1128
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
bool num[1000005]={false};
int main()
{
	int i,j,sum;
	for(i=1;i<=1000000;i++)
	{
		j=i;
		sum=j;
		while(j!=0)
		{
			sum+=j%10;
			j/=10;
		}
		num[sum]=true;
		if(!num[i])
			printf("%d\n",i);
	}
	return 0;
}