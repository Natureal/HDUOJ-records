////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-10 11:33:16
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2033
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define SYS 60
int main()
{
	int n,h1,m1,s1,h2,m2,s2,hs,ms,ss;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d %d %d %d %d",&h1,&m1,&s1,&h2,&m2,&s2);
		if( (s1+s2)/SYS)
			m1++;
		ss=(s1+s2)%SYS;
		if((m1+m2)/SYS)
			h1++;
		ms=(m1+m2)%SYS;
		hs=h1+h2;
		//ss = (s1+s2) % SYS; 这种算法对于位数多的算法毫无优势！
		//ms = ((s1+s2) / SYS + m1 + m2) % SYS;
		//hs = (((s1+s2) / SYS + m1 + m2) / SYS + h1 + h2) % SYS;
		printf("%d %d %d\n",hs,ms,ss);
	}
	return 0;
}
