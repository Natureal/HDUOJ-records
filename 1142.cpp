////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-11 20:42:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1142
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:652KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1142.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Thu 11 Sep 2014 08:04:10 PM CST
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

int n,m;
int first[1005],next[2000005],v[2000005],w[2000005];
int d[1005],inq[1005],c[1005],vis[1005];
int dp[1005];

void Spfa(int s){
	memset(inq,0,sizeof(inq));
	memset(c,0,sizeof(c));
	memset(d,0x3f,sizeof(d));
	d[s] = 0;
	queue<int> q; while(!q.empty()) q.pop();
	inq[s] = c[s] = 1;
	q.push(s);
	while(!q.empty()){
		int x = q.front(); q.pop();
		inq[x] = 0;
		for(int y = first[x]; y; y = next[y]) if(d[v[y]] > d[x] + w[y]){
			d[v[y]] = d[x] + w[y];
			if(!inq[v[y]]){
				inq[v[y]] = 1;
				c[v[y]]++;
				if(c[v[y]] > n) return;
				q.push(v[y]);
			}
		}
	}
}

int Dfs(int p){
	vis[p] = 1;
	if(dp[p] != -1) return dp[p];
	if(p == 2) return 1;
	int sum = 0;
	for(int y = first[p]; y; y = next[y]) if(!vis[v[y]] && d[p] > d[v[y]]){
		sum += Dfs(v[y]);
		vis[v[y]] = 0;
	}
	return dp[p] = sum;
}
	
int main(){
	int a,b,c;
	while(scanf("%d",&n) != EOF && n){
		scanf("%d",&m);
		m <<= 1;
		memset(first,0,sizeof(first));
		for(int i = 1; i <= m; ++i){
			scanf("%d%d%d",&a,&b,&c);
			next[i] = first[a];
			first[a] = i;
			v[i] = b;
			++i;
			next[i] = first[b];
			first[b] = i;
			v[i] = a;
			w[i] = w[i - 1] = c;
		}
		Spfa(2);
		memset(vis,0,sizeof(vis));
		memset(dp,-1,sizeof(dp));
		printf("%d\n",Dfs(1));
	}
	return 0;
}
			
