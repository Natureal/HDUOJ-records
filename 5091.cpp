////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-02 17:38:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5091
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:2816KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: b.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sun 02 Nov 2014 12:04:21 PM CST
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
const int maxn = 20010;
const int Maxn = 80000;

int N,H,W;
struct node{
	int x,y;
}nd[maxn];

struct seg_tree{
	int tmax;
	int cover;
}t[(Maxn << 2) + 10];

bool cmp(node a,node b){
	return a.y < b.y;
}

void Init(){
	memset(t,0,sizeof(t));
}

void Push_down(int p){
	if(t[p].cover){
		t[lp].tmax += t[p].cover;
		t[rp].tmax += t[p].cover;
		t[lp].cover += t[p].cover;
		t[rp].cover += t[p].cover;
		t[p].cover = 0;
	}
}

void Update(int a,int b,int c,int p,int l,int r){
	if(a <= l && r <= b){
		t[p].tmax += c;
		t[p].cover += c;
		return;
	}
	Push_down(p);
	int mid = getmid(l,r);
	if(a <= mid) Update(a,b,c,lp,l,mid);
	if(b > mid) Update(a,b,c,rp,mid + 1,r);
	t[p].tmax = max(t[lp].tmax,t[rp].tmax);
}

int main(){
	while(scanf("%d",&N) != EOF){
		if(N < 0) break;
		scanf("%d%d",&W,&H);
		Init();
		for(int i = 1; i <= N; ++i){
			scanf("%d%d",&nd[i].x,&nd[i].y);
			nd[i].x += 20001;
		}
		sort(nd + 1,nd + N + 1,cmp);
		int pos = 1,ans = 0;
		for(int i = 1; i <= N; ++i){
			Update(nd[i].x,nd[i].x + W,1,1,1,Maxn);
			while(nd[i].y - nd[pos].y > H){
				Update(nd[pos].x,nd[pos].x + W,-1,1,1,Maxn);
				++pos;
			}
			ans = max(ans,t[1].tmax);
		}
		printf("%d\n",ans);
	}
	return 0;
}



