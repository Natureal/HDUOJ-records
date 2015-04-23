////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-07 21:54:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1037
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a[3],i,count;
	while(3==scanf("%d %d %d",&a[0],&a[1],&a[2]))
	{
		count=0;
		for(i=0;i<3;i++)
		{
			if(a[i]<=168)
			{
				count=a[i];
				break;
			}
		}
		if(0==count)
	    printf("NO CRASH\n");
		else
		printf("CRASH %d\n",count);
	}
	return 0;
}