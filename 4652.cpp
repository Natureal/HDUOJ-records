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
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;

int T;
int a,n,m;

int main(){
	scanf("%d",&T);
	FOR(tt,1,T){
		scanf("%d%d%d",&a,&m,&n);
		if(a == 0){
			int ans = 0;
			for(int i = 0,b = 1; i < n; ++i,b *= m) ans += b;
			printf("%d\n",ans);
		}
		else{
			double ans = 0,b = 1.0;
			for(int i = 0; i < n; ++i){
				ans += b;
				b = b * m / (m - i - 1);
			}
			printf("%.10f\n",ans);
		}
	}
	return 0;
}

