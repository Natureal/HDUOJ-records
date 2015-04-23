////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-04-18 21:53:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5206
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:1632KB
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
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const double eps = 1e-8;

int T;
double a[5],b[5],c[5];
double D[10];

double Dis(double a1,double b1,double c1,double a2,double b2,double c2){
	return (a1-a2)*(a1-a2) + (b1-b2)*(b1-b2) + (c1-c2)*(c1-c2);
}

int main(){
	scanf("%d",&T);
	FOR(tt,1,T){
		FOR(i,1,4) scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
		bool flag = false;
		for(int i = 1; i <= 4; ++i){
			for(int j = 1; j <= 4; ++j) if(i != j){
				double d1 = Dis(a[i],b[i],c[i],a[j],b[j],c[j]);
				int p1 = -1,p2 = -1;
				for(int k = 1; k <= 4; ++k) if(k != i && k != j){
					if(p1 == -1) p1 = k;
					else p2 = k;
				}
				double d2 = Dis(a[p1],b[p1],c[p1],a[p2],b[p2],c[p2]);
				if(fabs(d1 - d2) < eps){
					D[1] = Dis(a[i],b[i],c[i],a[p1],b[p1],c[p1]);
					D[2] = Dis(a[i],b[i],c[i],a[p2],b[p2],c[p2]);
					D[3] = Dis(a[j],b[j],c[j],a[p1],b[p1],c[p1]);
					D[4] = Dis(a[j],b[j],c[j],a[p2],b[p2],c[p2]);
					if(fabs(D[1] - D[2]) < eps && fabs(D[1] - D[3]) < eps
							&& fabs(D[1] - D[4]) < eps){
						if(fabs(d1 - D[1] * 2.0) < eps){
							flag = true;
							break;
						}
					}
				}
			}
			if(flag == true) break;
		}
		printf("Case #%d: ",tt);
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

