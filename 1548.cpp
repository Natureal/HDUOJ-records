////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-11 21:17:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1548
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1548.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Thu 11 Sep 2014 08:46:20 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 1 << 29;

int N,A,B,k[205];

void Dij(){
	int  d[205],vis[205];
	for(int i = 0; i <= N; ++i) d[i] = INF;
	memset(vis,0,sizeof(vis));
	d[A] = 0;
	for(int i = 1; i <= N; ++i){
		int x,tmin = INF;
		for(int j = 1; j <= N; ++j) if(!vis[j] && d[j] < tmin)
			tmin = d[x = j];
		vis[x] = 1;
		if(x - k[x] >= 1 && d[x - k[x]] > d[x] + 1)
			d[x - k[x]] = d[x] + 1;
		if(x + k[x] <= N && d[x + k[x]] > d[x] + 1)
			d[x + k[x]] = d[x] + 1;
	}
	if(d[B] >= INF) printf("-1\n");
	else printf("%d\n",d[B]);
}	

int main(){
	while(scanf("%d",&N) != EOF && N){
		scanf("%d%d",&A,&B);
		for(int i = 1; i <= N; ++i) scanf("%d",&k[i]);
		Dij();
	}
	return 0;
}
