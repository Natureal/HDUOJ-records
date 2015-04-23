////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-09 22:22:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1256
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1256.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月25日 星期二 22时33分06秒
 ************************************************************************/

#include<stdio.h>
int main()
{
	int i,j,k,n1,n2,t,ti,w;
	char c;
	scanf("%d",&t);
	getchar();
	for(ti=1;ti<=t;ti++)
	{
		scanf("%c %d",&c,&k);
		getchar();

		w=k/6+1;
		k-=3;
		n1=k/2;
		n2=k-n1;

		for(i=1;i<=w;i++)printf(" ");
		for(i=1;i<=n2;i++)printf("%c",c);
	 //   for(i=1;i<=w;i++)printf(" ");
		puts("");
		
		for(j=1;j<=n1;j++)
		{
			for(i=1;i<=w;i++)printf("%c",c);
			for(i=1;i<=n2;i++)printf(" ");	
			for(i=1;i<=w;i++)printf("%c",c);
			puts("");
		}
		
		for(i=1;i<=w;i++)printf(" ");
		for(i=1;i<=n2;i++)printf("%c",c);
	//	for(i=1;i<=w;i++)printf(" ");
		puts("");

		for(j=1;j<=n2;j++)
		{	
			for(i=1;i<=w;i++)printf("%c",c);
			for(i=1;i<=n2;i++)printf(" ");
			for(i=1;i<=w;i++)printf("%c",c);
			puts("");
		}

		
		for(i=1;i<=w;i++)printf(" ");	
		for(i=1;i<=n2;i++)printf("%c",c);
	//	for(i=1;i<=w;i++)printf(" ");	
		puts("");

		if(ti!=t) puts("");
	}
	return 0;
}