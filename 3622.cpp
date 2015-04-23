////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-16 22:56:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3622
////Problem Title: 
////Run result: Accept
////Run time:609MS
////Run memory:984KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 3622.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Thu 16 Oct 2014 09:20:58 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define lp (p << 1)
#define rp (p << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
#define MP(a,b) make_pair(a,b)
typedef long long ll;
const int INF = 1 << 30;
const double eps = 1e-6;

int N,cnt;
double x[205],y[205];
double g[205][205];
int low[205],dfn[205],sc[205],scnt,tot;
vector<double> G[205];
stack<int> S;
double dmax;

double Dis(int a,int b){
	return sqrt((x[b] - x[a]) * (x[b] - x[a]) + 
			(y[b] - y[a]) * (y[b] - y[a]));
}

void Cal_dis(){
	int top = 2 * N;
	for(int i = 0; i < top; ++i)
	for(int j = 0; j < top; ++j){
		g[i][j] = g[j][i] = Dis(i,j);
		dmax = g[i][j] > dmax ? g[i][j] : dmax;
	}
}

void Dfs(int p){
	dfn[p] = low[p] = ++tot;
	S.push(p);
	int top = G[p].size();
	for(int i = 0; i < top; ++i){
		int v = G[p][i];
		if(!dfn[v]){
			Dfs(v);
			low[p] = min(low[p],low[v]);
		}
		else if(!sc[v]){
			low[p] = min(low[p],dfn[v]);
		}
	}
	if(low[p] == dfn[p]){
		++scnt;
		while(1){
			int x = S.top();
			S.pop();
			sc[x] = scnt;
			if(x == p) break;
		}
	}
}

void Tarjan(){
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(sc,0,sizeof(sc));
	while(!S.empty()) S.pop();
	scnt = tot = 0;
	int top = 2 * N;
	for(int i = 0; i < top; ++i)
		if(!dfn[i]) Dfs(i);
}

bool Solve(double d){
	//Build graph
	int top = 2 * N;
	for(int i = 0; i < top; ++i)
		G[i].clear();
	for(int i = 0; i < top; ++i){
		int j;
		if(i % 2) j = i + 1;
		else j = i + 2;
		for(; j < top; ++j){
			if(g[i][j] < 2 * d){
				G[i].push_back(j ^ 1);
				G[j].push_back(i ^ 1);
			}
		}
	}
	//Judge
	Tarjan();
	for(int i = 0; i < N; ++i)
		if(sc[i * 2] == sc[i * 2 + 1]) return false;
	return true;
}

int main(){
	int x1,y1,x2,y2;
	while(scanf("%d",&N) != EOF){
		for(int i = 0; i < N; ++i){
			scanf("%lf%lf%lf%lf",&x[i * 2],&y[i * 2],
					&x[i * 2 + 1],&y[i * 2 + 1]);
		}
		dmax = 0.0;
		Cal_dis();
		int top = 2 * N;
		double ans,mid,L = 0,R = dmax;
		while(fabs(R - L) >= eps){
			mid = L + (R - L) / 2.0;
			if(Solve(mid))
				L = mid;
			else
				R = mid;
		}
		printf("%.2f\n",L);
	}
	return 0;
}			
