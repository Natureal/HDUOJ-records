////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-28 21:47:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2665
////Problem Title: 
////Run result: Accept
////Run time:734MS
////Run memory:16292KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2665.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sun 28 Sep 2014 09:10:04 PM CST
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
#define lpos (pos << 1)
#define rpos (pos << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
typedef long long ll;
const int INF = 1 << 29;
const int maxn = 100010;

int sorted[maxn];

struct node{
	int val[maxn];
	int num[maxn];
}t[20];

void Build_ptree(int p,int l,int r){
	if(l == r) return;
	int mid = getmid(l,r);
	int isame = mid - l + 1;
	for(int i = l; i <= r; ++i)
		if(t[p].val[i] < sorted[mid])	--isame;
	int ls = l,rs = mid + 1;
	for(int i = l; i <= r; ++i){
		t[p].num[i] = (i == l ? 0 : t[p].num[i - 1]);
		if(t[p].val[i] < sorted[mid]){
			t[p].num[i]++;
			t[p + 1].val[ls++] = t[p].val[i];
		}
		else if(t[p].val[i] > sorted[mid]){
			t[p + 1].val[rs++] = t[p].val[i];
		}
		else{
			if(isame){
				--isame;
				t[p].num[i]++;
				t[p + 1].val[ls++] = t[p].val[i];
			}
			else t[p + 1].val[rs++] = t[p].val[i];
		}
	}
	Build_ptree(p + 1,l,mid);
	Build_ptree(p + 1,mid + 1,r);
}

int Query_ptree(int a,int b,int k,int p,int l,int r){
	if(l == r) return t[p].val[a];
	int mid = getmid(l,r);
	int ln,rn,preln,prern;
	ln = t[p].num[b] - (a == l ? 0 : t[p].num[a - 1]);
	preln = (a == l ? 0 : t[p].num[a - 1]);
	if(ln >= k){
		a = l + preln;
		b = l + preln + ln - 1;
		return Query_ptree(a,b,k,p + 1,l,mid);
	}
	else{
		prern = a - l - preln;
		rn = b - a + 1 - ln;
		a = mid + 1 + prern;
		b = mid + 1 + prern + rn - 1;
		return Query_ptree(a,b,k - ln,p + 1,mid + 1,r);
	}
}

//bool cmp(int a,int b){
//	return a < b;
//}

int main(){
	int T,n,m,a,b,k;
	scanf("%d",&T);
	while(T--){
		memset(t,0,sizeof(t));
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= n; ++i){
			scanf("%d",&sorted[i]);
			t[1].val[i] = sorted[i];
		}
		sort(sorted + 1,sorted + n + 1);
		Build_ptree(1,1,n);
		while(m--){
			scanf("%d%d%d",&a,&b,&k);
			printf("%d\n",Query_ptree(a,b,k,1,1,n));
		}
	}
	return 0;
}
