////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-06 22:47:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4786
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:1792KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 4786.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Thu 06 Nov 2014 08:00:18 PM CST
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
const int maxn = 100010;

int T,N,M,ans;
int fa[maxn];
int fib[30];
struct node{
	int u,v,c;
}e[maxn];

void Pre(){
	fib[0] = 1;
	fib[1] = 1;
	for(int i = 2; i <= 25; ++i)
		fib[i] = fib[i - 1] + fib[i - 2];
}

int Find(int x){
	return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

void Union(int a,int b){
	int x = Find(a);
	int y = Find(b);
	if(x != y)
		fa[y] = x;
}

void Kruskal(){
	for(int i = 1; i <= N; ++i)
		fa[i] = i;
	for(int i = 1; i <= M; ++i){
		int x = Find(e[i].u);
		int y = Find(e[i].v);
		if(x != y){
			fa[y] = x;
			if(e[i].c == 1)
				++ans;
		}
	}
}

bool cmp1(node a,node b){
	return a.c > b.c;
}

bool cmp2(node a,node b){
	return a.c < b.c;
}

int main(){
	Pre();
	int a,b,c;
	scanf("%d",&T);
	for(int Case = 1; Case <= T; ++Case){
		scanf("%d%d",&N,&M);
		printf("Case #%d: ",Case);
		for(int i = 1; i <= N; ++i)
			fa[i] = i;
		for(int i = 1; i <= M; ++i){
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
			Union(e[i].u,e[i].v);
		}
		if(M < N - 1){
			printf("No\n");
			continue;
		}
		int anc = Find(1),flag = 1;
		for(int i = 2; i <= N; ++i){
			if(Find(i) != anc){
				flag = 0;
				break;
			}
		}
		if(!flag){
			printf("No\n");
			continue;
		}
		int bot,top;
		sort(e + 1,e + M + 1,cmp1);
		ans = 0;
		Kruskal();
		top = ans;

		sort(e + 1,e + M + 1,cmp2);
		ans = 0;
		Kruskal();
		bot = ans;
		
		flag = 0;
		//printf("%d %d\n",bot,top);
		for(int i = 1; i <= 25; ++i){
			if(fib[i] >= bot && fib[i] <= top){
				flag = 1;
				break;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}


