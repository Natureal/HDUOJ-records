////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-02 19:43:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5098
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:380KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: i.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sun 02 Nov 2014 01:36:00 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <string>
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
const int INF = 1 << 30;
const int maxn = 1010;

int n,m,cnt;
int din[maxn],reb[maxn],dp[maxn];
int vis[maxn],first[maxn],next[maxn * maxn],ver[maxn * maxn],ecnt;
string s,id1,id2;
char name[1500];
map< string,int > mp;

void Add_edge(int u,int v){
    next[++ecnt] = first[u];
    ver[ecnt] = v;
    first[u] = ecnt;
}

void Init(){
    memset(reb,0,sizeof(reb));
    memset(din,0,sizeof(din));
    memset(first,-1,sizeof(first));
    ecnt = cnt = 0;
    mp.clear();
}

int Solve(int p){
	if(dp[p]) return dp[p];
	int ans = 0;
	for(int i = first[p]; i != -1; i = next[i]){
		int v = ver[i];
		ans = max(ans,Solve(v));
	}
	return dp[p] = ans + reb[p];
}

int DAG_max(){
	int ans = 0;
	for(int i = 1; i <= cnt; ++i) if(din[i] == 0){
		memset(dp,0,sizeof(dp));
		ans = max(ans,Solve(i));
	}
	return ans;
}

int main(){
    int a,b,len,flag;
    scanf("%d",&n);
    getchar();
    getchar();
    for(int Case = 1; Case <= n; ++Case){
        Init();
		while(getline(cin,s) != NULL){
             if(s[0] == '\0')
                 break;
             istringstream sin(s);
             sin >> name;
             flag = 0;
             int len = strlen(name);
             for(int i = 0; i < len; ++i)
                 if(name[i] == '*') flag = 1;
             name[len - 1 - flag] = '\0';
             id1 = name;
             if(mp.find(id1) == mp.end())
                mp[id1]= ++cnt;
             reb[mp[id1]] = flag;
             while(sin >> id2){
                 if(mp.find(id2) == mp.end())
                     mp[id2] = ++cnt;
                 Add_edge(mp[id2],mp[id1]);
                 din[mp[id1]]++;
             }
        }
       	printf("Case %d: %d\n",Case,DAG_max());
	}
    return 0;
}
