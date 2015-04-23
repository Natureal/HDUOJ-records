////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-30 19:42:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3473
////Problem Title: 
////Run result: Accept
////Run time:750MS
////Run memory:32740KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 3473.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sun 28 Sep 2014 10:00:25 PM CST
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
ll ans,pnum;

struct node{
	int val[maxn];
	int num[maxn];
	ll sum[maxn];
}t[20];

void Build_ptree(int p,int l,int r){
	if(l == r) return;
	int mid = getmid(l,r);
	int isame = mid - l + 1;
	for(int i = l; i <= r; ++i)
		if(t[p].val[i] < sorted[mid]) --isame;
	int ls = l,rs = mid + 1;
	for(int i = l; i <= r; ++i){
		t[p].num[i] = (i == l ? 0 : t[p].num[i - 1]);
		t[p].sum[i] = (i == l ? 0 : t[p].sum[i - 1]);
		if(t[p].val[i] < sorted[mid]){
			t[p].num[i]++;
			t[p].sum[i] += t[p].val[i];
			t[p + 1].val[ls++] = t[p].val[i];
		}
		else if(t[p].val[i] > sorted[mid]){
			t[p + 1].val[rs++] = t[p].val[i];
		}
		else{
			if(isame){
				--isame;
				t[p].num[i]++;
				t[p].sum[i] += t[p].val[i];
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
	ll tsum;
	ln = t[p].num[b] - (a == l ? 0 : t[p].num[a - 1]);
	preln = (a == l ? 0 : t[p].num[a - 1]);
	tsum = t[p].sum[b] - (a == l ? 0 : t[p].sum[a - 1]);
	if(ln >= k){
		a = l + preln;
		b = l + preln + ln - 1;
		return Query_ptree(a,b,k,p + 1,l,mid);
	}
	else{
		prern = a - l - preln;
		rn = b - a + 1 - ln;
		a = mid + 1 + prern;
		b = mid + prern + rn;
		ans += tsum;
		pnum += ln;
		return Query_ptree(a,b,k - ln,p + 1,mid + 1,r);
	}
}

int main(){
	ll sum[maxn];
	int T,n,q,a,b;
	scanf("%d",&T);
	for(int Case = 1; Case <= T; ++Case){
		scanf("%d",&n);
		memset(t,0,sizeof(t));
		sum[0] = 0;
		for(int i = 1; i <= n; ++i){
			scanf("%d",&sorted[i]);
			t[1].val[i] = sorted[i];
			sum[i] = sum[i - 1] + sorted[i];
		}
		sort(sorted + 1,sorted + n + 1);
		Build_ptree(1,1,n);
		scanf("%d",&q);
		printf("Case #%d:\n",Case);
		while(q--){
			scanf("%d%d",&a,&b);
			++a;
			++b;
			ans = pnum = 0;
			int k = (b - a + 2) / 2;
			ll median = Query_ptree(a,b,k,1,1,n);
			//printf("ans : %d\n",ans);
			//printf("median : %d\n",median);
			//printf("pnum : %d\n",pnum);
			//printf("sumab : %d\n",sum[b] - sum[a - 1]);
			printf("%I64d\n",median * pnum - ans + sum[b] - sum[a - 1] - ans - (b - a + 1 - pnum) * median);
		}
		puts("");
	}
	return 0;
}
