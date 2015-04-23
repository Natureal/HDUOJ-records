////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-11 21:54:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5063
////Problem Title: 
////Run result: Accept
////Run time:328MS
////Run memory:684KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 1002.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sat 11 Oct 2014 07:35:42 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
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
const int mod = 1000000007;

int T,n,t,m,p,cnt,id;
int op[100005];
ll ans;

void Dfs(int o){
	if(op[o] == 1){
		if(p > t) p = (p - t) * 2;
		else p = 2 * p - 1;
	}
	else if(op[o] == 2){
		p = n + 1 - p;
	}
	else ++cnt;
	if(o > 1) Dfs(o - 1);
}

int main(){
	int a,pre;
	char s[5];
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		id = 0;
		t = (n + 1) / 2;
		for(int i = 1; i <= m; ++i){
			scanf("%s%d",s,&a);
			if(s[0] == 'Q'){
				p = a;
				cnt = 0;
				if(id == 0) printf("%d\n",a);
				else{
					Dfs(pre);
					ans = p;
					while(cnt--) ans = (ans * ans) % mod;
					printf("%I64d\n",ans);
				}
			}
			else{
				op[++id] = a;
				pre = id;
			}
		}
	}
	return 0;
}
