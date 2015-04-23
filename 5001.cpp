////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-13 17:56:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5001
////Problem Title: 
////Run result: Accept
////Run time:4890MS
////Run memory:6824KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: w.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sat 13 Sep 2014 01:01:03 PM CST
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
typedef long long ll;
const int INF = 1 << 29;

int T,n,m,d;
int cnt[55];
int first[55],next[5010],v[5010],ecnt;
double p[55];
int vis[55][10010];
double dp[55][10010];
int dep[55];

struct node{
	int tag,dep;
	node(int a,int b) : tag(a),dep(b) {}
	node() {}
};

void Init(){
	ecnt = 0;
	memset(first,0,sizeof(first));
	memset(cnt,0,sizeof(cnt));
}

int main(){
	int a,b;
	scanf("%d",&T);
 	while(T--){
		scanf("%d%d%d",&n,&m,&d);
		Init();
		m <<= 1;
		for(int i = 1; i <= m; ++i){
			scanf("%d%d",&a,&b);
			cnt[a]++;
			next[i] = first[a];
			first[a] = i;
			v[i] = b;
			++i;
			cnt[b]++;
			next[i] = first[b];
			first[b] = i;
			v[i] = a;
		}
		queue<node> q;
		for(int i = 1; i <= n; ++i){
			memset(dp,0,sizeof(dp));
			memset(vis,0,sizeof(vis));
			while(!q.empty()) q.pop();
			for(int j = 1; j <= n; ++j) if(i != j){
				dp[j][0] = 1.0 / n;
				vis[j][0] = 1;
				node k; k.tag = j; k.dep = 0;
				q.push(k);
			}
			while(!q.empty()){
				node x = q.front(); q.pop();
				if(x.dep >= d) break;
				for(int y = first[x.tag]; y; y = next[y]){
					if(v[y] == i) continue;
					dp[v[y]][x.dep + 1] += dp[x.tag][x.dep] / (1.0 * cnt[x.tag]);
					if(!vis[v[y]][x.dep + 1]){
						vis[v[y]][x.dep + 1] = 1;
						node ke; ke.tag = v[y]; ke.dep = x.dep + 1;
						q.push(ke);
					}
				}
            }
            double ans = 0.0;
            for(int j = 1; j <= n; ++j) if(j != i)
                ans += dp[j][d];
            printf("%.10lf\n",ans);
		}
	}
	return 0;
}
