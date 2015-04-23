////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-07-15 12:13:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1456
////Problem Title: 
////Run result: Accept
////Run time:531MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n,m,norder,tmax,pasn[1000];

struct order{
	int st,ed,num;
};
order o[1000];

void Dfs(int cur,int earn){
    if(cur >= norder){
        tmax = max(tmax,earn);
        return;
    }
	int flag = 1;
	for(int i = o[cur].st; i < o[cur].ed; ++i){
		if(pasn[i] + o[cur].num > n){
			flag = 0;
			break;
		}
	}
	if(flag){
		for(int i = o[cur].st; i < o[cur].ed; ++i)
            pasn[i] += o[cur].num;
		//printf("yes: %d\n",earn + o[cur].num * (o[cur].ed - o[cur].st));
		Dfs(cur + 1,earn + o[cur].num * (o[cur].ed - o[cur].st));
		for(int i = o[cur].st; i < o[cur].ed; ++i)
			pasn[i] -= o[cur].num;
	}
	//printf("no: %d\n",earn);
	Dfs(cur + 1,earn);
}

int main(){
	while(scanf("%d %d %d",&n,&m,&norder) == 3){
		if(!n && !m && !norder)
            break;
		memset(pasn,0,sizeof(pasn));
		memset(o,0,sizeof(o));
		for(int i = 0; i < norder; ++i){
			scanf("%d %d %d",&o[i].st,&o[i].ed,&o[i].num);
		}
		tmax = 0;
		Dfs(0,0);
		printf("%d\n",tmax);
	}
	return 0;
}
