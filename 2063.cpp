////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-05 19:52:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2063
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:268KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2063.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Wed 05 Nov 2014 06:41:44 PM CST
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

int k,m,n;
int first[maxn],next[maxn],ver[maxn],ecnt;
int used[maxn],mat[maxn];

void Init(){
	memset(first,-1,sizeof(first));
	ecnt = 0;
}

void Add_edge(int u,int v){
	next[++ecnt] = first[u];
	ver[ecnt] = v;
	first[u] = ecnt;
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
	for(int i = 1; i <= m; ++i){
		memset(used,0,sizeof(used));
		if(find(i)) ++ans;
	}
	return ans;
}

int main(){
	int a,b;
	while(scanf("%d",&k) != EOF && k){
		Init();
		scanf("%d%d",&m,&n);
		for(int i = 1; i <= k; ++i){
			scanf("%d%d",&a,&b);
			Add_edge(a,b);
		}
		printf("%d\n",Hungary());
	}
	return 0;
}

