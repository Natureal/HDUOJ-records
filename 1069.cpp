////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-01 09:51:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1069
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:348KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct cuboid
{
	int x,y,h;
}cuboid;
cuboid cub[95];
int dp[95];
int cmp(cuboid a,cuboid b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,x,y,z;
	int Case=1;
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<3*n;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			cub[i].h=z;
			cub[i].x=x>y?x:y;
			cub[i++].y=x>y?y:x;

			cub[i].h=y;
			cub[i].x=x>z?x:z;
			cub[i++].y=x>z?z:x;

			cub[i].h=x;
			cub[i].x=y>z?y:z;
			cub[i].y=y>z?z:y;
		}
		sort(cub,cub+3*n,cmp);
		dp[0]=cub[0].h;
		int maxn=dp[0];
		for(int i=1;i<3*n;i++)
		{
			int max=0;
			for(int j=i-1;j>=0;j--)
			{
				if((cub[i].x>cub[j].x && cub[i].y>cub[j].y)||
					(cub[i].x>cub[j].y && cub[i].y>cub[j].x))
				{
					if(dp[j]>max)
					{
						max=dp[j];
					}
				}
			}
			dp[i]=max+cub[i].h;
			if(dp[i]>maxn)
			{
				maxn=dp[i];
			}
		}
		/*for(int i=0;i<3*n;i++)
		{
			printf("%d\n",dp[i]);
		}*/
		//由于不一定每个都用到所以要搜索最大值
		printf("Case %d: maximum height = %d\n",Case,maxn);
		Case++;
	}
	return 0;
}