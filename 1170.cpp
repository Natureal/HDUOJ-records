////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-07 23:34:26
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1170
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,a,b;
	char c;
	scanf("%d",&t);
	while(t--)
		{
			getchar();
			scanf("%c %d %d",&c,&a,&b);
			switch(c)
			{
		     	case '+' :printf("%d\n",a+b);continue;
				case '-' :printf("%d\n",a-b);continue;
				case '*' :printf("%d\n",a*b);continue ;
				case '/' :if(0==a%b)
					      {
						    printf("%d\n",a/b);
							continue;
						  }
						  else
						  {
						    printf("%.2f\n",(float)a/b);
							continue;
						  }
				default  :continue;
			}
		}
	return 0;
}
