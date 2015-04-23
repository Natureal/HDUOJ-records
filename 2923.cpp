////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-11 22:45:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2923
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:324KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 2923.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Thu 11 Sep 2014 09:26:08 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 1 << 29;

int Case,N,C,R,cnt,p;
int arr[1005],dis[105][105];
map<string,int> mp;

void Floyd(){
	for(int k = 1; k <= p; ++k)
	for(int i = 1; i <= p; ++i)
	for(int j = 1; j <= p; ++j) if(dis[i][k] < INF && dis[k][j] < INF){
		dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	}
}

void Init(){
    mp.clear();
    cnt = p = 0;
	for(int i = 0; i < 105; ++i){
		for(int j = 0; j < 105; ++j) dis[i][j] = INF;
		dis[i][i] = 0;
	}
}

int main(){
	string name,name2,tmp;
	int a,b;
	while(scanf("%d%d%d",&N,&C,&R) != EOF){
		if(N == 0 && C == 0 && R == 0) break;
		Init();
		for(int i = 1; i <= C + 1; ++i){
			cin >> name;
			if(mp.find(name) == mp.end())
				mp[name] = ++p;
			arr[++cnt] = mp[name];
		}
		arr[++cnt] = 1;
		for(int i = 1; i <= R; ++i){
			cin >> name >> tmp >> name2;
			if(mp.find(name) == mp.end())
				mp[name] = ++p;
			a = mp[name];
			if(mp.find(name2) == mp.end())
				mp[name2] = ++p;
			b = mp[name2];
			int val = tmp[2] - '0',ind = 3;
			while(tmp[ind] >= '0' && tmp[ind] <= '9'){
				val = val * 10 + tmp[ind] - '0';
				ind++;
			}
			if(tmp[0] == '<') dis[b][a] = min(dis[b][a],val);
			if(tmp[tmp.size() - 1] == '>') dis[a][b] = min(dis[a][b],val);
		}
		Floyd();
		int ans = 0;
		for(int i = 2; i <= cnt; ++i){
			ans += dis[1][arr[i]] + dis[arr[i]][1];
		}
		printf("%d. %d\n",++Case,ans);
	}
	return 0;
}

