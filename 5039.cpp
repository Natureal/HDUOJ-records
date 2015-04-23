////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-03 02:22:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5039
////Problem Title: 
////Run result: Accept
////Run time:2906MS
////Run memory:17920KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 5039.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Thu 02 Oct 2014 10:50:41 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define lp (p << 1)
#define rp (p << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
typedef long long ll;
const int INF = 1 << 30;
const int maxn = 60010;

int T,N,M;
int sta[maxn],t1[maxn],t2[maxn],tot,stval[maxn];
int first[maxn],next[maxn],ver[maxn],ecnt;
map<string,int> mp;
string name,s1,s2;
pair<int,int> e[maxn];

struct node{
	int sum,cover;
}t[maxn << 2];

void Add(int u,int v,int x){
	next[++ecnt] = first[u];
	first[u] = ecnt;
	ver[ecnt] = v;
	sta[ecnt] = x;
}

void Dfs(int p,int pre,int val){
	t1[p] = ++tot;
	stval[tot] = val;
	for(int i = first[p]; i; i = next[i])
		if(ver[i] != pre) Dfs(ver[i],p,val ^ sta[i]);
	t2[p] = tot;
}

void Push_up(int p){
	t[p].sum = t[lp].sum + t[rp].sum;
}

void Build_tree(int p,int l,int r){
	t[p].cover = 0;
	if(l == r){
		t[p].sum = stval[l];
		return;
	}
	int mid = getmid(l,r);
	Build_tree(lp,l,mid);
	Build_tree(rp,mid + 1,r);
	Push_up(p);
}

void Push_down(int p,int l,int mid,int r){
	if(t[p].cover){
		t[lp].cover ^= 1;
		t[lp].sum = mid - l + 1 - t[lp].sum;
		t[rp].cover ^= 1;
		t[rp].sum = r - mid - t[rp].sum;
		t[p].cover = 0;
	}
}

void Update_tree(int a,int b,int p,int l,int r){
	if(a <= l && r <= b){
		t[p].cover ^= 1;
		t[p].sum = r - l + 1 - t[p].sum;
		return;
	}
	int mid = getmid(l,r);
	Push_down(p,l,mid,r);
	if(a <= mid) Update_tree(a,b,lp,l,mid);
	if(b > mid) Update_tree(a,b,rp,mid + 1,r);
	Push_up(p);
}

void Init(){
	memset(first,0,sizeof(first));
	ecnt = tot = 0;
}

int main(){
	ios::sync_with_stdio(false);
	char s[5];
	int x,id1,id2;
	cin >> T;
	for(int Case = 1; Case <= T; ++Case){
		Init();
		cin >> N;
		for(int i = 1; i <= N; ++i){
			cin >> name;
			mp[name] = i;
		}
		for(int i = 1; i < N; ++i){
			cin >> s1 >> s2 >> x;
			id1 = mp[s1];
			id2 = mp[s2];
			Add(id1,id2,x);
			Add(id2,id1,x);
			e[i] = make_pair(id1,id2);
		}
		Dfs(1,0,0);
		Build_tree(1,1,N);
		printf("Case #%d:\n",Case);
		cin >> M;
		for(int i = 1; i <= M; ++i){
			cin >> s;
			if(s[0] == 'Q'){
				int tmp = t[1].sum;
				printf("%d\n",tmp * (N - tmp) * 2);
			}
			else{
				cin >> x;
				int u = e[x].first;
				int v = e[x].second;
				if(t1[u] < t1[v]) u = v;
				Update_tree(t1[u],t2[u],1,1,N);
			}
		}
	}
	return 0;
}
