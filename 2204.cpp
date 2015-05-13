#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;

ll ans,N,tmax[100];
int prime[100],pcnt,check[100];

void Pre(){
	for(int i = 2; i <= 60; ++i) if(!check[i]){
		prime[++pcnt] = i;
		for(int j = i + i; j <= 60; j += i) check[j] = 1;
	}
}

void Dfs(int p,int v,int cnt){
	if(p > pcnt){
		if(cnt == 0) return;
		if(cnt & 1) ans += tmax[v];
		else ans -= tmax[v];
		return;
	}
	if(v * prime[p] <= 60) Dfs(p + 1,v * prime[p],cnt + 1);
	Dfs(p + 1,v,cnt);
}

int main(){
	Pre();
	while(scanf("%lld",&N) != EOF){
		memset(tmax,0,sizeof(tmax));
		for(int i = 2; i <= 60; ++i){ //指数
			if(pow(2.0,1.0 * i) > N) break;
			tmax[i] = (ll)pow(1.0 * N,1.0 / i) - 1;
			//printf("tmax[%d] : %lld\n",i,tmax[i]);
		}
		ans = 0;
		Dfs(1,1,0);
		printf("%lld\n",ans + 1);
	}
	return 0;
}

