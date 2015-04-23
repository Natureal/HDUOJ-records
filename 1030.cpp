////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-09 16:44:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1030
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1030.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月09日 星期日 16时10分47秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include<cstdlib>
int main()
{
	int i,a,b,ca,cb,wa,wb,da,db;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		ca=(int)sqrt(a);
		if(a!=ca*ca)
		{
			ca++;
		}
		cb=(int)sqrt(b);
		if(b!=cb*cb)
		{
			cb++;
		}
		wa=a-(ca-1)*(ca-1);
		da=ca-wa/2;
		wa=((double)wa-0.1)/2+1;

		wb=b-(cb-1)*(cb-1);
		db=cb-wb/2;
		wb=((double)wb-0.1)/2+1;

	//	printf("%d %d %d\n%d %d %d\n",ca,wa,da,cb,wb,db);
		printf("%d\n",abs(ca-cb)+abs(wa-wb)+abs(da-db));
	}
	return 0;
}