////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-03 22:53:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5154
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1200KB
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
#include <iostream>
#include <algorithm>
using namespace std;
#define lp (p << 1)
#define rp (p << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
#define MP(a,b) make_pair(a,b)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int maxn = 10010;

int n,m;
int g[110][110];

int main(){
    int a,b;
    while(scanf("%d%d",&n,&m) != EOF){
        memset(g,0,sizeof(g));
        for(int i = 1; i <= m; ++i){
            scanf("%d%d",&a,&b);
            g[a][b] = 1;
		}
		for(int k = 1; k <= n; ++k){
			for(int i = 1; i <= n; ++i){
				for(int j = 1; j <= n; ++j){
					g[i][j] |= (g[i][k] && g[k][j]);
				}
			}
		}
		int flag = 1;
		for(int i = 1; i <= n; ++i) if(g[i][i]){
			flag = 0;
			break;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
    }
    return 0;
}