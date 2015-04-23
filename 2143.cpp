////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-12 22:04:31
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2143
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	_int64 a,b,c,flag;
	while(scanf("%I64d%I64d%I64d",&a,&b,&c)!=EOF)
	{
		flag=0;
		if((a+b)==c||(a+c)==b||(b+c)==a)
			flag=1;
		else if((a*b)==c||(a*c)==b||(b*c)==a)
			flag=1;
		else if((a&&(b%a==c||c%a==b))||(b&&(a%b==c||c%b==a))||(c&&(a%c==b||b%c==a)))
			flag=1;
		else
			flag=0;
		if(flag) printf("oh,lucky!\n");
		else printf("what a pity!\n");
	}
	return 0;
}