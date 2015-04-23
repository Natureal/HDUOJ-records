////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-09 21:48:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4770
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1304KB
//////////////////System Comment End//////////////////
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

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=1;i<=(n);++i)
#define REV(i,n) for(int i=(n);i>=1;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int N,M,ii,ans,cnt;
int X[20],Y[20],mp1[205][205];
char g[205][205];
int dir1[4][2] = {{-1,0},{0,1},{0,-1},{0,-1}};
int dir2[4][2] = {{0,1},{1,0},{1,0},{-1,0}};

void Dfs(int p,int num){
        if(num >= ans) return;
        if(p > cnt){
                bool flag = true;
                for(int i = 1; i <= cnt; ++i) if(mp1[X[i]][Y[i]] == 0){
                        flag = false;
                        break;
                }
                if(flag) ans = min(ans,num);
                return;
        }
        if(p == ii){
                Dfs(p + 1,num);
        }
        else{
                Dfs(p + 1,num);
                int a1 = X[p] - 1;
                int b1 = Y[p];
                int a2 = X[p];
                int b2 = Y[p] + 1;
                if(g[a1][b1] == '#' || g[a2][b2] == '#') return;
                ++mp1[X[p]][Y[p]];
                ++mp1[a1][b1];
                ++mp1[a2][b2];
                Dfs(p + 1,num + 1);
                --mp1[X[p]][Y[p]];
                --mp1[a1][b1];
                --mp1[a2][b2];
        }
}

int main(){
	while(scanf("%d%d",&N,&M) != EOF){
		if(N == 0 && M == 0)
			break;
		cnt = 0;
		memset(g,0,sizeof(g));
		for(int i = 1; i <= N; ++i){
			scanf("%s",g[i] + 1);
        }
		for(int i = 1; i <= N; ++i)
			for(int j = 1; j <= M; ++j)
				if(g[i][j] == '.'){
                    ++cnt;
					X[cnt] = i;
					Y[cnt] = j;
				}
		if(cnt == 0){
			printf("0\n");
			continue;
		}
		int res = INF;
		// put one
		for(ii = 1; ii <= cnt; ++ii){ //special
			for(int k = 0; k < 4; ++k){ //type
				memset(mp1,0,sizeof(mp1));
				mp1[X[ii]][Y[ii]]++;
				int tx1 = X[ii] + dir1[k][0];
				int ty1 = Y[ii] + dir1[k][1];
				int tx2 = X[ii] + dir2[k][0];
				int ty2 = Y[ii] + dir2[k][1];
                if(g[tx1][ty1] == '#' || g[tx2][ty2] == '#') continue;
                mp1[tx1][ty1]++;
                mp1[tx2][ty2]++;
                ans = INF;
				Dfs(1,1);
                if(ans < INF) res = min(res,ans);
            }
        }
		if(res >= INF) printf("-1\n");
		else printf("%d\n",res);
	}
	return 0;
}