////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-05-02 17:36:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4004
////Problem Title: 
////Run result: Accept
////Run time:328MS
////Run memory:428KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 500000

int dis[MAXN + 5];

int main()
{
	int l,m,n,maxn;
	while(scanf("%d %d %d",&l,&n,&m)!=EOF)
	{
		maxn = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			scanf("%d",&dis[i]);//dis用来记录每个石头及终点的坐标（相对于起点）
		}
		dis[n + 1] = l;
		sort(dis + 1,dis + n + 1);//第二个参数表示要排序的最后一个元素的后面一个元素
		for(int i = 1 ; i <= n ; i ++)
		{
			maxn = max(maxn,dis[i + 1] - dis[i]);
		}
		int low = maxn , high = l , mid;
		while(low <= high)
		{
			int num = 0;//跳跃次数
			int pos = 0;//现在的位置
			mid = (low + high) >> 1;
			for(int i = 1 ; i <= n ; i ++)
			{
				//printf("%d %d mid : %d \n",dis[i] - dis[pos],dis[i + 1] - dis[pos],mid);
				if(dis[i] - dis[pos] <= mid && dis[i + 1] - dis[pos] > mid)
				{
					num ++;
					pos = i;
				}
			}
			num ++;
			if(num > m) //次数多，步子小
				low = mid + 1;
			else        //次数小，步子大了
				high = mid - 1;
		}
		printf("%d\n",low);
	}
	return 0;
}