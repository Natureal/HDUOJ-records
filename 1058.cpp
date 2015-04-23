////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-08 22:45:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1058
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 5843
int MIN(int a,int b)
{
	return a < b ? a : b;
}
int MIN(int a,int b,int c,int d)
{
	return MIN(MIN(a,b),MIN(c,d));
}
int main()
{
	int a,b,c,d,n,mark;
	int arr[MAXN]={0,1};
	a = 1;
	b = 1;
	c = 1;
	d = 1;
	mark = 1;
	for(int i = 2;i <= MAXN;i ++)
	{
		mark ++;
		arr[i] = MIN(arr[a] * 2 , arr[b] * 3 , arr[c] * 5 , arr[d] * 7);
		if(arr[i] == arr[a] * 2)
			a ++;
		if(arr[i] == arr[b] * 3)
			b ++;
		if(arr[i] == arr[c] * 5)
			c ++;
		if(arr[i] == arr[d] * 7)
			d ++;
	}
	while(scanf("%d",&n)!=EOF && n)
	{
		if(n % 100 != 11 && n % 10 == 1)
			printf("The %dst humble number is %d.\n",n,arr[n]);
		else if(n % 100 != 12 && n % 10 == 2)
			printf("The %dnd humble number is %d.\n",n,arr[n]);
		else if(n % 100 != 13 && n % 10 == 3)
			printf("The %drd humble number is %d.\n",n,arr[n]);
		else
			printf("The %dth humble number is %d.\n",n,arr[n]);
	}
	return 0;
}