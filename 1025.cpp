////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-16 17:42:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1025
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:544KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int ans[500005],num[500005];
int main()
{
	int Case = 1,n,p,r,len,low,high,mid;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0;i < n;i ++)
		{
			scanf("%d %d",&p,&r);
			num[p] = r;
		}
		ans[1] = num[1];
		len = 1;
		for(int i = 2;i <= n;i ++)
		{
			low = 1;
			high = len;
			while(low <= high)
			{
				mid = (low + high) / 2;
				if(ans[mid] > num[i])
					high = mid - 1;
				else
					low = mid + 1;
			}
			ans[low] = num[i];
			if(low > len)
				len ++;
		}
		printf("Case %d:\n",Case ++);
		if(len == 1)
			printf("My king, at most 1 road can be built.\n\n");
		else
			printf("My king, at most %d roads can be built.\n\n",len);
	}
	return 0;
}