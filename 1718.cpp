////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-26 00:35:52
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1718
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
typedef struct
{
	long int name;
	int grade;
}STU;
int main()
{
	long int jac;
	STU a[1010];
	int i,j,rank,g;
	while(scanf("%ld",&jac)!=EOF)
	{
		i=0;
		while(scanf("%ld%d",&a[i].name,&a[i].grade)!=EOF)
		{
			if(a[i].name==0 && a[i].grade==0) break;
			if(a[i].name==jac) g=a[i].grade;
		   i++;
		}
		rank=1;
		for(j=0;j<=i;j++)
		{
			if(a[j].grade>g)
				rank++;
		}
		printf("%d\n",rank);
	}
	return 0;
}