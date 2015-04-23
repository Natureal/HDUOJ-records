////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-04-04 21:18:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5198
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1624KB
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

char s[1000];
int vis[300];

int main(){
	while(scanf("%s",s) != EOF){
		MEM(vis,0);
		int len = strlen(s);
		bool flag = true;
		vis[s[0]] = 1;
		for(int i = 1; i < len; ++i){
			if(s[i] == s[i - 1]){
				vis[s[i]]++;
				continue;
			}
			if(vis[s[i]]){
				flag = false;
				break;
			}
			else vis[s[i]] = 1;
		}
		int cnt = 0;
		int num = 0;
		for(int i = 0; i < 300; ++i) if(vis[i]){
			if(cnt == 0) num = vis[i];
			cnt++;
			if(vis[i] != num){
				flag = false;
				break;
			}
		}
		if(flag && cnt == 3){
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}


