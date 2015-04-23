////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-15 15:51:57
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2000
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	char a,b,c,x,y,z;
	while(scanf("%c%c%c",&a,&b,&c)!=EOF) //做空格实验，（也可以定义新的字符，输入但不用）
	{
		getchar();//吃掉回车！（在输入字符时，要注意回车的问题）
		x=a>b?a:b;
		x=x>c?x:c;
		z=a<b?a:b;
		z=z<c?z:c;
		y=a+b+c-x-z;
		printf("%c %c %c\n",z,y,x);
	}
	return 0;
}