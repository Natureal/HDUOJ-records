////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-04 13:44:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5093
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:316KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 5093.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Tue 04 Nov 2014 12:18:56 AM CST
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
const int maxn = 2510;

int T;
int n,m,cr,cc,row[55][55],col[55][55];
char g[55][55];
int first[maxn],next[maxn * maxn],ver[maxn * maxn],ecnt;
int used[maxn],mat[maxn];

void Init(){
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	memset(first,-1,sizeof(first));
	ecnt = cr = cc = 0;
}

void Add_edge(int u,int v){
	next[++ecnt] = first[u];
	ver[ecnt] = v;
	first[u] = ecnt;
}

void Build_graph(){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int u = row[i][j],v = col[i][j];
			if(u && v) Add_edge(u,v);
		}
	}
}

bool find(int p){
	for(int i = first[p]; i != -1; i = next[i]){
		int v = ver[i];
		if(used[v] == 0){
			used[v] = 1;
			if(mat[v] == 0 || find(mat[v])){
				mat[v] = p;
				return true;
			}
		}
	}
	return false;
}

int Hungary(){
	int ans = 0;
	memset(mat,0,sizeof(mat));
	for(int i = 1; i <= cr; ++i){
		memset(used,0,sizeof(used));
		if(find(i)) ++ans;
	}
	return ans;
}

int main(){
	scanf("%d",&T);
	while(T--){
		Init();
		scanf("%d%d",&n,&m);
		for(int i = 0; i < n; ++i)
			scanf("%s",g[i]);
		for(int i = 0; i < n; ++i){
			int flag = 0;
			for(int j = 0; j < m; ++j){
				if(g[i][j] == '*'){
					if(flag == 0) ++cr;
					row[i][j] = cr;
					flag = 1;
				}
				else if(g[i][j] == '#')
					flag = 0;
			}
		}
		for(int j = 0; j < m; ++j){
			int flag = 0;
			for(int i = 0; i < n; ++i){
				if(g[i][j] == '*'){
					if(flag == 0) ++cc;
					col[i][j] = cc;
					flag = 1;
				}
				else if(g[i][j] == '#')
					flag = 0;
			}
		}
		Build_graph();
		printf("%d\n",Hungary());
	}
	return 0;
}



