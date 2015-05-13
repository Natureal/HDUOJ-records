
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

int N,M;
int num[20];
int res;

int Gcd(int a,int b){
	while(a > 0 && b > 0){
		if(a > b) a %= b;
		else b %= a;
	}
	return a + b;
}

int Lcm(int a,int b){
	return a / Gcd(a,b) * b;
}

void Dfs(int p,int v,int cnt){
	if(p > M){
		if(cnt == 0) return;
		if(cnt & 1) res += N / v;
		else res -= N / v;
		return;
	}	
	Dfs(p + 1,v,cnt);
	if(num[p]) Dfs(p + 1,Lcm(v,num[p]),cnt + 1);
}

int main(){
	while(scanf("%d%d",&N,&M) != EOF){
		N--;
		for(int i = 1; i <= M; ++i)
			scanf("%d",num + i);
		res = 0;
		Dfs(1,1,0);
		printf("%d\n",res);
	}
	return 0;
}

