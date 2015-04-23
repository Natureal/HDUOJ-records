////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-16 22:39:34
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2061
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,n,count;
	char a[31];
	double  c,sum,gpa,s;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		gpa=0;
		count=0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s%lf%lf",&a,&c,&s);
			if(s<60)
			{
				count=1;
				continue;
			}
			else
			{
		     	gpa+=s*c;
		    	sum+=c;
			}
		}
		if(count)
			printf("Sorry!\n");
		else
		{
			printf("%.2lf\n",gpa/sum);
		}
		if(t!=0)
		{
			puts("");
		}
	}
	return 0;
}