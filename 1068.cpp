////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-05 18:38:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1068
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:1280KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 1466.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Wed 05 Nov 2014 04:09:29 PM CST
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
const int maxn = 510;

int N;
int g[maxn][maxn];
int first[maxn],next[maxn * maxn],ver[maxn * maxn],ecnt;
int used[maxn],mat[maxn];

void Init(){
	memset(g,0,sizeof(g));
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
	for(int i = 0; i < N; ++i){
		memset(used,0,sizeof(used));
		if(find(i)) ++ans;
	}
	return ans;
}

int main(){
	int a,b,c;
	while(scanf("%d",&N) != EOF){
		Init();
		for(int i = 0; i < N; ++i){
			scanf("%d: (%d)",&a,&b);
			while(b--){
				scanf("%d",&c);
				Add_edge(a,c);
			}
		}
		printf("%d\n",N - Hungary() / 2);
	}
	return 0;
}
