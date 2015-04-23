////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-23 20:16:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1237
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1100KB
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
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

double st1[205];
char st2[205];
int r1,r2;

int main(){
	double val;
	char s[205];
	while(gets(s)){
		if(s[0] == '0' && strlen(s) == 1) break;
		r1 = r2 = 0;
		int len = strlen(s);
		val = 0;
		FOR(i,0,len - 1) if(s[i] != ' '){
			if(s[i] >= '0' && s[i] <= '9')
				val = val * 10 + s[i] - '0';
			else{
				if(r2 > 0 && (st2[r2] == '*' || st2[r2] == '/')){
					double v1 = st1[r1--];
					if(st2[r2] == '*') st1[++r1] = v1 * val;
					else st1[++r1] = v1 / val;
					--r2;
				}
				else st1[++r1] = val;
				val = 0;
				st2[++r2] = s[i];
			}
		}
		if(r2 > 0 && (st2[r2] == '*' || st2[r2] == '/')){
			double v1 = st1[r1--];
			if(st2[r2] == '*') st1[++r1] = v1 * val;
			else st1[++r1] = v1 / val;
			--r2;
		}
		else st1[++r1] = val;
		double ans = st1[1];
		REP(i,r2){
			if(st2[i] == '+') ans += st1[i + 1];
			else ans -= st1[i + 1];
		}
		printf("%.2f\n",ans);
	}
	return 0;
}
