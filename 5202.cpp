////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-04-11 21:14:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5202
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1612KB
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

int n;
char ts[1010],s[1010];
int flag;

bool Judge(){
	for(int i = 1; i <= n / 2; ++i){
		if(s[i] == '?' || s[n + 1 - i] == '?' || s[i] != s[n + 1 - i])
			return true;
	}
	return false;
}

int main(){
	while(~scanf("%d",&n)){
		scanf("%s",s + 1);
		if(Judge() == false){
			printf("QwQ\n");
			continue;
		}
		int f = 1;
		for(int i = 1; i <= n; ++i) if(s[i] == '?'){
			bool flag = false;
			for(int j = 0; j < 26; ++j){
				s[i] = 'a' + j;
				if(Judge()){
					flag = true;
					break;
				}
			}
			if(flag == false){
				f = 0;
				break;
			}
		}
		
		if(f == 0){
			printf("QwQ\n");
		}
		else printf("%s\n",s + 1);
	}
	return 0;
}
