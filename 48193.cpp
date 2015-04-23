////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-06 09:54:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4819
////Problem Title: 
////Run result: Accept
////Run time:1185MS
////Run memory:36952KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 800;

int T,N,Q,X1,X2,Y1,Y2;
int g[MAXN + 10][MAXN + 10];

inline int Read(){
      int x = 0,f = 1;char ch = getchar();
      while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
      while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
      return x * f;
}

struct SMT_2{
	int tmax[810 << 2][810 << 2];
	int tmin[810 << 2][810 << 2];
	inline void Push_up(int xp,int p){
		tmax[xp][p] = max(tmax[xp][p << 1],tmax[xp][p << 1|1]);
		tmin[xp][p] = min(tmin[xp][p << 1],tmin[xp][p << 1|1]);
	}
	void Build_y(int xp,int x,int p,int l,int r){
		if(l == r){
			tmax[xp][p] = tmin[xp][p] = g[x][l];
			return;
		}
		int mid = getmid(l,r);
		Build_y(xp,x,p << 1,l,mid);
		Build_y(xp,x,p << 1|1,mid + 1,r);
		Push_up(xp,p);
	}
	void Build_y_2(int xp,int p,int l,int r){
		tmax[xp][p] = max(tmax[xp << 1][p],tmax[xp << 1|1][p]);
		tmin[xp][p] = min(tmin[xp << 1][p],tmin[xp << 1|1][p]);
		if(l == r)
			return;
		int mid = getmid(l,r);
		Build_y_2(xp,p << 1,l,mid);
		Build_y_2(xp,p << 1|1,mid + 1,r);
	}
	void Build_x(int p,int l,int r){
		if(l == r){
			Build_y(p,l,1,1,N);
			return;
		}
		int mid = getmid(l,r);
		Build_x(p << 1,l,mid);
		Build_x(p << 1|1,mid + 1,r);
		Build_y_2(p,1,1,N);
	}
	pii Query_y(int xp,int p,int l,int r){
		if(Y1 <= l && r <= Y2){
			return MP(tmax[xp][p],tmin[xp][p]);
		}
		int mid = getmid(l,r);
		pii t1(0,INF),t2(0,INF);
		if(Y1 <= mid) t1 = Query_y(xp,p << 1,l,mid);
		if(Y2 > mid) t2 = Query_y(xp,p << 1|1,mid + 1,r);
		return MP(max(t1.first,t2.first),min(t1.second,t2.second));
	}
	pii Query_x(int p,int l,int r){
		if(X1 <= l && r <= X2){
			return Query_y(p,1,1,N);
		}
		int mid = getmid(l,r);
		pii t1(0,INF),t2(0,INF);
		if(X1 <= mid) t1 = Query_x(p << 1,l,mid);
		if(X2 > mid) t2 = Query_x(p << 1|1,mid + 1,r);
		return MP(max(t1.first,t2.first),min(t1.second,t2.second));
	}
	void Update_y(int xp,int c,int p,int l,int r){
		if(l == r){
			tmax[xp][p] = tmin[xp][p] = c;
			return;
		}
		int mid = getmid(l,r);
		if(Y1 <= mid) Update_y(xp,c,p << 1,l,mid);
		else Update_y(xp,c,p << 1|1,mid + 1,r);
		Push_up(xp,p);

	}
	void Update_y_2(int xp,int p,int l,int r){
		tmax[xp][p] = max(tmax[xp << 1][p],tmax[xp << 1|1][p]);
		tmin[xp][p] = min(tmin[xp << 1][p],tmin[xp << 1|1][p]);
		if(l == r)
			return;
		int mid = getmid(l,r);
		if(Y1 <= mid) Update_y_2(xp,p << 1,l,mid);
		else Update_y_2(xp,p << 1|1,mid + 1,r);
		Push_up(xp,p);
	}
	void Update_x(int c,int p,int l,int r){
		if(l == r){
			Update_y(p,c,1,1,N);
			return;
		}
		int mid = getmid(l,r);
		if(X1 <= mid) Update_x(c,p << 1,l,mid);
		else Update_x(c,p << 1|1,mid + 1,r);
		Update_y_2(p,1,1,N);
	}
}smt;

int main(){
	int a,b,c;
	T = Read();
	FOR(tt,1,T){
		N = Read();
		FOR(i,1,N) FOR(j,1,N) g[i][j] = Read();
		smt.Build_x(1,1,N);
		printf("Case #%d:\n",tt);
		Q = Read();
		REP(i,Q){
			a = Read(),b = Read(),c = Read();
			c >>= 1;
			X1 = max(1,a - c);
			X2 = min(N,a + c);
			Y1 = max(1,b - c);
			Y2 = min(N,b + c);
			pii res = smt.Query_x(1,1,N);
			X1 = a;
			Y1 = b;
			int ans = (res.first + res.second) >> 1;
			smt.Update_x(ans,1,1,N);
			printf("%d\n",ans);
		}
	}
	return 0;
}
