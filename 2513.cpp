////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-08-25 14:42:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2513
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1852KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: a.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Mon 25 Aug 2014 01:21:44 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1 << 30;

int dp[25][25][25][25];
int g[25][25];
int n,m,k;
int Case = 0;

int Solve(int x1,int y1,int x2,int y2){
	int &res = dp[x1][y1][x2][y2];
	if(res != -1)
		return res;
	int flag = 0;
	int up = y2,down = y1,left = x1,right = x2;
	while(!flag){ //up
		for(int i = x1; i <= x2; ++i)
			if(g[i][up]){
				flag = 1;
				break;
			}
		if(!flag) up--;
	}
	flag = 0;
	while(!flag){ //down
		for(int i = x1; i <= x2; ++i)
			if(g[i][down]){
				flag = 1;
				break;
			}
		if(!flag) down++;
	}
	flag = 0;
	while(!flag){ //right
		for(int i = y1; i <= y2; ++i)
			if(g[right][i]){
				flag = 1;
				break;
			}
		if(!flag) right--;
	}
	flag = 0;
	while(!flag){
		for(int i = y1; i <= y2; ++i)
			if(g[left][i]){
				flag = 1;
				break;
			}
		if(!flag) left++;
	}
	if(up == down && left == right)
		return 0;
	res = INF;
	for(int i = down; i < up; ++i){
		res = min(res,Solve(x1,y1,x2,i) + Solve(x1,i + 1,x2,y2) + x2 - x1 + 1);
	}
	for(int i = left; i < right; ++i){
		res = min(res,Solve(x1,y1,i,y2) + Solve(i + 1,y1,x2,y2) + y2 - y1 + 1);
	}
	return res;
}	

int main(){
	int x,y;
	while(scanf("%d%d%d",&n,&m,&k) == 3){
		memset(g,0,sizeof(g));
		while(k--){
			scanf("%d%d",&x,&y);
			g[x][y] = 1;
		}
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %d\n",++Case,Solve(1,1,n,m));
	}
	return 0;
}
