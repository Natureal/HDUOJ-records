////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-15 23:46:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3062
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:764KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 3062.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Wed 15 Oct 2014 11:22:36 PM CST
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
const int maxn = 2010;

int n,m,cnt;
int first[maxn],next[maxn * maxn],ver[maxn * maxn],ecnt;
int S[maxn];
bool mark[maxn];

void Init(){
	memset(first,-1,sizeof(first));
	memset(mark,false,sizeof(mark));
	ecnt = 0;
	cnt = 0;
}

void Add_edge(int u,int v){
	next[++ecnt] = first[u];
	ver[ecnt] = v;
	first[u] = ecnt;
}

bool Dfs(int p){
	if(mark[p ^ 1]) return false;
	if(mark[p]) return true;
	mark[p] = true; //标记真值
	S[cnt++] = p; //入队
	for(int i = first[p]; i != -1; i = next[i]){
		int v = ver[i];
		if(!Dfs(v)) return false;
	}
	return true;
}

bool Two_sat(){
	int top = 2 * n;
	for(int i = 0; i < top; i += 2){
		if(!mark[i] && !mark[i + 1]){
			if(!Dfs(i)){
				while(cnt > 0) mark[S[--cnt]] = false;
				if(!Dfs(i + 1)) return false;
			}
		}
	}
	return true;
}

int main(){
	int a1,a2,c1,c2;
	while(scanf("%d%d",&n,&m) != EOF){
		Init();
		for(int i = 0; i < m; ++i){
			scanf("%d%d%d%d",&a1,&a2,&c1,&c2);
			int u,v;
			u = a1 * 2 + c1;
			v = a2 * 2 + c2;
			Add_edge(u ^ 1,v);
			Add_edge(v ^ 1,u);
		}
		if(Two_sat()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
