////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-16 22:31:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2141
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:1232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string.h>
using namespace std;
#define NUM 505
int l,n,m;
int L[NUM],N[NUM],M[NUM],S,X,arr[NUM * NUM];
bool binary_search(int arr[],int num,int k)
{
	int low = 1,high = num,mid;
	if(arr[low] == k || arr[high] == k)
		return true;
	while(low <= high)
	{
		mid = (high + low) / 2;
		if(arr[mid] == k)
			return true;
		if(arr[mid] > k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	if(low > high)
		return false;
}
int main()
{
	int Case = 1;
	while(scanf("%d %d %d",&l,&n,&m)!=EOF)
	{
		for(int i = 1;i <= l;i ++)
			scanf("%d",&L[i]);
		for(int i = 1;i <= n;i ++)
			scanf("%d",&N[i]);
		for(int i = 1;i <= m;i ++)
			scanf("%d",&M[i]);
		int num = 0;
		for(int i = 1;i <= l;i ++)
		{
			for(int j = 1;j <= n;j ++)
				arr[++num] = L[i] + N[j];
		}
		sort(arr + 1,arr + num + 1);
		sort(M + 1,M + m + 1);
		scanf("%d",&S);
		printf("Case %d:\n",Case ++);
		while(S --)
		{
			int flag = 0;
			scanf("%d",&X);
			for(int i = 1;i <= m;i ++)
			{
				if(binary_search(arr,num,X - M[i]))
				{
					flag = 1;
					break;
				}
			}
			if(flag)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}